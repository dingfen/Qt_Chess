#ifndef AISCENE_H
#define AISCENE_H

#include "chessscene.h"
#include "searchengine.h"

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
    QSharedPointer<SearchEngine> se_;

    void searchEngineInit();
    void selectValidPlace();
    bool isValid(const Mesh&);
    void move(const Mesh&);

    void hypothesisMove(RoundSptr);
    void unHypothesisMove(RoundSptr);
    bool isGameOver();
    void waitForAI();
    void getAllSteps(QVector<RoundSptr> *, bool);
    RoundSptr minMaxSearch();
    int minSearch(int level, double cur_max);
    int maxSearch(int level, double cur_min);
};

#endif // AISCENE_H
