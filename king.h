#ifndef KING_H
#define KING_H

#include "chess.h"

class BlackKing : public Chess {
public:
    explicit BlackKing(const QPoint&);
    explicit BlackKing(int, int);
    explicit BlackKing(const Mesh&);
    ~BlackKing();
    PlaceVecSptr generateNextPlace(const ChessVecSptr&, bool) override;

    static QString classname();
private:
    void init(int x, int y);
};

class RedKing : public Chess {
public:
    explicit RedKing(const QPoint&);
    explicit RedKing(int, int);
    explicit RedKing(const Mesh&);
    ~RedKing();
    PlaceVecSptr generateNextPlace(const ChessVecSptr&, bool) override;

    static QString classname();
private:
    void init(int x, int y);
};

#endif // KING_H
