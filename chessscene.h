#ifndef CHESSSCENE_H
#define CHESSSCENE_H
#pragma execution_character_set("utf-8")

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QTimer>
#include "resourcemanager.h"
#include "chessboard.h"
#include "recorder.h"
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
    bool isCheck(bool);
    bool who() {
        return is_red_move_;
    }
    virtual void startGame(const QString& path);
    void saveGame(const QString& path);
    void regret();
    void clear();
    Recorder* getRecorder() {
        return recorder_.get();
    }

signals:
    void nextRound(bool);
    void remainTime(int);
    void timeOut();

protected:
    bool is_start_;
    bool is_red_move_;
    bool is_regret_;
    int totalTime;
    QSharedPointer<QTimer> timer_;

    ChessVecSptr chess_vec;
    // to judge if game is over
    QSharedPointer<Chess> black_king_;
    QSharedPointer<Chess> red_king_;

    QSharedPointer<ChessBoard> chess_board_;
    QSharedPointer<ChessPlace> chess_place_move_to_;
    PlaceVecSptr move_vec;
    QSharedPointer<Chess>   selected_chess_;
    QSharedPointer<Recorder> recorder_;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *);
    void registerClass();
    void changehands();
    void putAllChess(const QString& filepath);
    void unSelectValidPlace();
    void updateMovePlaces();
    void backOneStep();

protected slots:
    void runtime() {
        if (totalTime > 0)
            emit remainTime(totalTime--);
        else
            emit timeOut();
    }
};

#endif // CHESSSCENE_H
