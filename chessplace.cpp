#include "chessplace.h"

ChessPlace::ChessPlace(const Mesh& mesh, int choice) {
    cur_pos_ = mesh;
    init(mesh.x(), mesh.y(), choice);
}

ChessPlace::ChessPlace(const QPoint& p, int choice) {
    Mesh mesh(p);
    init(mesh.x(), mesh.y(), choice);
}

ChessPlace::~ChessPlace() {

}

void ChessPlace::init(int x, int y, int choice) {
    const QPixmap* q = ResourceManager::get().chessPlacePixmap();
    setPixmap(q->copy(1+choice*68, 0, 66, 66));
    this->setPos(x, y);
    this->setScale(1.5);
}

Mesh ChessPlace::getMesh() {
    return cur_pos_;
}
