#ifndef ROOK_H
#define ROOK_H

#include "chess.h"

class BlackRook : public Chess {
public:
    explicit BlackRook(const QPoint&);
    explicit BlackRook(int, int);
    explicit BlackRook(const Mesh&);
    ~BlackRook();

    static QString classname();
    QSharedPointer<ChessChain> updateMovePlace(const ChessVecSptr&) override;
    QJsonObject toJson() override;
    int getType() override;

private:
    void init(int x, int y);
};


class RedRook : public Chess {
public:
    explicit RedRook(const QPoint&);
    explicit RedRook(int, int);
    explicit RedRook(const Mesh&);
    ~RedRook();

    static QString classname();
    QSharedPointer<ChessChain> updateMovePlace(const ChessVecSptr&) override;
    QJsonObject toJson() override;
    int getType() override;

private:
    void init(int x, int y);
};
#endif // ROOK_H
