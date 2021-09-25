#ifndef REHEARSALSCENE_H
#define REHEARSALSCENE_H

#include "chessscene.h"

class RehearsalScene : public ChessScene {
    Q_OBJECT
public:
    explicit RehearsalScene(QObject *parent = nullptr);
    void regret();
    void startGame(const QString &path);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);

private:
    // to judge if game is over
    QSharedPointer<Chess> black_king_;
    QSharedPointer<Chess> red_king_;

    void selectValidPlace();
    void move(const Mesh&);
    bool isValid(const Mesh&);
    bool isCheck();
    void stillCheck();
};

#endif // REHEARSALSCENE_H
