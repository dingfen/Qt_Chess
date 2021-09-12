#include "pawn.h"

BlackPawn::BlackPawn(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackPawn::BlackPawn(int x, int y): Chess() {
    init(x, y);
}

BlackPawn::BlackPawn(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackPawn::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(300, 0, 50, 50));
    setPoint(QPoint(x, y));
}

BlackPawn::~BlackPawn() {

}

QString BlackPawn::classname() {
    return QString("BlackPawn");
}

BlackPawn::PlaceVecSptr
    BlackPawn::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    PlaceVecSptr next_vec;
    QSharedPointer<Chess> c;
    QSharedPointer<ChessPlace> cp;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (y > 5) {
        if (y+1 < 11 && (!(c = cb[y][x-1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x, y+1), 1));
            next_vec.append(cp);
        }
        if (x+1 < 10 && (!(c = cb[y-1][x]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+1, y), 1));
            next_vec.append(cp);
        }
        if (x-1 > 0 && (!(c = cb[y-1][x-2]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-1, y), 1));
            next_vec.append(cp);
        }
    } else {
        if (y+1 < 11 && (!(c = cb[y][x-1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x, y+1), 1));
            next_vec.append(cp);
        }
    }
    return next_vec;
}

/*
** *****            Red Pawn                 ***** **
*/

RedPawn::RedPawn(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedPawn::RedPawn(int x, int y): Chess() {
    init(x, y);
}

RedPawn::RedPawn(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedPawn::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(300, 50, 50, 50));
    setPoint(QPoint(x, y));
}

RedPawn::~RedPawn() {

}

QString RedPawn::classname() {
    return QString("RedPawn");
}


RedPawn::PlaceVecSptr
    RedPawn::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    PlaceVecSptr next_vec;
    QSharedPointer<Chess> c;
    QSharedPointer<ChessPlace> cp;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (y < 6) {
        if (y-1 > 0 && (!(c = cb[y-2][x-1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x, y-1), 1));
            next_vec.append(cp);
        }
        if (x+1 < 10 && (!(c = cb[y-1][x]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x+1, y), 1));
            next_vec.append(cp);
        }
        if (x-1 > 0 && (!(c = cb[y-1][x-2]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x-1, y), 1));
            next_vec.append(cp);
        }
    } else {
        if (y-1 < 11 && (!(c = cb[y-2][x-1]) || c->isRed() != redmove)) {
            cp.reset(new ChessPlace(Mesh(x, y-1), 1));
            next_vec.append(cp);
        }
    }
    return next_vec;
}
