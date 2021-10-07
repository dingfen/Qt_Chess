#include "pawn.h"

BlackPawn::BlackPawn(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackPawn::BlackPawn(int x, int y): Chess() {
    init(x, y);
}

BlackPawn::BlackPawn(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackPawn::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(300, 0, 50, 50));
    setPoint(QPoint(x, y));
}

BlackPawn::~BlackPawn() {

}

QString BlackPawn::classname() {
    return QString("BlackPawn");
}

int BlackPawn::getType() {
    return BLACKPAWN;
}

QSharedPointer<ChessChain>
    BlackPawn::updateMovePlace(const ChessVecSptr& cb) {
    QSharedPointer<Chess> c;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> me = cb[y-1][x-1];
    if (y > 5) {
        if (y+1 < 11) {
            c = cb[y][x-1];
            updateChain(me, c, Mesh(x, y+1));
        }
        if (x+1 < 10) {
            c = cb[y-1][x];
            updateChain(me, c, Mesh(x+1, y));
        }
        if (x-1 > 0) {
            c = cb[y-1][x-2];
            updateChain(me, c, Mesh(x-1, y));
        }
    } else {
        if (y+1 < 11) {
            c = cb[y][x-1];
            updateChain(me, c, Mesh(x, y+1));
        }
    }
    return chain_;
}

QJsonObject BlackPawn::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Pawn");
    obj.insert("Color", "Black");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}

/*
** *****            Red Pawn                 ***** **
*/

RedPawn::RedPawn(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedPawn::RedPawn(int x, int y): Chess() {
    init(x, y);
}

RedPawn::RedPawn(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedPawn::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(300, 50, 50, 50));
    setPoint(QPoint(x, y));
}

RedPawn::~RedPawn() {

}

QString RedPawn::classname() {
    return QString("RedPawn");
}

int RedPawn::getType() {
    return REDPAWN;
}

QSharedPointer<ChessChain>
    RedPawn::updateMovePlace(const ChessVecSptr& cb) {
    QSharedPointer<Chess> c;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> me = cb[y-1][x-1];
    if (y < 6) {
        if (y-1 > 0) {
            c = cb[y-2][x-1];
            updateChain(me, c, Mesh(x, y-1));
        }
        if (x+1 < 10) {
            c = cb[y-1][x];
            updateChain(me, c, Mesh(x+1, y));
        }
        if (x-1 > 0) {
            c = cb[y-1][x-2];
            updateChain(me, c, Mesh(x-1, y));
        }
    } else {
        if (y-1 < 11) {
            c = cb[y-2][x-1];
            updateChain(me, c, Mesh(x, y-1));
        }
    }
    return chain_;
}

QJsonObject RedPawn::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Pawn");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
