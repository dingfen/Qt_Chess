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

BlackBishop::PlaceVecSptr
  BlackBishop::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    PlaceVecSptr next_vec;
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> d;
    QSharedPointer<ChessPlace> cp;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (x+2 <= 9 && y+2 < 6) {
        if (!(d = cb[y][x]) &&
             (!(c = cb[y+1][x+1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+2, y+2), 1));
            next_vec.append(cp);
        }
    }
    if (x+2 <= 9 && y-2 > 0) {
        if (!(d = cb[y-2][x]) &&
             (!(c = cb[y-3][x+1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+2, y-2), 1));
            next_vec.append(cp);
        }
    }
    if (x-2 > 0 && y+2 < 6) {
        if (!(d = cb[y][x-2]) &&
             (!(c = cb[y+1][x-3]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-2, y+2), 1));
            next_vec.append(cp);
        }
    }
    if (x-2 > 0 && y-2 > 0) {
        if (!(d = cb[y-2][x-2]) &&
             (!(c = cb[y-3][x-3]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-2, y-2), 1));
            next_vec.append(cp);
        }
    }
    return next_vec;
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

RedBishop::PlaceVecSptr
  RedBishop::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    PlaceVecSptr next_vec;
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> d;
    QSharedPointer<ChessPlace> cp;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (x+2 <= 9 && y+2 < 11) {
        if (!(d = cb[y][x]) &&
             (!(c = cb[y+1][x+1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+2, y+2), 1));
            next_vec.append(cp);
        }
    }
    if (x+2 <= 9 && y-2 > 5) {
        if (!(d = cb[y-2][x]) &&
             (!(c = cb[y-3][x+1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+2, y-2), 1));
            next_vec.append(cp);
        }
    }
    if (x-2 > 0 && y+2 < 11) {
        if (!(d = cb[y][x-2]) &&
             (!(c = cb[y+1][x-3]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-2, y+2), 1));
            next_vec.append(cp);
        }
    }
    if (x-2 > 0 && y-2 > 5) {
        if (!(d = cb[y-2][x-2]) &&
             (!(c = cb[y-3][x-3]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-2, y-2), 1));
            next_vec.append(cp);
        }
    }
    return next_vec;
}
