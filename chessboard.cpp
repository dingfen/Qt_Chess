#include "chessboard.h"

ChessBoard::ChessBoard(const QPixmap & img) {
    setPixmap(img);
}

ChessBoard::~ChessBoard() {

}


//void ChessBoard::mousePressEvent(QGraphicsSceneMouseEvent *event) {
//    qDebug() << "ChessBoard clicked.";
//}

//void ChessBoard::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
//    QPointF p = event->lastPos();
//    Mesh m(p);
//    qDebug() << "(" << m.meshx() << ", " << m.meshy() << ")";
//}
