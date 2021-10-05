#include "rook.h"

BlackRook::BlackRook(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackRook::BlackRook(int x, int y): Chess() {
    init(x, y);
}

BlackRook::BlackRook(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackRook::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(200, 0, 50, 50));
    setPoint(QPoint(x, y));
    if (cur_pos_.meshx() == 1)
        chess_name_ = "左黑车";
    else if (cur_pos_.meshx() == 9)
        chess_name_ = "右黑车";
    else
        chess_name_ = "黑车";
}

BlackRook::~BlackRook() {

}


QString BlackRook::classname() {
    return QString("BlackRook");
}

QString BlackRook::getType() {
    return QString("BlackRook");
}

QSharedPointer<ChessChain>
    BlackRook::updateMovePlace(const ChessVecSptr& cb) {
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> me = cb[y-1][x-1];
    int i = x-1;
    while (i > 0 && !(c = cb[y-1][i-1])) {
        updateChain(me, c, Mesh(i, y));
        i--;
    }
    if (c) {
        updateChain(me, c, Mesh(i, y));
        c.clear();
    }

    i = x+1;
    while (i < 10 && !(c = cb[y-1][i-1])) {
        updateChain(me, c, Mesh(i, y));
        i++;
    }
    if (c) {
        updateChain(me, c, Mesh(i, y));
        c.clear();
    }

    i = y-1;
    while (i > 0 && !(c = cb[i-1][x-1])) {
        updateChain(me, c, Mesh(x, i));
        i--;
    }
    if (c) {
        updateChain(me, c, Mesh(x, i));
        c.clear();
    }

    i = y+1;
    while (i < 11 && !(c = cb[i-1][x-1])) {
        updateChain(me, c, Mesh(x, i));
        i++;
    }
    if (c) {
        updateChain(me, c, Mesh(x, i));
    }
    return chain_;
}

QJsonObject BlackRook::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Rook");
    obj.insert("Color", "Black");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}

/*
** *****            Red Rook                 ***** **
*/

RedRook::RedRook(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedRook::RedRook(int x, int y): Chess() {
    init(x, y);
}

RedRook::RedRook(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedRook::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(200, 50, 50, 50));
    setPoint(QPoint(x, y));
    if (cur_pos_.meshx() == 1)
        chess_name_ = "左红车";
    else if (cur_pos_.meshx() == 9)
        chess_name_ = "右红车";
    else
        chess_name_ = "红车";
}

RedRook::~RedRook() {

}

QString RedRook::classname() {
    return QString("RedRook");
}

QString RedRook::getType() {
    return QString("RedRook");
}

QSharedPointer<ChessChain>
    RedRook::updateMovePlace(const ChessVecSptr& cb) {
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> me = cb[y-1][x-1];
    int i = x-1;
    while (i > 0 && !(c = cb[y-1][i-1])) {
        updateChain(me, c, Mesh(i, y));
        i--;
    }
    if (c) {
        updateChain(me, c, Mesh(i, y));
        c.clear();
    }

    i = x+1;
    while (i < 10 && !(c = cb[y-1][i-1])) {
        updateChain(me, c, Mesh(i, y));
        i++;
    }
    if (c) {
        updateChain(me, c, Mesh(i, y));
        c.clear();
    }

    i = y-1;
    while (i > 0 && !(c = cb[i-1][x-1])) {
        updateChain(me, c, Mesh(x, i));
        i--;
    }
    if (c) {
        updateChain(me, c, Mesh(x, i));
        c.clear();
    }

    i = y+1;
    while (i < 11 && !(c = cb[i-1][x-1])) {
        updateChain(me, c, Mesh(x, i));
        i++;
    }
    if (c) {
        updateChain(me, c, Mesh(x, i));
    }
    return chain_;
}


QJsonObject RedRook::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Rook");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
