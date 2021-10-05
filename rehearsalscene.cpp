#include "rehearsalscene.h"

RehearsalScene::RehearsalScene(QObject *parent) : ChessScene(parent) {

}

void RehearsalScene::startGame(const QString &path) {
    is_start_ = true;
    putAllChess(path);
    updateMovePlaces();
    recorder_->write("Load Completed!");
    recorder_->write("<h2>Rehearsal start!</h2>");
}

void RehearsalScene::regret() {
    if (is_start_ && !is_regret_) {
        backOneStep();
        backOneStep();
        updateMovePlaces();
        is_regret_ = true;
    }
}

void RehearsalScene::selectValidPlace() {
    auto mesh_vec = selected_chess_->attackRegion();
    QSharedPointer<ChessPlace> cp;
    for(auto mesh : mesh_vec) {
        cp.reset(new ChessPlace(mesh, 1));
        addItem(cp.get());
        move_vec.append(cp);
    }
}


/* whether click at valid place
 * valid: Move and kill
 * invalid: keep
 */
bool RehearsalScene::isValid(const Mesh& mesh) {
    for(auto ptr : move_vec) {
        if (mesh == ptr->getMesh()) {
            return true;
        }
    }
    return false;
}

void RehearsalScene::stillCheck() {
    qDebug() << "Check!";
    backOneStep();
    updateMovePlaces();
}


void RehearsalScene::move(const Mesh& m) {
    Mesh pos = selected_chess_->getMesh();
    selected_chess_->animate(m);
    recorder_->record(chess_vec, pos, m, is_red_move_);
    chess_vec[m.meshy()-1][m.meshx()-1].swap(selected_chess_);
    chess_vec[pos.meshy()-1][pos.meshx()-1].clear();
    if (selected_chess_) {
        removeItem(selected_chess_.get());
        selected_chess_.clear();
    }
}


void RehearsalScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (is_start_) {
        if (event->button() == Qt::LeftButton) {
            // get the clicked item, cast as Chess if it is
            Mesh mpos(event->lastScenePos());
            // second click
            if (selected_chess_) {
                if (isValid(mpos)) {
                    unSelectValidPlace();
                    move(mpos);
                    updateMovePlaces();
                    if (isCheck(is_red_move_)) {
                        stillCheck();
                        return;
                    }
                    is_red_move_ = !is_red_move_;
                    is_regret_ = false;
                    emit nextRound(is_red_move_);
                }
                return ;
            }
            // first click
            auto c = chess_vec[mpos.meshy()-1][mpos.meshx()-1];
            if (c && !selected_chess_ && is_red_move_ == c->isRed()) {
                // display all valid place, and if check
                selected_chess_ = chess_vec[mpos.meshy()-1][mpos.meshx()-1];
                selectValidPlace();
            }
        } else if (event->button() == Qt::RightButton) {
            if (selected_chess_) {
                unSelectValidPlace();
                selected_chess_ = nullptr;
            }
        }
    }
    QGraphicsScene::mousePressEvent(event);
}
