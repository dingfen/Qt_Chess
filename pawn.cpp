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
    setPixmap(ResourceManager::get().chessPixmap()->copy(300, 0, 50, 50));
    setPoint(QPoint(x, y));
}

BlackPawn::~BlackPawn() {

}

QString BlackPawn::classname() {
    return QString("BlackPawn");
}

void BlackPawn::generateNextPlace() {
    if (next_vec.empty()) {
        Mesh next(cur_pos_.meshx(), cur_pos_.meshy()+1);
        if (!isOnBoard(next)) {
            return;
        }
        ChessPlace* cp = new ChessPlace(next, 1);
        next_vec.append(QSharedPointer<ChessPlace>(cp));
        for (auto ptr : next_vec) {
            this->scene()->addItem(ptr.get());
        }
    }
}

void BlackPawn::removeNextPlace() {
    for(auto ptr : next_vec) {
        this->scene()->removeItem(ptr.get());
    }
    next_vec.clear();
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

//void RedPawn::move(const Mesh& mesh) {

//}

//bool RedPawn::isLegal(const Mesh& mesh) {
//    return true;
//}

QString RedPawn::classname() {
    return QString("RedPawn");
}
