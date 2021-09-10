#ifndef MESH_H
#define MESH_H

#include <QPoint>
#include <QPointF>

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
    void adsorbPoint(const QPoint&);
    void adsorbPoint(const QPointF&);
    int x() const;
    int y() const;
    int meshx() const;
    int meshy() const;

    bool operator==(const Mesh&) const;
private:
    int x_;
    int y_;
};

#endif // MESH_H
