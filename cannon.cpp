﻿#include "cannon.h"

BlackCannon::BlackCannon(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackCannon::BlackCannon(int x, int y): Chess() {
    init(x, y);
}

BlackCannon::BlackCannon(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackCannon::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(250, 0, 50, 50));
    setPoint(QPoint(x, y));
    if (cur_pos_.meshx() == 2)
        chess_name_ = "左黑炮";
    else if (cur_pos_.meshx() == 8)
        chess_name_ = "右黑炮";
    else
        chess_name_ = "黑炮";
}

BlackCannon::~BlackCannon() {

}

QString BlackCannon::classname() {
    return QString("BlackCannon");
}

BlackCannon::MeshVecSptr
  BlackCannon::generateNextPlace(const ChessVecSptr& cb) {
    move_range_.clear();
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> c;
    int i = x-1;
    while (i > 0 && !(c = cb[y-1][i-1])) {
        move_range_.append(Mesh(i, y));
        i--;
    }
    do {
        i--;
    }while (i > 0 && !(c = cb[y-1][i-1]));
    if(i > 0 && c && c->isRed() != is_red_) {
        move_range_.append(Mesh(i, y));
    }
    c.clear();
    i = x+1;
    while (i < 10 && !(c = cb[y-1][i-1])) {
        move_range_.append(Mesh(i, y));
        i++;
    }
    do {
        i++;
    }while (i < 10 && !(c = cb[y-1][i-1]));
    if(i < 10 && c && c->isRed() != is_red_) {
        move_range_.append(Mesh(i, y));
    }
    c.clear();
    i = y-1;
    while (i > 0 && !(c = cb[i-1][x-1])) {
        move_range_.append(Mesh(x, i));
        i--;
    }
    do {
        i--;
    }while (i > 0 && !(c = cb[i-1][x-1]));
    if(i > 0 && c && c->isRed() != is_red_) {
        move_range_.append(Mesh(x, i));
    }
    c.clear();
    i = y+1;
    while (i < 11 && !(c = cb[i-1][x-1])) {
        move_range_.append(Mesh(x, i));
        i++;
    }
    do {
        i++;
    }while (i < 11 && !(c = cb[i-1][x-1]));
    if(i < 11 && c && c->isRed() != is_red_) {
        move_range_.append(Mesh(x, i));
    }
    return move_range_;
}

QJsonObject BlackCannon::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Cannon");
    obj.insert("Color", "Black");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}

/*
** *****            Red Cannon                 ***** **
*/

RedCannon::RedCannon(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedCannon::RedCannon(int x, int y): Chess() {
    init(x, y);
}

RedCannon::RedCannon(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedCannon::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(250, 50, 50, 50));
    setPoint(QPoint(x, y));
    if (cur_pos_.meshx() == 2)
        chess_name_ = "左红炮";
    else if (cur_pos_.meshx() == 8)
        chess_name_ = "右红炮";
    else
        chess_name_ = "红炮";
}

RedCannon::~RedCannon() {

}

QString RedCannon::classname() {
    return QString("RedCannon");
}

RedCannon::MeshVecSptr
  RedCannon::generateNextPlace(const ChessVecSptr& cb) {
    move_range_.clear();
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    QSharedPointer<Chess> c;
    int i = x-1;
    while (i > 0 && !(c = cb[y-1][i-1])) {
        move_range_.append(Mesh(i, y));
        i--;
    }
    do {
        i--;
    }while (i > 0 && !(c = cb[y-1][i-1]));
    if(i > 0 && c && c->isRed() != is_red_) {
        move_range_.append(Mesh(i, y));
    }
    c.clear();
    i = x+1;
    while (i < 10 && !(c = cb[y-1][i-1])) {
        move_range_.append(Mesh(i, y));
        i++;
    }
    do {
        i++;
    }while (i < 10 && !(c = cb[y-1][i-1]));
    if(i < 10 && c && c->isRed() != is_red_) {
        move_range_.append(Mesh(i, y));
    }
    c.clear();
    i = y-1;
    while (i > 0 && !(c = cb[i-1][x-1])) {
        move_range_.append(Mesh(x, i));
        i--;
    }
    do {
        i--;
    }while (i > 0 && !(c = cb[i-1][x-1]));
    if(i > 0 && c && c->isRed() != is_red_) {
        move_range_.append(Mesh(x, i));
    }
    c.clear();
    i = y+1;
    while (i < 11 && !(c = cb[i-1][x-1])) {
        move_range_.append(Mesh(x, i));
        i++;
    }
    do {
        i++;
    }while (i < 11 && !(c = cb[i-1][x-1]));
    if(i < 11 && c && c->isRed() != is_red_) {
        move_range_.append(Mesh(x, i));
    }
    return move_range_;
}

QJsonObject RedCannon::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Cannon");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
