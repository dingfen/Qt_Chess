#ifndef CHESSPLACE_H
#define CHESSPLACE_H

#include "mesh.h"
#include "resourcemanager.h"

class ChessPlace : public QGraphicsPixmapItem {
public:
    explicit ChessPlace(const Mesh&, int);
    explicit ChessPlace(const QPoint&, int);
    ~ChessPlace();

    Mesh getPos();
private:
    void init(int, int, int);
    Mesh cur_pos_;
};

#endif // CHESSPLACE_H
