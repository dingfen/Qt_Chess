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


BlackRook::PlaceVecSptr
    BlackRook::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    PlaceVecSptr next_vec;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> c;
    QSharedPointer<ChessPlace> cp;
    int i = x-1;
    while (i > 0 && !(c = cb[y-1][i-1])) {
        cp.reset(new ChessPlace(Mesh(i, y), 1));
        next_vec.append(cp);
        i--;
    }
    if (c && c->isRed() != redmove) {
        cp.reset(new ChessPlace(Mesh(i, y), 1));
        next_vec.append(cp);
    }
    c.clear();
    i = x+1;
    while (i < 10 && !(c = cb[y-1][i-1])) {
        cp.reset(new ChessPlace(Mesh(i, y), 1));
        next_vec.append(cp);
        i++;
    }
    if (c && c->isRed() != redmove) {
        cp.reset(new ChessPlace(Mesh(i, y), 1));
        next_vec.append(cp);
    }
    c.clear();
    i = y-1;
    while (i > 0 && !(c = cb[i-1][x-1])) {
        cp.reset(new ChessPlace(Mesh(x, i), 1));
        next_vec.append(cp);
        i--;
    }
    if (c && c->isRed() != redmove) {
        cp.reset(new ChessPlace(Mesh(x, i), 1));
        next_vec.append(cp);
    }
    c.clear();
    i = y+1;
    while (i < 11 && !(c = cb[i-1][x-1])) {
        cp.reset(new ChessPlace(Mesh(x, i), 1));
        next_vec.append(cp);
        i++;
    }
    if (c && c->isRed() != redmove) {
        cp.reset(new ChessPlace(Mesh(x, i), 1));
        next_vec.append(cp);
    }
    return next_vec;
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

RedRook::PlaceVecSptr
    RedRook::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    PlaceVecSptr next_vec;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> c;
    QSharedPointer<ChessPlace> cp;
    int i = x-1;
    while (i > 0 && (!(c = cb[y-1][i-1]))) {
        cp.reset(new ChessPlace(Mesh(i, y), 1));
        next_vec.append(cp);
        i--;
    }
    if (c && c->isRed() != redmove) {
        cp.reset(new ChessPlace(Mesh(i, y), 1));
        next_vec.append(cp);
    }
    c.clear();
    i = x+1;
    while (i < 10 && (!(c = cb[y-1][i-1]))) {
        cp.reset(new ChessPlace(Mesh(i, y), 1));
        next_vec.append(cp);
        i++;
    }
    if (c && c->isRed() != redmove) {
        cp.reset(new ChessPlace(Mesh(i, y), 1));
        next_vec.append(cp);
    }
    c.clear();
    i = y-1;
    while (i > 0 && (!(c = cb[i-1][x-1]))) {
        cp.reset(new ChessPlace(Mesh(x, i), 1));
        next_vec.append(cp);
        i--;
    }
    if (c && c->isRed() != redmove) {
        cp.reset(new ChessPlace(Mesh(x, i), 1));
        next_vec.append(cp);
    }
    c.clear();
    i = y+1;
    while (i < 11 && (!(c = cb[i-1][x-1]))) {
        cp.reset(new ChessPlace(Mesh(x, i), 1));
        next_vec.append(cp);
        i++;
    }
    if (c && c->isRed() != redmove) {
        cp.reset(new ChessPlace(Mesh(x, i), 1));
        next_vec.append(cp);
    }
    return next_vec;
}
