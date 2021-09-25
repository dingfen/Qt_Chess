#ifndef RECORDER_H
#define RECORDER_H
#pragma execution_character_set("utf-8")

#include <QString>
#include <QVector>
#include <QObject>
#include "mesh.h"
#include "chess.h"

class Recorder : public QObject {
    Q_OBJECT
public:
    class Round {
    public:
        int id_;
        QSharedPointer<Chess> move_;
        Mesh from_;
        Mesh to_;
        QSharedPointer<Chess> eaten_;
    };
    using ChessVecSptr=QVector<QVector<QSharedPointer<Chess>>>;
    Recorder();
    void write(const QString& str);
    void record(const ChessVecSptr& cb, const Mesh& from, const Mesh& to, bool);
    Round regret();
    void clear();

signals:
    void recordHistory(const QString&);

private:
    int cur_round_;
    QVector<Round> round_vec_;
};

#endif // RECORDER_H
