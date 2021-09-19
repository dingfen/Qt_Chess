#include "king.h"

BlackKing::BlackKing(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackKing::BlackKing(int x, int y): Chess() {
    init(x, y);
}

BlackKing::BlackKing(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackKing::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(0, 0, 50, 50));
    setPoint(QPoint(x, y));
    chess_name_ = "黑将";
}

BlackKing::~BlackKing() {

}

QString BlackKing::classname() {
    return QString("BlackKing");
}

BlackKing::MeshVecSptr
  BlackKing::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    move_range_.clear();
    QSharedPointer<Chess> c;
//    QSharedPointer<ChessPlace> cp;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (y+1 < 4 && (!(c = cb[y][x-1]) || c->isRed() != redmove)) {
//        cp.reset(new ChessPlace(Mesh(x, y+1), 1));
        move_range_.append(Mesh(x, y+1));
    }
    if (x+1 < 7 && (!(c = cb[y-1][x]) || c->isRed() != redmove)) {
//        cp.reset(new ChessPlace(Mesh(x+1, y), 1));
        move_range_.append(Mesh(x+1, y));
    }
    if (x-1 > 3 && (!(c = cb[y-1][x-2]) || c->isRed() != redmove)) {
//        cp.reset(new ChessPlace(Mesh(x-1, y), 1));
        move_range_.append(Mesh(x-1, y));
    }
    if (y-1 > 0 && (!(c = cb[y-2][x-1]) || c->isRed() != redmove)) {
//        cp.reset(new ChessPlace(Mesh(x, y-1), 1));
        move_range_.append(Mesh(x, y-1));
    }
    int i = y+1;
    while(i < 11 && !(c = cb[i-1][x-1])) {
        i++;
    }
    if (i < 11 && dynamic_cast<RedKing*>(c.get())) {
//        cp.reset(new ChessPlace(Mesh(x, i), 1));
        move_range_.append(Mesh(x, i));
    }
    return move_range_;
}

QJsonObject BlackKing::toJson() {
    QJsonObject obj;
    obj.insert("Type", "King");
    obj.insert("Color", "Black");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}

/*
** *****            Red King                 ***** **
*/

RedKing::RedKing(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedKing::RedKing(int x, int y): Chess() {
    init(x, y);
}

RedKing::RedKing(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedKing::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(0, 50, 50, 50));
    setPoint(QPoint(x, y));
    chess_name_ = "红帅";
}

RedKing::~RedKing() {

}

QString RedKing::classname() {
    return QString("RedKing");
}

RedKing::MeshVecSptr
  RedKing::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    move_range_.clear();
    QSharedPointer<Chess> c;
//    QSharedPointer<ChessPlace> cp;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (y+1 < 11 && (!(c = cb[y][x-1]) || c->isRed() != redmove)) {
//        cp.reset(new ChessPlace(Mesh(x, y+1), 1));
        move_range_.append(Mesh(x, y+1));
    }
    if (x+1 < 7 && (!(c = cb[y-1][x]) || c->isRed() != redmove)) {
//        cp.reset(new ChessPlace(Mesh(x+1, y), 1));
        move_range_.append(Mesh(x+1, y));
    }
    if (x-1 > 3 && (!(c = cb[y-1][x-2]) || c->isRed() != redmove)) {
        move_range_.append(Mesh(x-1, y));
    }
    if (y-1 > 7 && (!(c = cb[y-2][x-1]) || c->isRed() != redmove)) {
        move_range_.append(Mesh(x, y-1));
    }
    int i = y-1;
    while(i > 0 && !(c = cb[i-1][x-1])) {
        i--;
    }
    if (i > 0 && dynamic_cast<BlackKing*>(c.get())) {
        move_range_.append(Mesh(x, i));
    }
    return move_range_;
}

QJsonObject RedKing::toJson() {
    QJsonObject obj;
    obj.insert("Type", "King");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
