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
}

BlackKnight::~BlackKnight() {

}

QString BlackKnight::classname() {
    return QString("BlackKnight");
}

BlackKnight::PlaceVecSptr
  BlackKnight::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    PlaceVecSptr next_vec;
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> d;
    QSharedPointer<ChessPlace> cp;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (y-1 > 0 && x-2 > 0) {
        if ((!(d = cb[y-1][x-2])) &&
              (!(c = cb[y-2][x-3]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-2, y-1), 1));
            next_vec.append(cp);
        }
    }
    if (y+1 < 11 && x-2 > 0) {
        if ((!(d = cb[y-1][x-2])) &&
              (!(c = cb[y][x-3]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-2, y+1), 1));
            next_vec.append(cp);
        }
    }

    if (y-1 > 0 && x+2 < 10) {
        if ((!(d = cb[y-1][x])) &&
              (!(c = cb[y-2][x+1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+2, y-1), 1));
            next_vec.append(cp);
        }
    }
    if (y+1 < 11 && x+2 < 10) {
        if ((!(d = cb[y-1][x])) &&
              (!(c = cb[y][x+1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+2, y+1), 1));
            next_vec.append(cp);
        }
    }

    if (y-2 > 0 && x+1 < 10) {
        if ((!(d = cb[y-2][x-1])) &&
              (!(c = cb[y-3][x]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+1, y-2), 1));
            next_vec.append(cp);
        }
    }
    if (y-2 > 0 && x-1 > 0) {
        if ((!(d = cb[y-2][x-1])) &&
              (!(c = cb[y-3][x-2]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-1, y-2), 1));
            next_vec.append(cp);
        }
    }

    if (y+2 < 11 && x+1 < 10) {
        if ((!(d = cb[y][x-1])) &&
              (!(c = cb[y+1][x]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+1, y+2), 1));
            next_vec.append(cp);
        }
    }
    if (y+2 < 11 && x-1 > 0) {
        if ((!(d = cb[y][x-1])) &&
              (!(c = cb[y+1][x-2]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-1, y+2), 1));
            next_vec.append(cp);
        }
    }
    return next_vec;
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
}

RedKnight::~RedKnight() {

}

QString RedKnight::classname() {
    return QString("RedKnight");
}

RedKnight::PlaceVecSptr
  RedKnight::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    PlaceVecSptr next_vec;
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> d;
    QSharedPointer<ChessPlace> cp;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (y-1 > 0 && x-2 > 0) {
        if ((!(d = cb[y-1][x-2])) &&
              (!(c = cb[y-2][x-3]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-2, y-1), 1));
            next_vec.append(cp);
        }
    }
    if (y+1 < 11 && x-2 > 0) {
        if ((!(d = cb[y-1][x-2])) &&
              (!(c = cb[y][x-3]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-2, y+1), 1));
            next_vec.append(cp);
        }
    }

    if (y-1 > 0 && x+2 < 10) {
        if ((!(d = cb[y-1][x])) &&
              (!(c = cb[y-2][x+1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+2, y-1), 1));
            next_vec.append(cp);
        }
    }
    if (y+1 < 11 && x+2 < 10) {
        if ((!(d = cb[y-1][x])) &&
              (!(c = cb[y][x+1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+2, y+1), 1));
            next_vec.append(cp);
        }
    }

    if (y-2 > 0 && x+1 < 10) {
        if ((!(d = cb[y-2][x-1])) &&
              (!(c = cb[y-3][x]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+1, y-2), 1));
            next_vec.append(cp);
        }
    }
    if (y-2 > 0 && x-1 > 0) {
        if ((!(d = cb[y-2][x-1])) &&
              (!(c = cb[y-3][x-2]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-1, y-2), 1));
            next_vec.append(cp);
        }
    }

    if (y+2 < 11 && x+1 < 10) {
        if ((!(d = cb[y][x-1])) &&
              (!(c = cb[y+1][x]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+1, y+2), 1));
            next_vec.append(cp);
        }
    }
    if (y+2 < 11 && x-1 > 0) {
        if ((!(d = cb[y][x-1])) &&
              (!(c = cb[y+1][x-2]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-1, y+2), 1));
            next_vec.append(cp);
        }
    }
    return next_vec;
}
