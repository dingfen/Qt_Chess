#include "guard.h"

BlackGuard::BlackGuard(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackGuard::BlackGuard(int x, int y): Chess() {
    init(x, y);
}

BlackGuard::BlackGuard(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackGuard::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(50, 0, 50, 50));
    setPoint(QPoint(x, y));
}

BlackGuard::~BlackGuard() {

}

//void BlackGuard::move(const Mesh& mesh) {

//}

//bool BlackGuard::isLegal(const Mesh& mesh) {
//    return true;
//}

QString BlackGuard::classname() {
    return QString("BlackGuard");
}

/*
** *****            Red Guard                 ***** **
*/

RedGuard::RedGuard(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedGuard::RedGuard(int x, int y): Chess() {
    init(x, y);
}

RedGuard::RedGuard(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedGuard::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(50, 50, 50, 50));
    setPoint(QPoint(x, y));
}

RedGuard::~RedGuard() {

}

//void RedGuard::move(const Mesh& mesh) {

//}

//bool RedGuard::isLegal(const Mesh& mesh) {
//    return true;
//}

QString RedGuard::classname() {
    return QString("RedGuard");
}
