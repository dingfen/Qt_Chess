#include "bishop.h"

BlackBishop::BlackBishop(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

BlackBishop::BlackBishop(int x, int y): Chess() {
    init(x, y);
}

BlackBishop::BlackBishop(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void BlackBishop::init(int x, int y) {
    is_red_ = false;
    setPixmap(ResourceManager::get().chessPixmap()->copy(100, 0, 50, 50));
    setPoint(QPoint(x, y));
    if (cur_pos_.meshx() == 3)
        chess_name_ = "左黑象";
    else if (cur_pos_.meshx() == 7)
        chess_name_ = "右黑象";
    else
        chess_name_ = "黑象";
}

BlackBishop::~BlackBishop() {

}

QString BlackBishop::classname() {
    return QString("BlackBishop");
}

BlackBishop::MeshVecSptr
  BlackBishop::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    move_range_.clear();
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> d;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (x+2 <= 9 && y+2 < 6) {
        if (!(d = cb[y][x]) &&
             (!(c = cb[y+1][x+1]) || c->isRed() != redmove)) {
            move_range_.append(Mesh(x+2, y+2));
        }
    }
    if (x+2 <= 9 && y-2 > 0) {
        if (!(d = cb[y-2][x]) &&
             (!(c = cb[y-3][x+1]) || c->isRed() != redmove)) {
            move_range_.append(Mesh(x+2, y-2));
        }
    }
    if (x-2 > 0 && y+2 < 6) {
        if (!(d = cb[y][x-2]) &&
             (!(c = cb[y+1][x-3]) || c->isRed() != redmove)) {
            move_range_.append(Mesh(x-2, y+2));
        }
    }
    if (x-2 > 0 && y-2 > 0) {
        if (!(d = cb[y-2][x-2]) &&
             (!(c = cb[y-3][x-3]) || c->isRed() != redmove)) {
            move_range_.append(Mesh(x-2, y-2));
        }
    }
    return move_range_;
}

QJsonObject BlackBishop::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Bishop");
    obj.insert("Color", "Black");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}

/*
** *****            Red Bishop                 ***** **
*/

RedBishop::RedBishop(const QPoint& pos): Chess() {
    init(pos.x(), pos.y());
}

RedBishop::RedBishop(int x, int y): Chess() {
    init(x, y);
}

RedBishop::RedBishop(const Mesh& mesh): Chess() {
    init(mesh.x(), mesh.y());
}

void RedBishop::init(int x, int y) {
    setPixmap(ResourceManager::get().chessPixmap()->copy(100, 50, 50, 50));
    setPoint(QPoint(x, y));
    if (cur_pos_.meshx() == 3)
        chess_name_ = "左红象";
    else if (cur_pos_.meshx() == 7)
        chess_name_ = "右红象";
    else
        chess_name_ = "红象";
}

RedBishop::~RedBishop() {

}


QString RedBishop::classname() {
    return QString("RedBishop");
}

RedBishop::MeshVecSptr
  RedBishop::generateNextPlace(const ChessVecSptr& cb, bool redmove) {
    move_range_.clear();
    QSharedPointer<Chess> c;
    QSharedPointer<Chess> d;
    int x = cur_pos_.meshx();
    int y = cur_pos_.meshy();
    if (x+2 <= 9 && y+2 < 11) {
        if (!(d = cb[y][x]) &&
             (!(c = cb[y+1][x+1]) || c->isRed() != redmove)) {
            move_range_.append(Mesh(x+2, y+2));
        }
    }
    if (x+2 <= 9 && y-2 > 5) {
        if (!(d = cb[y-2][x]) &&
             (!(c = cb[y-3][x+1]) || c->isRed() != redmove)) {
            move_range_.append(Mesh(x+2, y-2));
        }
    }
    if (x-2 > 0 && y+2 < 11) {
        if (!(d = cb[y][x-2]) &&
             (!(c = cb[y+1][x-3]) || c->isRed() != redmove)) {
            move_range_.append(Mesh(x-2, y+2));
        }
    }
    if (x-2 > 0 && y-2 > 5) {
        if (!(d = cb[y-2][x-2]) &&
             (!(c = cb[y-3][x-3]) || c->isRed() != redmove)) {
            move_range_.append(Mesh(x-2, y-2));
        }
    }
    return move_range_;
}

QJsonObject RedBishop::toJson() {
    QJsonObject obj;
    obj.insert("Type", "Bishop");
    obj.insert("Color", "Red");
    obj.insert("X", QJsonValue(cur_pos_.meshx()));
    obj.insert("Y", QJsonValue(cur_pos_.meshy()));
    return obj;
}
