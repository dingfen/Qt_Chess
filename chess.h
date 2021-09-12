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
    using PlaceVecSptr=QVector<QSharedPointer<ChessPlace>>;
    using ChessVecSptr=QVector<QVector<QSharedPointer<Chess>>>;
    explicit Chess();
    ~Chess();

    Mesh getMesh() {
        return cur_pos_;
    }
    void animate(const Mesh&);
    bool isRed() {
        return is_red_;
    }

    virtual PlaceVecSptr generateNextPlace(const ChessVecSptr&, bool) {
        return PlaceVecSptr({});
    };
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
