#ifndef BLACKSOLDIER_H
#define BLACKSOLDIER_H

#include <QtDebug>
#include "chess.h"

class BlackPawn : public Chess {
public:
    explicit BlackPawn(const QPoint&);
    explicit BlackPawn(int, int);
    explicit BlackPawn(const Mesh&);
    ~BlackPawn();
    static QString classname();
    PlaceVecSptr generateNextPlace(const ChessVecSptr&, bool) override;

private:
    void init(int x, int y);
};

class RedPawn : public Chess {
public:
    explicit RedPawn(const QPoint&);
    explicit RedPawn(int, int);
    explicit RedPawn(const Mesh&);
    ~RedPawn();
   static QString classname();
   PlaceVecSptr generateNextPlace(const ChessVecSptr&, bool) override;
private:
    void init(int x, int y);
};


#endif // BLACKSOLDIER_H
