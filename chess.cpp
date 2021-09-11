#include "chess.h"

Chess::Chess()
    :cur_pos_(0, 0), is_red_(true) {
    init();
}

Chess::~Chess() {

}

void Chess::setPoint(const Mesh &m) {
    cur_pos_ = m;
    setPos(cur_pos_.x(), cur_pos_.y());
}

void Chess::setPoint(const QPoint &p) {
    cur_pos_ = Mesh(p);
    setPos(p);
}

QString Chess::classname() {
    return QString("Chess");
}

bool Chess::isOnBoard(const Mesh &mesh) {
    if (mesh.meshx() < 1 || mesh.meshx() > 9 ||
        mesh.meshy() < 1 || mesh.meshy() > 10) {
        return false;
    } else {
        return true;
    }
}


void Chess::init() {
    this->setScale(2.0);
    this->setCursor(Qt::PointingHandCursor);
    anim.reset(new QGraphicsItemAnimation);
    anim->setItem(this);
    tl.reset(new QTimeLine(500));
    anim->setTimeLine(tl.get());
}

void Chess::move(const Mesh &m) {
    QPointF start = cur_pos_.getPointF();
    QPointF end = m.getPointF();
    for (int i = 0; i < 100; ++i) {
        QPointF pg = start + i*(end -start)/100.0;
        anim->setPosAt(i/100.0, pg);
    }
    tl->start();
    cur_pos_ = m;
    qDebug() << "Move";
}

void Chess::dead() {
    scene()->removeItem(this);
}
