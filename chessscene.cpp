#include "chessscene.h"

ChessScene::ChessScene(QObject *parent) : QGraphicsScene(parent),
    is_start_(false), chess_vec(10, QVector<QSharedPointer<Chess>>(9)),
    chess_board_(nullptr), chess_place_move_to_(nullptr), move_vec({}), selected_chess_(nullptr),
    is_red_check_(false), is_black_check_(false), is_red_move_(true) {
    // no index just search all item in scene
    // apply to move add remove freq case
    this->setItemIndexMethod(QGraphicsScene::NoIndex);
    chess_board_.reset(new ChessBoard(*ResourceManager::get().chessBoardPixmap()));
    this->addItem(chess_board_.get());
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
    registerClass();
    this->putAllChess(path);
}

void ChessScene::putAllChess(const QString& path) {
    qDebug() << "Loading " << path << " ...";
    JsonParser jp(path);
    jp.parseJson();
    QJsonObject obj;

    while (jp.get(&obj)) {
        QString color = obj.value("Color").toString();
        QString classname = color + obj.value("Type").toString();
        int x = obj.value("X").toInt();
        int y = obj.value("Y").toInt();

        QSharedPointer<Chess> ptr(ChessFactory::createObject(classname, Mesh(x, y)));
        chess_vec[y-1][x-1] = ptr;
        this->addItem(ptr.get());
    }
}

void ChessScene::selectValidPlace(Chess *c) {
    move_vec = c->generateNextPlace(chess_vec, is_red_move_);
    for(auto ptr : move_vec) {
        addItem(ptr.get());
    }
}

Chess* ChessScene::chessOn(const Mesh &m) {
    QPointF p = m.getPointF()+QPointF(50, 50);
    auto item = itemAt(p, QTransform());
    return dynamic_cast<Chess*>(item);
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
        if (mesh == ptr->getMesh())
            return true;
    }
    return false;
}

void ChessScene::move(const Mesh& m) {
    Mesh pos = selected_chess_->getMesh();
    selected_chess_->animate(m);
    chess_vec[m.meshy()-1][m.meshx()-1].swap(selected_chess_);
    chess_vec[pos.meshy()-1][pos.meshx()-1].clear();
    selected_chess_.clear();
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
                    is_red_move_ = !is_red_move_;
                }
                return ;
            }
            // first click
            Chess* c = chessOn(mpos);
            if (c && !selected_chess_ && is_red_move_ == c->isRed()) {
                // display all valid place, and if check
                selected_chess_ = chess_vec[mpos.meshy()-1][mpos.meshx()-1];
                selectValidPlace(c);
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
