#ifndef GUARD_H
#define GUARD_H

#include "chess.h"

class BlackGuard : public Chess {
public:
    explicit BlackGuard(const QPoint&);
    explicit BlackGuard(int, int);
    explicit BlackGuard(const Mesh&);
    ~BlackGuard();
    QSharedPointer<ChessChain> updateMovePlace(const ChessVecSptr&) override;
    QJsonObject toJson() override;
    QString getType() override;
    static QString classname();
private:
    void init(int x, int y);
};

class RedGuard : public Chess {
public:
    explicit RedGuard(const QPoint&);
    explicit RedGuard(int, int);
    explicit RedGuard(const Mesh&);
    ~RedGuard();
    QSharedPointer<ChessChain> updateMovePlace(const ChessVecSptr&) override;
    QJsonObject toJson() override;
    QString getType() override;
    static QString classname();
private:
    void init(int x, int y);
};


#endif // GUARD_H
