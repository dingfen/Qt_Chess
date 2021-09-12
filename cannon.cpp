#include "cannon.h"

BlackCannon::BlackCannon(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackCannon::BlackCannon(int x, int y): Chess() {
    init(x, y);
}

BlackCannon::BlackCannon(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackCannon::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(250, 0, 50, 50));
    setPoint(QPoint(x, y));
}

BlackCannon::~BlackCannon() {

}

QString BlackCannon::classname() {
    return QString("BlackCannon");
}

BlackCannon::PlaceVecSptr
  BlackCannon::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
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
    do {
        i--;
    }while (i > 0 && !(c = cb[y-1][i-1]));
    if(i > 0 && c && c->isRed() != redmove) {
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
    do {
        i++;
    }while (i < 10 && !(c = cb[y-1][i-1]));
    if(i < 10 && c && c->isRed() != redmove) {
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
    do {
        i--;
    }while (i > 0 && !(c = cb[i-1][x-1]));
    if(i > 0 && c && c->isRed() != redmove) {
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
    do {
        i++;
    }while (i < 11 && !(c = cb[i-1][x-1]));
    if(i < 11 && c && c->isRed() != redmove) {
        cp.reset(new ChessPlace(Mesh(x, i), 1));
        next_vec.append(cp);
    }
    return next_vec;
}

/*
** *****            Red Cannon                 ***** **
*/

RedCannon::RedCannon(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedCannon::RedCannon(int x, int y): Chess() {
    init(x, y);
}

RedCannon::RedCannon(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedCannon::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(250, 50, 50, 50));
    setPoint(QPoint(x, y));
}

RedCannon::~RedCannon() {

}

QString RedCannon::classname() {
    return QString("RedCannon");
}

RedCannon::PlaceVecSptr
  RedCannon::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
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
    do {
        i--;
    }while (i > 0 && !(c = cb[y-1][i-1]));
    if(i > 0 && c && c->isRed() != redmove) {
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
    do {
        i++;
    }while (i < 10 && !(c = cb[y-1][i-1]));
    if(i < 10 && c && c->isRed() != redmove) {
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
    do {
        i--;
    }while (i > 0 && !(c = cb[i-1][x-1]));
    if(i > 0 && c && c->isRed() != redmove) {
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
    do {
        i++;
    }while (i < 11 && !(c = cb[i-1][x-1]));
    if(i < 11 && c && c->isRed() != redmove) {
        cp.reset(new ChessPlace(Mesh(x, i), 1));
        next_vec.append(cp);
    }
    return next_vec;
}
