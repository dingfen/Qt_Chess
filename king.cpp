#include "king.h"

BlackKing::BlackKing(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackKing::BlackKing(int x, int y): Chess() {
    init(x, y);
}

BlackKing::BlackKing(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackKing::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(0, 0, 50, 50));
    setPoint(QPoint(x, y));
}

BlackKing::~BlackKing() {

}

//void BlackKing::move(const Mesh& mesh) {

//}

//bool BlackKing::isLegal(const Mesh& mesh) {
//    return true;
//}

QString BlackKing::classname() {
    return QString("BlackKing");
}

/*
** *****            Red King                 ***** **
*/

RedKing::RedKing(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedKing::RedKing(int x, int y): Chess() {
    init(x, y);
}

RedKing::RedKing(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedKing::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(0, 50, 50, 50));
    setPoint(QPoint(x, y));
}

RedKing::~RedKing() {

}

//void RedKing::move(const Mesh& mesh) {

//}

//bool RedKing::isLegal(const Mesh& mesh) {
//    return true;
//}

QString RedKing::classname() {
    return QString("RedKing");
}
