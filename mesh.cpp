#include "mesh.h"

Mesh::Mesh(int x, int y) : x_(x), y_(y) {
}

Mesh::Mesh(const QPoint& p) {
    x_ = (int)(p.x()-63)/110 +1;
    y_ = (int)(p.y()-20)/110 +1;
}

Mesh::Mesh(const QPointF& p) {
    x_ = (int)(p.x()-63)/110 +1;
    y_ = (int)(p.y()-20)/110 +1;
}

Mesh::Mesh() : x_(0), y_(0) {
}

Mesh::~Mesh() {

}

bool Mesh::setMeshx(int x) {
    if (x >= 1 && x <= 9) {
        x_ = x;
        return true;
    }
    return false;
}

bool Mesh::setMeshy(int y) {
    if (y >= 1 && y <= 10) {
        y_ = y;
        return true;
    }
    return false;
}

QPoint Mesh::getPoint() const {
    QPoint p;
    p.setX(x_*110-47);
    p.setY(y_*110-90);
    return p;
}

QPointF Mesh::getPointF() const {
    QPointF p;
    p.setX(x_*110-47);
    p.setY(y_*110-90);
    return p;
}

int Mesh::x() const {
    return x_*110-47;
}

int Mesh::y() const {
    return y_*110-90;
}

int Mesh::meshx() const {
    return x_;
}

int Mesh::meshy() const {
    return y_;
}

bool Mesh::operator==(const Mesh& mesh) const{
    return x_ == mesh.x_ && y_ == mesh.y_;
}
