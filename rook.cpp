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
}

BlackRook::~BlackRook() {

}


QString BlackRook::classname() {
    return QString("BlackRook");
}


BlackRook::MeshVecSptr
    BlackRook::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    move_range_.clear();
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> c;
    int i = x-1;
    while (i > 0 && !(c = cb[y-1][i-1])) {
//        cp.reset(new ChessPlace(Mesh(i, y), 1));
        move_range_.append(Mesh(i, y));
        i--;
    }
    if (c && c->isRed() != redmove) {
//        cp.reset(new ChessPlace(Mesh(i, y), 1));
        move_range_.append(Mesh(i, y));
    }
    c.clear();
    i = x+1;
    while (i < 10 && !(c = cb[y-1][i-1])) {
//        cp.reset(new ChessPlace(Mesh(i, y), 1));
        move_range_.append(Mesh(i, y));
        i++;
    }
    if (c && c->isRed() != redmove) {
//        cp.reset(new ChessPlace(Mesh(i, y), 1));
        move_range_.append(Mesh(i, y));
    }
    c.clear();
    i = y-1;
    while (i > 0 && !(c = cb[i-1][x-1])) {
        move_range_.append(Mesh(x, i));
        i--;
    }
    if (c && c->isRed() != redmove) {
        move_range_.append(Mesh(x, i));
    }
    c.clear();
    i = y+1;
    while (i < 11 && !(c = cb[i-1][x-1])) {
        move_range_.append(Mesh(x, i));
        i++;
    }
    if (c && c->isRed() != redmove) {
        move_range_.append(Mesh(x, i));
    }
    return move_range_;
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
}

RedRook::~RedRook() {

}

QString RedRook::classname() {
    return QString("RedRook");
}

RedRook::MeshVecSptr
    RedRook::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    move_range_.clear();
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> c;
    int i = x-1;
    while (i > 0 && (!(c = cb[y-1][i-1]))) {
        move_range_.append(Mesh(i, y));
        i--;
    }
    if (c && c->isRed() != redmove) {
        move_range_.append(Mesh(i, y));
    }
    c.clear();
    i = x+1;
    while (i < 10 && (!(c = cb[y-1][i-1]))) {
        move_range_.append(Mesh(i, y));
        i++;
    }
    if (c && c->isRed() != redmove) {
        move_range_.append(Mesh(i, y));
    }
    c.clear();
    i = y-1;
    while (i > 0 && (!(c = cb[i-1][x-1]))) {
        move_range_.append(Mesh(x, i));
        i--;
    }
    if (c && c->isRed() != redmove) {
//        cp.reset(new ChessPlace(Mesh(x, i), 1));
        move_range_.append(Mesh(x, i));
    }
    c.clear();
    i = y+1;
    while (i < 11 && (!(c = cb[i-1][x-1]))) {
//        cp.reset(new ChessPlace(Mesh(x, i), 1));
        move_range_.append(Mesh(x, i));
        i++;
    }
    if (c && c->isRed() != redmove) {
//        cp.reset(new ChessPlace(Mesh(x, i), 1));
        move_range_.append(Mesh(x, i));
    }
    return move_range_;
}


QJsonObject RedRook::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Rook");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
