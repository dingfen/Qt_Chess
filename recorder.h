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
        Round() : id_(0), move_(nullptr),
            from_(), to_(), eaten_(nullptr) {
        }
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
    const QString chess_name[15] = {
        "", "黑将", "黑车", "黑马", "黑炮", "黑士", "黑象", "黑兵",
        "红帅", "红车", "红马", "红炮", "红士", "红象", "红兵"
    };
};

#endif // RECORDER_H
