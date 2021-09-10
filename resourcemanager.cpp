#include "resourcemanager.h"

ResourceManager::ResourceManager() {
    chess_.reset(new QPixmap(":/img/img/chess.png"));
    chess_board_.reset(new QPixmap(":/img/img/chess_board.png"));
    chess_place_.reset(new QPixmap(":/img/img/labeled.png"));
}

const ResourceManager& ResourceManager::get() {
    static ResourceManager instance;
    return instance;
}

const QPixmap *ResourceManager::chessPixmap() const{
    return chess_.get();
}

const QPixmap *ResourceManager::chessBoardPixmap() const{
    return chess_board_.get();
}

const QPixmap *ResourceManager::chessPlacePixmap() const{
    return chess_place_.get();
}
