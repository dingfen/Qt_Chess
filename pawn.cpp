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

QVector<QSharedPointer<ChessPlace>> BlackPawn::generateNextPlace() {
    QVector<QSharedPointer<ChessPlace>> next_vec;
    Mesh next(cur_pos_.meshx(), cur_pos_.meshy()+1);
    if (!isOnBoard(next)) {
       return next_vec;
    }
    ChessPlace* cp = new ChessPlace(next, 1);
    next_vec.append(QSharedPointer<ChessPlace>(cp));
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


QVector<QSharedPointer<ChessPlace>> RedPawn::generateNextPlace() {
    QVector<QSharedPointer<ChessPlace>> next_vec;
    Mesh next(cur_pos_.meshx(), cur_pos_.meshy()-1);
    if (!isOnBoard(next)) {
       return next_vec;
    }
    ChessPlace* cp = new ChessPlace(next, 1);
    next_vec.append(QSharedPointer<ChessPlace>(cp));
    return next_vec;
}
