#include "chessscene.h"

ChessScene::ChessScene(QObject *parent) : QGraphicsScene(parent),
    is_start_(false), black_vec({}), red_vec({}), chess_board_(nullptr),
    chess_place_move_to_(nullptr), move_vec({}), selected_chess_(nullptr),
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
        if (color == "Red") {
            red_vec.push_back(ptr);
        } else if (color == "Black") {
            black_vec.push_back(ptr);
        }
        this->addItem(ptr.get());
    }
}

void ChessScene::selectValidPlace(Chess *c) {
    // get initial pos from rule
    move_vec = c->generateNextPlace();
    // based on playground, remove some illegal pos
    filterPlace(c);
    for(auto ptr : move_vec) {
        addItem(ptr.get());
    }
}

Chess* ChessScene::chessOnPlace(const Mesh &m) {
    QPointF p = m.getPointF()+QPointF(50, 50);
    auto item = itemAt(p, QTransform());
    return dynamic_cast<Chess*>(item);
}


void ChessScene::filterPlace(Chess *src) {
    Mesh cur = src->getMesh();
    if (move_vec.size() == 17) {
        // must be Cannon or Rook
        _filterCannonRook(src, cur);
    }
}


void ChessScene::_filterCannonRook(Chess *c, const Mesh& cur) {
    int leftx = 0;
    for(int i = cur.meshx()-1; i > 0; i--) {
        Chess *c = chessOnPlace(Mesh(i, cur.meshy()));
        if (c) {
            if (c->isRed() == is_red_move_)
                leftx = i;
            else
                leftx = i-1;
            break;
        }
    }
    int rightx = 8;
    for(int i = cur.meshx()+1; i < 10; i++) {
        Chess *c = chessOnPlace(Mesh(i, cur.meshy()));
        if (c) {
            if (c->isRed() == is_red_move_)
                rightx = i-2;
            else
                rightx = i-1;
            break;
        }
    }
    int topy = 0;
    for(int i = cur.meshy()-1; i > 0; i--) {
        Chess *c = chessOnPlace(Mesh(cur.meshx(), i));
        if (c) {
            if (c->isRed() == is_red_move_)
                topy = i;
            else
                topy = i-1;
            break;
        }
    }
    int boty = 9;
    for(int i = cur.meshy()+1; i < 11; i++) {
        Chess *c = chessOnPlace(Mesh(cur.meshx(), i));
        if (c) {
            if (c->isRed() == is_red_move_)
                boty = i-2;
            else
                boty = i-1;
            break;
        }
    }
    move_vec.remove(8+boty, 9-boty);
    move_vec.remove(8, topy);
    move_vec.remove(rightx, 8-rightx);
    move_vec.remove(0, leftx);
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

void ChessScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (is_start_) {
        if (event->button() == Qt::LeftButton) {
            // get the clicked item, cast as Chess if it is
            Mesh mpos(event->lastScenePos());
            Chess* c = chessOnPlace(mpos);
            // second click
            if (selected_chess_) {
                if (isValid(mpos)) {
                    unSelectValidPlace();
                    selected_chess_->move(mpos);
                    selected_chess_ = nullptr;
                    if (c)
                        c->dead();
                    is_red_move_ = !is_red_move_;
                }
                return ;
            }
            // first click
            if (c && !selected_chess_ && is_red_move_ == c->isRed()) {
                // display all valid place, and if check
                selected_chess_ = c;
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
