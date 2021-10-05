#ifndef CHESSCHAIN_H
#define CHESSCHAIN_H

#include <QVector>
#include <QSharedPointer>
#include "mesh.h"

class Chess;

class ChessChain {
public:
    using ChessSptr=QSharedPointer<Chess>;
    ChessChain();
    ~ChessChain();

    QVector<Mesh>& moveRange() {
        return move_range;
    }

    void addAttack(ChessSptr);
    void addAssaulted(ChessSptr);
    void addGuards(ChessSptr);
    void addGuardeds(ChessSptr);

    QVector<ChessSptr> getGuards() {
        return guards;
    }
    QVector<ChessSptr> getGuardeds() {
        return guardeds;
    }
    QVector<ChessSptr> getAttacks() {
        return attacks;
    }
    QVector<ChessSptr> getAssaulteds() {
        return assaulteds;
    }
    QVector<Mesh> getMoveRange() {
        return move_range;
    }

    void addMoveRange(const Mesh&);
    void clear();

private:
    QVector<ChessSptr> guards;
    QVector<ChessSptr> guardeds;
    QVector<ChessSptr> attacks;
    QVector<ChessSptr> assaulteds;
    QVector<Mesh> move_range;
};

#endif // CHESSCHAIN_H
