#include "recorder.h"

Recorder::Recorder() : cur_round_(0) {

}

void Recorder::write(const QString& str) {
    QString s = "<font color=\"#808080\">" + str + "</font>";
    emit recordHistory(s);
}

void Recorder::record(const ChessVecSptr& cb, const Mesh& from,
                      const Mesh& to, bool isred) {
    Round r;
    r.id_ = ++cur_round_;

    r.move_ = cb[from.meshy()-1][from.meshx()-1];
    r.from_ = from;
    r.to_ = to;
    if (cb[to.meshy()-1][to.meshx()-1]) {
        r.eaten_ = cb[to.meshy()-1][to.meshx()-1];
    } else {
        r.eaten_ = nullptr;
    }
    round_vec_.append(r);
    QString str = r.move_->chessname()+"从"+from.to_qstr()
            +"至"+to.to_qstr();
    if (isred) {
        str = "<font color=\"#FF0000\">" + str + "</font>";
    } else {
        str = "<font color=\"#000000\">" + str + "</font>";
    }
    emit recordHistory(str);
}

Recorder::Round Recorder::regret() {
    if (round_vec_.empty()) {
        qDebug() << "Regret Error";
        return Round();
    }
    auto r = round_vec_.last();
    round_vec_.pop_back();
    return r;
}

void Recorder::clear() {
    round_vec_.clear();
    cur_round_ = 0;
}
