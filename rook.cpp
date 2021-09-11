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


QVector<QSharedPointer<ChessPlace>> BlackRook::generateNextPlace() {
    QVector<QSharedPointer<ChessPlace>> next_vec;
    QVector<Mesh> meshs;
    for(int i = 1; i <= 9; i++)
        if (cur_pos_.meshx() != i)
            meshs.append(Mesh(i, cur_pos_.meshy()));
    for(int i = 1; i <= 10; i++)
        if (cur_pos_.meshy() != i)
            meshs.append(Mesh(cur_pos_.meshx(), i));
    for(auto m : meshs) {
        ChessPlace *cp = new ChessPlace(m, 1);
        next_vec.append(QSharedPointer<ChessPlace>(cp));
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

QVector<QSharedPointer<ChessPlace>> RedRook::generateNextPlace() {
    QVector<QSharedPointer<ChessPlace>> next_vec;
    QVector<Mesh> meshs;
    for(int i = 1; i <= 9; i++)
        if (cur_pos_.meshx() != i)
            meshs.append(Mesh(i, cur_pos_.meshy()));
    for(int i = 1; i <= 10; i++)
        if (cur_pos_.meshy() != i)
            meshs.append(Mesh(cur_pos_.meshx(), i));
    for(auto m : meshs) {
        ChessPlace *cp = new ChessPlace(m, 1);
        next_vec.append(QSharedPointer<ChessPlace>(cp));
    }
    return next_vec;
}
