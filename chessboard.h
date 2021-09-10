#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QDebug>
#include <QVector>
#include <QGraphicsView>
#include "chessfactory.h"
#include "jsonparser.h"

class ChessBoard : public QGraphicsPixmapItem {
public:
    ChessBoard(const QPixmap&);
    ~ChessBoard();

private:
    QSharedPointer<Chess> active_;

    void registerClass();
};

#endif // CHESSBOARD_H
