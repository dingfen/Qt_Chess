#ifndef CANNON_H
#define CANNON_H

#include "chess.h"

class BlackCannon : public Chess {
public:
    explicit BlackCannon(const QPoint&);
    explicit BlackCannon(int, int);
    explicit BlackCannon(const Mesh&);
    ~BlackCannon();
    QSharedPointer<ChessChain> updateMovePlace(const ChessVecSptr&) override;
    QJsonObject toJson() override;
    QString getType() override;
    static QString classname();
private:
    void init(int x, int y);
};

class RedCannon : public Chess {
public:
    explicit RedCannon(const QPoint&);
    explicit RedCannon(int, int);
    explicit RedCannon(const Mesh&);
    ~RedCannon();
    QSharedPointer<ChessChain> updateMovePlace(const ChessVecSptr&) override;
    QJsonObject toJson() override;
    QString getType() override;
    static QString classname();
private:
    void init(int x, int y);
};

#endif // CANNON_H
