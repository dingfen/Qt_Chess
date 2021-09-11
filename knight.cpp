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

//void BlackKnight::move(const Mesh& mesh) {

//}

//bool BlackKnight::isLegal(const Mesh& mesh) {
//    return true;
//}

QString BlackKnight::classname() {
    return QString("BlackKnight");
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

//void RedKnight::move(const Mesh& mesh) {

//}

//bool RedKnight::isLegal(const Mesh& mesh) {
//    return true;
//}

QString RedKnight::classname() {
    return QString("RedKnight");
}
