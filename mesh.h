#ifndef MESH_H
#define MESH_H

#include <QPoint>
#include <QPointF>
#include <QString>

class Mesh {
public:
    // mesh number from 1 to count
    Mesh(const QPoint &p);
    Mesh(const QPointF& p);
    Mesh(int, int);
    Mesh();
    ~Mesh();

    QPoint getPoint() const;
    QPointF getPointF() const;
    bool setMeshx(int);
    bool setMeshy(int);
    int x() const;
    int y() const;
    int meshx() const;
    int meshy() const;
    QString to_qstr() const;

    bool operator==(const Mesh&) const;
private:
    int x_;
    int y_;
};

#endif // MESH_H
