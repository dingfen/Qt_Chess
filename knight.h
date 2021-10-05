#ifndef KNIGHT_H
#define KNIGHT_H

#include "chess.h"

class BlackKnight : public Chess {
public:
    explicit BlackKnight(const QPoint&);
    explicit BlackKnight(int, int);
    explicit BlackKnight(const Mesh&);
    ~BlackKnight();
    QSharedPointer<ChessChain> updateMovePlace(const ChessVecSptr&) override;
    QJsonObject toJson() override;
    QString getType() override;
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
    QSharedPointer<ChessChain> updateMovePlace(const ChessVecSptr&) override;
    QJsonObject toJson() override;
    QString getType() override;
    static QString classname();
private:
    void init(int x, int y);
};

#endif // KNIGHT_H
