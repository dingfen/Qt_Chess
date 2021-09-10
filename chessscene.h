#ifndef CHESSSCENE_H
#define CHESSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "resourcemanager.h"
#include "chessplace.h"
#include "chessboard.h"
#include "chess.h"

class ChessScene : public QGraphicsScene {
public:
    explicit ChessScene(QObject *parent = nullptr);
    ~ChessScene();

    bool isStart() {
        return is_start_;
    }

    void startGame(const QString& path);
    void putAllChess(const QString& filepath);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *);

private:
    bool is_start_;
    QVector<QSharedPointer<Chess>> black_vec;
    QVector<QSharedPointer<Chess>> red_vec;
    QSharedPointer<ChessBoard> chess_board_;
    QSharedPointer<ChessPlace> chess_place_point_to_;
    Chess*   selected_chess_;

    void registerClass();
};

#endif // CHESSSCENE_H
