#ifndef KNIGHT_H
#define KNIGHT_H

#include "chess.h"

class BlackKnight : public Chess {
public:
    explicit BlackKnight(const QPoint&);
    explicit BlackKnight(int, int);
    explicit BlackKnight(const Mesh&);
    ~BlackKnight();
    MeshVecSptr generateNextPlace(const ChessVecSptr&, bool) override;
    QJsonObject toJson() override;
    static QString classname();
private:
    void init(int x, int y);
};


class RedKnight : public Chess {
public:
    explicit RedKnight(const QPoint&);
    explicit RedKnight(int, int);
    explicit RedKnight(const Mesh&);
    ~RedKnight();
    MeshVecSptr generateNextPlace(const ChessVecSptr&, bool) override;
    QJsonObject toJson() override;
    static QString classname();
private:
    void init(int x, int y);
};

#endif // KNIGHT_H
