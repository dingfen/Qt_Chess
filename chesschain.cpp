#include "chesschain.h"

ChessChain::ChessChain() {
}

ChessChain::~ChessChain() {
}

void ChessChain::addAttack(ChessSptr ptr) {
    attacks.append(ptr);
}

void ChessChain::addAssaulted(ChessSptr ptr) {
    assaulteds.append(ptr);
}

void ChessChain::addGuards(ChessSptr ptr) {
    guards.append(ptr);
}

void ChessChain::addGuardeds(ChessSptr ptr) {
    guardeds.append(ptr);
}

void ChessChain::addMoveRange(const Mesh& m) {
    move_range.append(m);
}

void ChessChain::clear() {
    guards.clear();
    attacks.clear();
    assaulteds.clear();
    move_range.clear();
}
