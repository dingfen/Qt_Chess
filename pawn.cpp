﻿#include "pawn.h"

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
    chess_name_ = QString(cur_pos_.meshx()+'0')+" 黑卒";
}

BlackPawn::~BlackPawn() {

}

QString BlackPawn::classname() {
    return QString("BlackPawn");
}

BlackPawn::MeshVecSptr
    BlackPawn::generateNextPlace(const ChessVecSptr& cb) {
    move_range_.clear();
    QSharedPointer<Chess> c;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (y > 5) {
        if (y+1 < 11 && (!(c = cb[y][x-1]) || c->isRed() != is_red_)) {
            move_range_.append(Mesh(x, y+1));
        }
        if (x+1 < 10 && (!(c = cb[y-1][x]) || c->isRed() != is_red_)) {
            move_range_.append(Mesh(x+1, y));
        }
        if (x-1 > 0 && (!(c = cb[y-1][x-2]) || c->isRed() != is_red_)) {
            move_range_.append(Mesh(x-1, y));
        }
    } else {
        if (y+1 < 11 && (!(c = cb[y][x-1]) || c->isRed() != is_red_)) {
            move_range_.append(Mesh(x, y+1));
        }
    }
    return move_range_;
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
    chess_name_ = QString(cur_pos_.meshx()+'0') + " 红兵";
}

RedPawn::~RedPawn() {

}

QString RedPawn::classname() {
    return QString("RedPawn");
}


RedPawn::MeshVecSptr
    RedPawn::generateNextPlace(const ChessVecSptr& cb) {
    move_range_.clear();
    QSharedPointer<Chess> c;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (y < 6) {
        if (y-1 > 0 && (!(c = cb[y-2][x-1]) || c->isRed() != is_red_)) {
            move_range_.append(Mesh(x, y-1));
        }
        if (x+1 < 10 && (!(c = cb[y-1][x]) || c->isRed() != is_red_)) {
            move_range_.append(Mesh(x+1, y));
        }
        if (x-1 > 0 && (!(c = cb[y-1][x-2]) || c->isRed() != is_red_)) {
            move_range_.append(Mesh(x-1, y));
        }
    } else {
        if (y-1 < 11 && (!(c = cb[y-2][x-1]) || c->isRed() != is_red_)) {
            move_range_.append(Mesh(x, y-1));
        }
    }
    return move_range_;
}

QJsonObject RedPawn::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Pawn");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
