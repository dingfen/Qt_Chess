#include "chessscene.h"

ChessScene::ChessScene(QObject *parent) : QGraphicsScene(parent),
    is_start_(false), is_red_check_(false), is_black_check_(false), is_red_move_(true),
    is_regret_(false), chess_vec(10, QVector<QSharedPointer<Chess>>(9)), chess_board_(nullptr),
    chess_place_move_to_(nullptr), move_vec({}), selected_chess_(nullptr) {
    // no index just search all item in scene
    // apply to move add remove freq case
    this->setItemIndexMethod(QGraphicsScene::NoIndex);
    // new a chess board
    chess_board_.reset(new ChessBoard(*ResourceManager::get().chessBoardPixmap()));
    this->addItem(chess_board_.get());
    // new recorder
    recorder_.reset(new Recorder);
    // register for factory
    registerClass();
}

ChessScene::~ChessScene() {

}

void ChessScene::registerClass() {
    ChessFactory::registerClass<BlackBishop>();
    ChessFactory::registerClass<BlackCannon>();
    ChessFactory::registerClass<BlackGuard>();
    ChessFactory::registerClass<BlackKing>();
    ChessFactory::registerClass<BlackKnight>();
    ChessFactory::registerClass<BlackPawn>();
    ChessFactory::registerClass<BlackRook>();

    ChessFactory::registerClass<RedBishop>();
    ChessFactory::registerClass<RedCannon>();
    ChessFactory::registerClass<RedGuard>();
    ChessFactory::registerClass<RedKing>();
    ChessFactory::registerClass<RedKnight>();
    ChessFactory::registerClass<RedPawn>();
    ChessFactory::registerClass<RedRook>();
}

void ChessScene::startGame(const QString &path) {
    is_start_ = true;
    this->putAllChess(path);
    updateAttackRegion();
    recorder_->write("Load Completed!");
}

void ChessScene::saveGame(const QString &path) {
    JsonParser jp(path);
    QVector<QJsonObject> obj_vec;
    for(auto &row : chess_vec) {
        for(auto &chess : row) {
            if (chess) {
                QJsonObject obj = chess->toJson();
                obj_vec.append(obj);
            }
        }
    }
    jp.writeJson(obj_vec);
}


void ChessScene::putAllChess(const QString& path) {
    JsonParser jp;
    jp.openAndRead(path);
    jp.parseJson();
    recorder_->write("Load " + path + " ...");
    QJsonObject obj;
    while (jp.get(&obj)) {
        QString color = obj.value("Color").toString();
        QString classname = color + obj.value("Type").toString();
        int x = obj.value("X").toInt();
        int y = obj.value("Y").toInt();

        QSharedPointer<Chess> ptr(ChessFactory::createObject(classname, Mesh(x, y)));
        if (classname == "BlackKing") {
            black_king_ = ptr;
        } else if (classname == "RedKing") {
            red_king_ = ptr;
        }
        chess_vec[y-1][x-1] = ptr;
        this->addItem(ptr.get());
    }
}

void ChessScene::clear() {
    selected_chess_.reset();
    for(auto& row : chess_vec) {
        for(auto& ptr : row) {
            if (ptr) {
                removeItem(ptr.get());
                ptr.reset();
            }
        }
    }
    move_vec.clear();
    recorder_->clear();
    is_red_check_ = false;
    is_black_check_ = false;
    is_red_move_ = true;
    is_start_ = false;
}

void ChessScene::selectValidPlace() {
    auto mesh_vec = selected_chess_->attackRegion();
    QSharedPointer<ChessPlace> cp;
    for(auto mesh : mesh_vec) {
        cp.reset(new ChessPlace(mesh, 1));
        addItem(cp.get());
        move_vec.append(cp);
    }
}

void ChessScene::unSelectValidPlace() {
    for(auto ptr : move_vec) {
        removeItem(ptr.get());
    }
    move_vec.clear();
}

/* whether click at valid place
 * valid: Move and kill
 * invalid: keep
 */
bool ChessScene::isValid(const Mesh& mesh) {
    for(auto ptr : move_vec) {
        if (mesh == ptr->getMesh()) {
            return true;
        }
    }
    return false;
}

void ChessScene::updateAttackRegion() {
    for(auto &row : chess_vec)
        for(auto &chess : row) {
            if (chess)
                chess->generateNextPlace(chess_vec);
        }
}

bool ChessScene::isCheck() {
    QSharedPointer<Chess> king = is_red_move_ ? red_king_ : black_king_;
    for(auto &row : chess_vec) {
        for(auto &c : row) {
            if (c && c->isRed() != is_red_move_) {
                auto region = c->attackRegion();
                auto kingpos = king->getMesh();
                for(auto m : region) {
                    if (kingpos == m) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


void ChessScene::backOneStep() {
    Recorder::Round r = recorder_->regret();
    r.move_->animate(r.from_);
    chess_vec[r.from_.meshy()-1][r.from_.meshx()-1].swap(
        chess_vec[r.to_.meshy()-1][r.to_.meshx()-1]);
    if (r.eaten_) {
        chess_vec[r.to_.meshy()-1][r.to_.meshx()-1] = r.eaten_;
        addItem(chess_vec[r.to_.meshy()-1][r.to_.meshx()-1].get());
    }
}


void ChessScene::stillCheck() {
    qDebug() << "Check!";
    backOneStep();
    updateAttackRegion();
}

void ChessScene::regret() {
    if (is_start_ && !is_regret_) {
        backOneStep();
        backOneStep();
        updateAttackRegion();
        is_regret_ = true;
    }
}

void ChessScene::move(const Mesh& m) {
    Mesh pos = selected_chess_->getMesh();
    selected_chess_->animate(m);
    recorder_->record(chess_vec, pos, m, is_red_move_);
    chess_vec[m.meshy()-1][m.meshx()-1].swap(selected_chess_);
    chess_vec[pos.meshy()-1][pos.meshx()-1].clear();
    if (selected_chess_) {
        removeItem(selected_chess_.get());
        selected_chess_.clear();
    }
}

void ChessScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (is_start_) {
        if (event->button() == Qt::LeftButton) {
            // get the clicked item, cast as Chess if it is
            Mesh mpos(event->lastScenePos());
            // second click
            if (selected_chess_) {
                if (isValid(mpos)) {
                    unSelectValidPlace();
                    move(mpos);
                    updateAttackRegion();
                    if (isCheck()) {
                        stillCheck();
                        return;
                    }
                    is_red_move_ = !is_red_move_;
                    is_regret_ = false;
                    emit nextRound(is_red_move_);
                }
                return ;
            }
            // first click
            auto c = chess_vec[mpos.meshy()-1][mpos.meshx()-1];
            if (c && !selected_chess_ && is_red_move_ == c->isRed()) {
                // display all valid place, and if check
                selected_chess_ = chess_vec[mpos.meshy()-1][mpos.meshx()-1];
                selectValidPlace();
            }
        } else if (event->button() == Qt::RightButton) {
            if (selected_chess_) {
                unSelectValidPlace();
                selected_chess_ = nullptr;
            }
        }
    }
    QGraphicsScene::mousePressEvent(event);
}


void ChessScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (is_start_) {
        QPointF p = event->lastScenePos();
        Mesh m(p);
        if (chess_place_move_to_) {
            this->removeItem(chess_place_move_to_.get());
        }
        chess_place_move_to_.reset(new ChessPlace(m, 0));
        this->addItem(chess_place_move_to_.get());
    }
    QGraphicsScene::mousePressEvent(event);
}
