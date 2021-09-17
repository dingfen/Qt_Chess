#ifndef CHESSSCENE_H
#define CHESSSCENE_H
#pragma execution_character_set("utf-8")

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "resourcemanager.h"
#include "chessboard.h"
#include "mesh.h"

class ChessScene : public QGraphicsScene {
    Q_OBJECT
public:
    using ChessVecSptr=QVector<QVector<QSharedPointer<Chess>>>;
    using PlaceVecSptr=QVector<QSharedPointer<ChessPlace>>;
    using MeshVecSptr =QVector<Mesh>;
    explicit ChessScene(QObject *parent = nullptr);
    ~ChessScene();

    bool isStart() {
        return is_start_;
    }
    void startGame(const QString& path);
    void saveGame(const QString& path);
    void write(const QString&);
    void clear();

signals:
    void recordHistory(const QString&);
    void nextRound(bool);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *);

private:
    bool is_start_;
    ChessVecSptr chess_vec;
    QSharedPointer<ChessBoard> chess_board_;
    QSharedPointer<ChessPlace> chess_place_move_to_;
    PlaceVecSptr move_vec;
    QSharedPointer<Chess>   selected_chess_;

    bool is_red_check_;
    bool is_black_check_;
    bool is_red_move_;

    void registerClass();
    void putAllChess(const QString& filepath);
    void selectValidPlace();
    void move(const Mesh&);
    void unSelectValidPlace();
    bool isValid(const Mesh&);
    void isCheck(const Mesh&);
};

#endif // CHESSSCENE_H
