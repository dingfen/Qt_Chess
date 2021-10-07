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
#include "chesschain.h"
#include "resourcemanager.h"

enum ChessType {
    BLACKKING=1,
    BLACKROOK,
    BLACKKNIGHT,
    BLACKCANON,
    BLACKGUARD,
    BLACKBISHOP,
    BLACKPAWN,

    REDKING,
    REDROOK,
    REDKNIGHT,
    REDCANON,
    REDGUARD,
    REDBISHOP,
    REDPAWN
};

class Chess : public QGraphicsPixmapItem {
public:
    using ChessVecSptr=QVector<QVector<QSharedPointer<Chess>>>;
    explicit Chess();
    ~Chess();

    void setPoint(const Mesh&);
    void setPoint(const QPoint&);
    Mesh getMesh() {
        return cur_pos_;
    }
    void setMesh(const Mesh& m) {
        cur_pos_ = m;
    }
    QVector<Mesh>& attackRegion() {
        return chain_->moveRange();
    }
    QSharedPointer<ChessChain> getChain() {
        return chain_;
    }
    void clearLastChain() {
        chain_->clear();
    }
    bool isRed() {
        return is_red_;
    }

    void animate(const Mesh &);
    virtual QSharedPointer<ChessChain>
        updateMovePlace(const ChessVecSptr&)=0;
    virtual QJsonObject toJson()=0;
    virtual int getType() = 0;

    static void updateChain(QSharedPointer<Chess>, QSharedPointer<Chess>, const Mesh&);
    static QString classname();
protected:
    Mesh cur_pos_;
    bool is_red_;
    QSharedPointer<ChessChain> chain_;
    QSharedPointer<QGraphicsItemAnimation> anim;
    QSharedPointer<QTimeLine> tl;

private:
    void init();
};

#endif // CHESS_H
