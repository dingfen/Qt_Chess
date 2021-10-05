#include "knight.h"

BlackKnight::BlackKnight(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackKnight::BlackKnight(int x, int y): Chess() {
    init(x, y);
}

BlackKnight::BlackKnight(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackKnight::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(150, 0, 50, 50));
    setPoint(QPoint(x, y));
    if (cur_pos_.meshx() == 2)
        chess_name_ = "左黑马";
    else if (cur_pos_.meshx() == 8)
        chess_name_ = "右黑马";
    else
        chess_name_ = "黑马";
}

BlackKnight::~BlackKnight() {

}

QString BlackKnight::classname() {
    return QString("BlackKnight");
}

QString BlackKnight::getType() {
    return QString("BlackKnight");
}

QSharedPointer<ChessChain>
  BlackKnight::updateMovePlace(const ChessVecSptr& cb) {
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> d;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> me = cb[y-1][x-1];
    if (y-1 > 0 && x-2 > 0 && !(d = cb[y-1][x-2])) {
        c = cb[y-2][x-3];
        updateChain(me, c, Mesh(x-2, y-1));
    }
    if (y+1 < 11 && x-2 > 0 && !(d = cb[y-1][x-2])) {
        c = cb[y][x-3];
        updateChain(me, c, Mesh(x-2, y+1));
    }
    if (y-1 > 0 && x+2 < 10 && !(d = cb[y-1][x])) {
        c = cb[y-2][x+1];
        updateChain(me, c, Mesh(x+2, y-1));
    }
    if (y+1 < 11 && x+2 < 10 && !(d = cb[y-1][x])) {
        c = cb[y][x+1];
        updateChain(me, c, Mesh(x+2, y+1));
    }
    if (y-2 > 0 && x+1 < 10 && !(d = cb[y-2][x-1])) {
        c = cb[y-3][x];
        updateChain(me, c, Mesh(x+1, y-2));
    }
    if (y-2 > 0 && x-1 > 0 && !(d = cb[y-2][x-1])) {
        c = cb[y-3][x-2];
        updateChain(me, c, Mesh(x-1, y-2));
    }
    if (y+2 < 11 && x+1 < 10 && !(d = cb[y][x-1])) {
        c = cb[y+1][x];
        updateChain(me, c, Mesh(x+1, y+2));
    }
    if (y+2 < 11 && x-1 > 0 && !(d = cb[y][x-1])) {
        c = cb[y+1][x-2];
        updateChain(me, c, Mesh(x-1, y+2));
    }
    return chain_;
}

QJsonObject BlackKnight::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Knight");
    obj.insert("Color", "Black");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}

/*
** *****            Red Horse                 ***** **
*/

RedKnight::RedKnight(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedKnight::RedKnight(int x, int y): Chess() {
    init(x, y);
}

RedKnight::RedKnight(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedKnight::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(150, 50, 50, 50));
    setPoint(QPoint(x, y));
    if (cur_pos_.meshx() == 2)
        chess_name_ = "左红马";
    else if (cur_pos_.meshx() == 8)
        chess_name_ = "右红马";
    else
        chess_name_ = "红马";
}

RedKnight::~RedKnight() {

}

QString RedKnight::classname() {
    return QString("RedKnight");
}

QString RedKnight::getType() {
    return QString("RedKnight");
}

QSharedPointer<ChessChain>
  RedKnight::updateMovePlace(const ChessVecSptr& cb) {
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> d;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> me = cb[y-1][x-1];
    if (y-1 > 0 && x-2 > 0 && !(d = cb[y-1][x-2])) {
        c = cb[y-2][x-3];
        updateChain(me, c, Mesh(x-2, y-1));
    }
    if (y+1 < 11 && x-2 > 0 && !(d = cb[y-1][x-2])) {
        c = cb[y][x-3];
        updateChain(me, c, Mesh(x-2, y+1));
    }
    if (y-1 > 0 && x+2 < 10 && !(d = cb[y-1][x])) {
        c = cb[y-2][x+1];
        updateChain(me, c, Mesh(x+2, y-1));
    }
    if (y+1 < 11 && x+2 < 10 && !(d = cb[y-1][x])) {
        c = cb[y][x+1];
        updateChain(me, c, Mesh(x+2, y+1));
    }
    if (y-2 > 0 && x+1 < 10 && !(d = cb[y-2][x-1])) {
        c = cb[y-3][x];
        updateChain(me, c, Mesh(x+1, y-2));
    }
    if (y-2 > 0 && x-1 > 0 && !(d = cb[y-2][x-1])) {
        c = cb[y-3][x-2];
        updateChain(me, c, Mesh(x-1, y-2));
    }
    if (y+2 < 11 && x+1 < 10 && !(d = cb[y][x-1])) {
        c = cb[y+1][x];
        updateChain(me, c, Mesh(x+1, y+2));
    }
    if (y+2 < 11 && x-1 > 0 && !(d = cb[y][x-1])) {
        c = cb[y+1][x-2];
        updateChain(me, c, Mesh(x-1, y+2));
    }
    return chain_;
}

QJsonObject RedKnight::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Knight");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
