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

    Mesh getMesh() {
        return cur_pos_;
    }
    void move(const Mesh&);
    void dead();
    bool isRed() {
        return is_red_;
    }

    virtual QVector<QSharedPointer<ChessPlace>> generateNextPlace() {
        return QVector<QSharedPointer<ChessPlace>>({});
    };
    static bool isOnBoard(const Mesh&);
    static QString classname();
protected:
    Mesh cur_pos_;
    bool is_red_;
    QSharedPointer<QGraphicsItemAnimation> anim;
    QSharedPointer<QTimeLine> tl;

    void setPoint(const Mesh&);
    void setPoint(const QPoint&);

private:
    void init();
};

#endif // CHESS_H
