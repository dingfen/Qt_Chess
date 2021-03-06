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

void Chess::init() {
    chain_.reset(new ChessChain);
    this->setScale(2.0);
    this->setCursor(Qt::PointingHandCursor);
    anim.reset(new QGraphicsItemAnimation);
    tl.reset(new QTimeLine(500));
    anim->setItem(this);
    anim->setTimeLine(tl.get());
}

void Chess::animate(const Mesh &m) {
    QPointF start = cur_pos_.getPointF();
    QPointF end = m.getPointF();
    for (int i = 0; i < 100; ++i) {
        QPointF pg = start + i*(end -start)/100.0;
        anim->setPosAt(i/100.0, pg);
    }
    tl->start();
    cur_pos_ = m;
}

void Chess::updateChain(QSharedPointer<Chess> th, QSharedPointer<Chess> ptr, const Mesh& m) {
    if (ptr) {
      if (ptr->is_red_ != th->is_red_) {
        th->chain_->addAttack(ptr);
        th->chain_->addMoveRange(m);
        ptr->chain_->addAssaulted(th);
      } else {
        th->chain_->addGuards(ptr);
        ptr->chain_->addGuardeds(th);
      }
    } else {
        th->chain_->addMoveRange(m);
    }
}
