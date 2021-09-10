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
    setPixmap(ResourceManager::get().chessPixmap()->copy(250, 0, 50, 50));
    setPoint(QPoint(x, y));
}

BlackCannon::~BlackCannon() {

}

//void BlackCannon::move(const Mesh& mesh) {

//}

//bool BlackCannon::isLegal(const Mesh& mesh) {
//    return true;
//}

QString BlackCannon::classname() {
    return QString("BlackCannon");
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

//void RedCannon::move(const Mesh& mesh) {

//}

//bool RedCannon::isLegal(const Mesh& mesh) {
//    return true;
//}

QString RedCannon::classname() {
    return QString("RedCannon");
}
