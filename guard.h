#ifndef GUARD_H
#define GUARD_H

#include "chess.h"

class BlackGuard : public Chess {
public:
    explicit BlackGuard(const QPoint&);
    explicit BlackGuard(int, int);
    explicit BlackGuard(const Mesh&);
    ~BlackGuard();
    PlaceVecSptr generateNextPlace(const ChessVecSptr&, bool) override;

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
    PlaceVecSptr generateNextPlace(const ChessVecSptr&, bool) override;

    static QString classname();
private:
    void init(int x, int y);
};


#endif // GUARD_H
