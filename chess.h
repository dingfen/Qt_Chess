#ifndef CHESS_H
#define CHESS_H

#include <QCursor>
#include <QEvent>
#include <QVector>
#include <QtDebug>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QGraphicsSceneMouseEvent>
#include "chessplace.h"
#include "resourcemanager.h"

class Chess : public QGraphicsPixmapItem {
public:
    explicit Chess();
    ~Chess();

    QPoint getPoint();
    void move(const Mesh&);
    void dead();
    void selected();
    void unselected();

    static bool isOnBoard(const Mesh&);
    static QString classname();
protected:
    Mesh cur_pos_;
    bool ishit_;
    QVector<QSharedPointer<ChessPlace>> next_vec;
    QSharedPointer<QGraphicsItemAnimation> anim;
    QSharedPointer<QTimeLine> tl;

    void setPoint(const Mesh&);
    void setPoint(const QPoint&);

    virtual void generateNextPlace() {};
    virtual void removeNextPlace() {};

private:
    void init();
};

#endif // CHESS_H
