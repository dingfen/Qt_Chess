#ifndef REHEARSALSCENE_H
#define REHEARSALSCENE_H

#include "chessscene.h"

class RehearsalScene : public ChessScene {
    Q_OBJECT
public:
    explicit RehearsalScene(QObject *parent = nullptr);
    void startGame(const QString &path) override;

public slots:
    void regret();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;

private:
    void selectValidPlace();
    void move(const Mesh&);
    bool isValid(const Mesh&);
    void stillCheck();
};

#endif // REHEARSALSCENE_H
