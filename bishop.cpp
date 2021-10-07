#include "bishop.h"

BlackBishop::BlackBishop(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackBishop::BlackBishop(int x, int y): Chess() {
    init(x, y);
}

BlackBishop::BlackBishop(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackBishop::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(100, 0, 50, 50));
    setPoint(QPoint(x, y));
}

BlackBishop::~BlackBishop() {

}

QString BlackBishop::classname() {
    return QString("BlackBishop");
}

int BlackBishop::getType() {
    return BLACKBISHOP;
}

QSharedPointer<ChessChain>
  BlackBishop::updateMovePlace(const ChessVecSptr& cb) {
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> d;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> me = cb[y-1][x-1];
    if (x+2 <= 9 && y+2 < 6 && !(d = cb[y][x])) {
        c = cb[y+1][x+1];
        updateChain(me, c, Mesh(x+2, y+2));
    }
    if (x+2 <= 9 && y-2 > 0 && !(d = cb[y-2][x])) {
        c = cb[y-3][x+1];
        updateChain(me, c, Mesh(x+2, y-2));
    }
    if (x-2 > 0 && y+2 < 6 && !(d = cb[y][x-2])) {
        c = cb[y+1][x-3];
        updateChain(me, c, Mesh(x-2, y+2));
    }
    if (x-2 > 0 && y-2 > 0 && !(d = cb[y-2][x-2])) {
        c = cb[y-3][x-3];
        updateChain(me, c, Mesh(x-2, y-2));
    }
    return chain_;
}

QJsonObject BlackBishop::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Bishop");
    obj.insert("Color", "Black");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}

/*
** *****            Red Bishop                 ***** **
*/

RedBishop::RedBishop(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedBishop::RedBishop(int x, int y): Chess() {
    init(x, y);
}

RedBishop::RedBishop(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedBishop::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(100, 50, 50, 50));
    setPoint(QPoint(x, y));
}

RedBishop::~RedBishop() {

}


QString RedBishop::classname() {
    return QString("RedBishop");
}

int RedBishop::getType() {
    return REDBISHOP;
}

QSharedPointer<ChessChain>
  RedBishop::updateMovePlace(const ChessVecSptr& cb) {
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> d;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> me = cb[y-1][x-1];
    if (x+2 <= 9 && y+2 < 11 && !(d = cb[y][x])) {
        c = cb[y+1][x+1];
        updateChain(me, c, Mesh(x+2, y+2));
    }
    if (x+2 <= 9 && y-2 > 5 && !(d = cb[y-2][x])) {
        c = cb[y-3][x+1];
        updateChain(me, c, Mesh(x+2, y-2));
    }
    if (x-2 > 0 && y+2 < 11 && !(d = cb[y][x-2])) {
        c = cb[y+1][x-3];
        updateChain(me, c, Mesh(x-2, y+2));
    }
    if (x-2 > 0 && y-2 > 0 && !(d = cb[y-2][x-2])) {
        c = cb[y-3][x-3];
        updateChain(me, c, Mesh(x-2, y-2));
    }
    return chain_;
}

QJsonObject RedBishop::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Bishop");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
