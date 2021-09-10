#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QSharedPointer>

class ResourceManager {
public:
    static const ResourceManager& get();
    const QPixmap* chessPixmap() const;
    const QPixmap* chessBoardPixmap() const;
    const QPixmap *chessPlacePixmap() const;

private:
    // singleton pattern
    ResourceManager();
    ~ResourceManager() {};
    ResourceManager(const ResourceManager&);
    ResourceManager& operator=(const ResourceManager&);

    QSharedPointer<QPixmap> chess_board_;
    QSharedPointer<QPixmap> chess_;
    QSharedPointer<QPixmap> chess_place_;
};

#endif // RESOURCEMANAGER_H
