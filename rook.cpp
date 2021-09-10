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
    setPixmap(ResourceManager::get().chessPixmap()->copy(200, 0, 50, 50));
    setPoint(QPoint(x, y));
}

BlackRook::~BlackRook() {

}

//void BlackRook::move(const Mesh& mesh) {

//}

//bool BlackRook::isLegal(const Mesh& mesh) {
//    return true;
//}

QString BlackRook::classname() {
    return QString("BlackRook");
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

//void RedRook::move(const Mesh& mesh) {

//}

//bool RedRook::isLegal(const Mesh& mesh) {
//    return true;
//}

QString RedRook::classname() {
    return QString("RedRook");
}
