#include "aiscene.h"

AIScene::AIScene(QObject *parent)
    : ChessScene(parent), you_move_(true) {

}

void AIScene::startGame(const QString &path) {
    is_start_ = true;
    putAllChess(path);
    updateMovePlaces();
    se_.reset(new SearchEngine);
    recorder_->write("Load Completed!");
    recorder_->write("<h2>AI Game start!</h2>");
    connect(timer_.get(), &QTimer::timeout, this, &AIScene::runtime);
    timer_->start(1000);
}

void AIScene::regret() {
    if (is_start_ && !is_regret_) {
        backOneStep();
        updateMovePlaces();
        is_regret_ = true;
    }
}

void AIScene::selectValidPlace() {
    auto mesh_vec = selected_chess_->attackRegion();
    for(auto &m : mesh_vec) {
        RoundSptr r(new Recorder::Round);
        r->move_ = selected_chess_;
        r->from_ = selected_chess_->getMesh();
        r->to_ = m;
        hypothesisMove(r);
        updateMovePlaces();
        if (isCheck(you_move_)) {
            mesh_vec.removeOne(m);
        }
        unHypothesisMove(r);
        updateMovePlaces();
    }
    QSharedPointer<ChessPlace> cp;
    for(auto mesh : mesh_vec) {
        cp.reset(new ChessPlace(mesh, 1));
        addItem(cp.get());
        move_vec.append(cp);
    }
}

bool AIScene::isValid(const Mesh& mesh) {
    for(auto ptr : move_vec) {
        if (mesh == ptr->getMesh()) {
            return true;
        }
    }
    return false;
}

bool AIScene::isGameOver() {
    return false;
}

void AIScene::move(const Mesh& m) {
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


void AIScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (is_start_ && is_red_move_ == you_move_) {
        if (event->button() == Qt::LeftButton) {
            Mesh mpos(event->lastScenePos());
            // second click
            if (selected_chess_) {
                if (isValid(mpos)) {
                    unSelectValidPlace();
                    move(mpos);
                    updateMovePlaces();
                    changehands();
                    isGameOver();

                    QFuture<void> f1 = QtConcurrent::run(this, &AIScene::waitForAI);
                    if (f1.isFinished()) {
                        changehands();
                        isGameOver();
                    }
                }
                return;
            }
            //first click
            auto c = chess_vec[mpos.meshy()-1][mpos.meshx()-1];
            if (c && !selected_chess_) {
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

void AIScene::hypothesisMove(RoundSptr r) {
    auto chess = r->move_;
    auto from = r->from_;
    auto to = r->to_;
    assert(from == chess->getMesh());
    chess->setMesh(to);
    chess_vec[to.meshy()-1][to.meshx()-1].swap(chess);
    chess_vec[from.meshy()-1][from.meshx()-1].clear();
    if (chess) {
        r->eaten_ = chess;
    }

}

void AIScene::unHypothesisMove(RoundSptr r) {
    auto chess = r->move_;
    auto from = r->from_;
    auto to = r->to_;
    assert(to == chess->getMesh());
    chess->setMesh(from);
    chess_vec[from.meshy()-1][from.meshx()-1].swap(chess);
    chess_vec[to.meshy()-1][to.meshx()-1] = r->eaten_;
}

void AIScene::waitForAI() {
    auto r = minMaxSearch();
    if (!r) {
        qDebug() << "You Win!";
        clear();
        return;
    }
    selected_chess_ = r->move_;
    move(r->to_);
    updateMovePlaces();
}

AIScene::RoundSptr AIScene::minMaxSearch() {
    QVector<RoundSptr> steps;
    // 1. get all possible steps
    getAllSteps(&steps, !you_move_);

    // 2. initial value & start search
    // AI for minimize while you for maximize
    double max = -std::numeric_limits<double>::max();
    int l = 4;
    RoundSptr best = nullptr;
    while(!steps.empty()) {
        RoundSptr cur_step = steps.back();
        steps.pop_back();

        hypothesisMove(cur_step);
        double score = minSearch(l-1, max);
        unHypothesisMove(cur_step);
        if (score > max) {
            max = score;
            best = cur_step;
        }
    }
    return best;
}

void AIScene::getAllSteps(QVector<RoundSptr> *steps, bool isred) {
    for(auto &row : chess_vec) {
        for(auto &chess : row) {
            if (chess && chess->isRed() == isred) {
                auto region = chess->attackRegion();
                for(auto place : region) {
                    RoundSptr round(new Recorder::Round);
                    round->move_ = chess;
                    round->from_ = chess->getMesh();
                    round->to_ = place;
                    steps->append(round);
                }
            }
        }
    }
}

int AIScene::minSearch(int level, double cur_max) {
    if (!level) {
        return se_->evaluate(chess_vec, you_move_);
    } else {
        QVector<RoundSptr> steps;
        getAllSteps(&steps, you_move_);
        double min = std::numeric_limits<double>::max();
        while(!steps.empty()) {
            RoundSptr cur_step = steps.back();
            steps.pop_back();

            hypothesisMove(cur_step);
            updateMovePlaces();
            double score = maxSearch(level-1, min);
//            qDebug("in minSearch: %d", score);
            unHypothesisMove(cur_step);
            updateMovePlaces();

            if (score < cur_max)
                return score;
            if (score < min) {
                min = score;
            }
        }
        return min;
    }
}


int AIScene::maxSearch(int level, double cur_min) {
    if (!level) {
        return se_->evaluate(chess_vec, !you_move_);
    } else {
        QVector<RoundSptr> steps;
        getAllSteps(&steps, !you_move_);
        int max = std::numeric_limits<int>::min();
        while(!steps.empty()) {
            RoundSptr cur_step = steps.back();
            steps.pop_back();

            hypothesisMove(cur_step);
            updateMovePlaces();
            double score = minSearch(level-1, max);
//            qDebug("in maxSearch: %d", score);
            unHypothesisMove(cur_step);
            updateMovePlaces();

            if (score > cur_min)
                return score;
            if (score > max) {
                max = score;
            }
        }
        return max;
    }
}
