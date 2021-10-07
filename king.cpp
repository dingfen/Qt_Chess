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
}

BlackKing::~BlackKing() {

}

QString BlackKing::classname() {
    return QString("BlackKing");
}

int BlackKing::getType() {
    return BLACKKING;
}

QSharedPointer<ChessChain>
  BlackKing::updateMovePlace(const ChessVecSptr& cb) {
    QSharedPointer<Chess> c;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> me = cb[y-1][x-1];
    if (y+1 < 4) {
        c = cb[y][x-1];
        updateChain(me, c, Mesh(x, y+1));
    }
    if (x+1 < 7) {
        c = cb[y-1][x];
        updateChain(me, c, Mesh(x+1, y));
    }
    if (x-1 > 3) {
        c = cb[y-1][x-2];
        updateChain(me, c, Mesh(x-1, y));
    }
    if (y-1 > 0) {
        c = cb[y-2][x-1];
        updateChain(me, c, Mesh(x, y-1));
    }
    int i = y+1;
    while(i < 11 && !(c = cb[i-1][x-1])) {
        i++;
    }
    if (i < 11 && dynamic_cast<RedKing*>(c.get())) {
        updateChain(me, c, Mesh(x, i));
    }
    return chain_;
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
}

RedKing::~RedKing() {

}

QString RedKing::classname() {
    return QString("RedKing");
}

int RedKing::getType() {
    return REDKING;
}

QSharedPointer<ChessChain>
  RedKing::updateMovePlace(const ChessVecSptr& cb) {
    QSharedPointer<Chess> c;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> me = cb[y-1][x-1];
    if (y+1 < 11) {
        c = cb[y][x-1];
        updateChain(me, c, Mesh(x, y+1));
    }
    if (x+1 < 7) {
        c = cb[y-1][x];
        updateChain(me, c, Mesh(x+1, y));
    }
    if (x-1 > 3) {
        c = cb[y-1][x-2];
        updateChain(me, c, Mesh(x-1, y));
    }
    if (y-1 > 7) {
        c = cb[y-2][x-1];
        updateChain(me, c, Mesh(x, y-1));
    }
    int i = y-1;
    while(i > 0 && !(c = cb[i-1][x-1])) {
        i--;
    }
    if (i > 0 && dynamic_cast<BlackKing*>(c.get())) {
        updateChain(me, c, Mesh(x, i));
    }
    return chain_;
}

QJsonObject RedKing::toJson() {
    QJsonObject obj;
    obj.insert("Type", "King");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
