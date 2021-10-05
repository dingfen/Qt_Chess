#ifndef AISCENE_H
#define AISCENE_H

#include "chessscene.h"

class AIScene : public ChessScene {
    Q_OBJECT
public:
    using RoundSptr=QSharedPointer<Recorder::Round>;
    explicit AIScene(QObject *parent = nullptr);
    void startGame(const QString &path) override;

public slots:
    void regret();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;

private:
    struct ChessValue {
        int base_;
        int flex_;
    };

    // true means you are red
    // false means your are black
    bool you_move_;
    QMap<QString, ChessValue> chess_value_;


    void AIinit();
    void selectValidPlace();
    bool isValid(const Mesh&);
    void move(const Mesh&);

    void hypothesisMove(RoundSptr);
    void unHypothesisMove(RoundSptr);

    void waitForAI();
    void getAllSteps(QVector<RoundSptr> *, bool);
    double evaluate(bool);
    double getValue(QSharedPointer<Chess>, bool);
    RoundSptr minMaxSearch();
    double minSearch(int level, double cur_max);
    double maxSearch(int level, double cur_min);
};

#endif // AISCENE_H
