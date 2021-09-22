﻿#include "guard.h"

BlackGuard::BlackGuard(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackGuard::BlackGuard(int x, int y): Chess() {
    init(x, y);
}

BlackGuard::BlackGuard(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackGuard::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(50, 0, 50, 50));
    setPoint(QPoint(x, y));
    if (cur_pos_.meshx() == 4)
        chess_name_ = "左黑士";
    else if (cur_pos_.meshx() == 6)
        chess_name_ = "右黑士";
    else
        chess_name_ = "黑士";
}

BlackGuard::~BlackGuard() {

}

QString BlackGuard::classname() {
    return QString("BlackGuard");
}

BlackGuard::MeshVecSptr
    BlackGuard::generateNextPlace(const ChessVecSptr& cb) {
    move_range_.clear();
    QSharedPointer<Chess> c;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (x+1 <= 6 && y+1 <= 3) {
        if (!(c = cb[y][x]) || c->isRed() != is_red_) {
            move_range_.append(Mesh(x+1, y+1));
        }
    }
    if (x+1 <= 6 && y-1 > 0) {
        if (!(c = cb[y-2][x]) || c->isRed() != is_red_) {
            move_range_.append(Mesh(x+1, y-1));
        }
    }
    if (x-1 >= 4 && y+1 <= 3) {
        if (!(c = cb[y][x-2]) || c->isRed() != is_red_) {
            move_range_.append(Mesh(x-1, y+1));
        }
    }
    if (x-1 >= 4 && y-1 > 0) {
        if (!(c = cb[y-2][x-2]) || c->isRed() != is_red_) {
            move_range_.append(Mesh(x-1, y-1));
        }
    }
    return move_range_;
}

QJsonObject BlackGuard::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Guard");
    obj.insert("Color", "Black");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}

/*
** *****            Red Guard                 ***** **
*/

RedGuard::RedGuard(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedGuard::RedGuard(int x, int y): Chess() {
    init(x, y);
}

RedGuard::RedGuard(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedGuard::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(50, 50, 50, 50));
    setPoint(QPoint(x, y));
    if (cur_pos_.meshx() == 4)
        chess_name_ = "左红士";
    else if (cur_pos_.meshx() == 6)
        chess_name_ = "右红士";
    else
        chess_name_ = "红士";
}

RedGuard::~RedGuard() {

}

QString RedGuard::classname() {
    return QString("RedGuard");
}

RedGuard::MeshVecSptr
    RedGuard::generateNextPlace(const ChessVecSptr& cb) {
    move_range_.clear();
    QSharedPointer<Chess> c;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (x+1 <= 6 && y+1 <= 10) {
        if (!(c = cb[y][x]) || c->isRed() != is_red_) {
            move_range_.append(Mesh(x+1, y+1));
        }
    }
    if (x+1 <= 6 && y-1 >= 8) {
        if (!(c = cb[y-2][x]) || c->isRed() != is_red_) {
            move_range_.append(Mesh(x+1, y-1));
        }
    }
    if (x-1 >= 4 && y+1 <= 10) {
        if (!(c = cb[y][x-2]) || c->isRed() != is_red_) {
            move_range_.append(Mesh(x-1, y+1));
        }
    }
    if (x-1 >= 4 && y-1 >= 8) {
        if (!(c = cb[y-2][x-2]) || c->isRed() != is_red_) {
            move_range_.append(Mesh(x-1, y-1));
        }
    }
    return move_range_;
}

QJsonObject RedGuard::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Guard");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
