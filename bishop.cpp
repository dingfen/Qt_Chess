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

//void BlackBishop::move(const Mesh& mesh) {

//}

//bool BlackBishop::isLegal(const Mesh& mesh) {
//    return true;
//}

QString BlackBishop::classname() {
    return QString("BlackBishop");
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

//void RedBishop::move(const Mesh& mesh) {

//}

//bool RedBishop::isLegal(const Mesh& mesh) {
//    return true;
//}

QString RedBishop::classname() {
    return QString("RedBishop");
}
