#ifndef CHESS_H
#define CHESS_H
#pragma execution_character_set("utf-8")

#include <QCursor>
#include <QEvent>
#include <QVector>
#include <QtDebug>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QGraphicsSceneMouseEvent>
#include <QJsonObject>
#include "chessplace.h"
#include "resourcemanager.h"

class Chess : public QGraphicsPixmapItem {
public:
    using MeshVecSptr=QVector<Mesh>;
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
    QString chessname() {
        return chess_name_;
    }

    virtual MeshVecSptr generateNextPlace(const ChessVecSptr&, bool)=0;
    virtual QJsonObject toJson()=0;
    static QString classname();
protected:
    Mesh cur_pos_;
    bool is_red_;
    MeshVecSptr move_range_;
    QString chess_name_;
    QSharedPointer<QGraphicsItemAnimation> anim;
    QSharedPointer<QTimeLine> tl;

    void setPoint(const Mesh&);
    void setPoint(const QPoint&);

private:
    void init();
};

#endif // CHESS_H
