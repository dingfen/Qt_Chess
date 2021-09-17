#ifndef BISHOP_H
#define BISHOP_H

#include "chess.h"

class BlackBishop : public Chess {
public:
    explicit BlackBishop(const QPoint&);
    explicit BlackBishop(int, int);
    explicit BlackBishop(const Mesh&);
    ~BlackBishop();
    MeshVecSptr generateNextPlace(const ChessVecSptr&, bool) override;
    QJsonObject toJson() override;
    static QString classname();
private:
    void init(int x, int y);
};

class RedBishop : public Chess {
public:
    explicit RedBishop(const QPoint&);
    explicit RedBishop(int, int);
    explicit RedBishop(const Mesh&);
    ~RedBishop();
    MeshVecSptr generateNextPlace(const ChessVecSptr&, bool) override;
    QJsonObject toJson() override;
    static QString classname();
private:
    void init(int x, int y);
};
#endif // BISHOP_H
