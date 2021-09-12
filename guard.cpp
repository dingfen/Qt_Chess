#include "guard.h"

BlackGuard::BlackGuard(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackGuard::BlackGuard(int x, int y): Chess() {
    init(x, y);
}

BlackGuard::BlackGuard(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackGuard::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(50, 0, 50, 50));
    setPoint(QPoint(x, y));
}

BlackGuard::~BlackGuard() {

}

QString BlackGuard::classname() {
    return QString("BlackGuard");
}

BlackGuard::PlaceVecSptr
    BlackGuard::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    PlaceVecSptr next_vec;
    QSharedPointer<Chess> c;
    QSharedPointer<ChessPlace> cp;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (x+1 <= 6 && y+1 <= 3) {
        if (!(c = cb[y][x]) || c->isRed() != redmove) {
            cp.reset(new ChessPlace(Mesh(x+1, y+1), 1));
            next_vec.append(cp);
        }
    }
    if (x+1 <= 6 && y-1 > 0) {
        if (!(c = cb[y-2][x]) || c->isRed() != redmove) {
            cp.reset(new ChessPlace(Mesh(x+1, y-1), 1));
            next_vec.append(cp);
        }
    }
    if (x-1 >= 4 && y+1 <= 3) {
        if (!(c = cb[y][x-2]) || c->isRed() != redmove) {
            cp.reset(new ChessPlace(Mesh(x-1, y+1), 1));
            next_vec.append(cp);
        }
    }
    if (x-1 >= 4 && y-1 > 0) {
        if (!(c = cb[y-2][x-2]) || c->isRed() != redmove) {
            cp.reset(new ChessPlace(Mesh(x-1, y-1), 1));
            next_vec.append(cp);
        }
    }
    return next_vec;
}


/*
** *****            Red Guard                 ***** **
*/

RedGuard::RedGuard(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedGuard::RedGuard(int x, int y): Chess() {
    init(x, y);
}

RedGuard::RedGuard(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedGuard::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(50, 50, 50, 50));
    setPoint(QPoint(x, y));
}

RedGuard::~RedGuard() {

}

QString RedGuard::classname() {
    return QString("RedGuard");
}

RedGuard::PlaceVecSptr
    RedGuard::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    PlaceVecSptr next_vec;
    QSharedPointer<Chess> c;
    QSharedPointer<ChessPlace> cp;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (x+1 <= 6 && y+1 <= 10) {
        if (!(c = cb[y][x]) || c->isRed() != redmove) {
            cp.reset(new ChessPlace(Mesh(x+1, y+1), 1));
            next_vec.append(cp);
        }
    }
    if (x+1 <= 6 && y-1 >= 8) {
        if (!(c = cb[y-2][x]) || c->isRed() != redmove) {
            cp.reset(new ChessPlace(Mesh(x+1, y-1), 1));
            next_vec.append(cp);
        }
    }
    if (x-1 >= 4 && y+1 <= 10) {
        if (!(c = cb[y][x-2]) || c->isRed() != redmove) {
            cp.reset(new ChessPlace(Mesh(x-1, y+1), 1));
            next_vec.append(cp);
        }
    }
    if (x-1 >= 4 && y-1 >= 8) {
        if (!(c = cb[y-2][x-2]) || c->isRed() != redmove) {
            cp.reset(new ChessPlace(Mesh(x-1, y-1), 1));
            next_vec.append(cp);
        }
    }
    return next_vec;
}
