#include "chessscene.h"

ChessScene::ChessScene(QObject *parent) : QGraphicsScene(parent),
    is_start_(false), chess_place_point_to_(nullptr), selected_chess_(nullptr) {
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

void ChessScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (is_start_) {
        if (event->button() == Qt::LeftButton) {
            qDebug() << "Chess Scene here";
            auto item = itemAt(event->lastScenePos(), QTransform());
            Chess* c = dynamic_cast<Chess*>(item);
            if (selected_chess_) {
                // second click
//                bool succ = selected_chess_->isLegal();
                selected_chess_->move(Mesh(event->lastScenePos()));
                selected_chess_->unselected();
                selected_chess_ = nullptr;
                if (c) {
                    c->dead();
                }
                return ;
            }
            if (c && !selected_chess_) {
                // first click
                selected_chess_ = c;
                selected_chess_->selected();
            }
        } else if (event->button() == Qt::RightButton) {
            if (selected_chess_) {
                qDebug() << "canceled";
                selected_chess_->unselected();
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
        if (chess_place_point_to_) {
            this->removeItem(chess_place_point_to_.get());
        }
        chess_place_point_to_.reset(new ChessPlace(m, 0));
        this->addItem(chess_place_point_to_.get());
    }
    QGraphicsScene::mousePressEvent(event);
}
