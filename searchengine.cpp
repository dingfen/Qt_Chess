#include "searchengine.h"


SearchEngine::SearchEngine()
{

}

int SearchEngine::getPosValue(QSharedPointer<Chess> c) {
    Mesh p = c->getMesh();
    if (c->isRed()) {
        return BA0[p.meshy()-1][p.meshx()-1];
    } else {
        return BA1[p.meshy()-1][p.meshx()-1];
    }
    return 0;
}

int SearchEngine::getAssaultedScore(QSharedPointer<Chess> c) {
    auto attacks = c->getChain()->getAssaulteds();
    int value = 0;
    for(auto& a : attacks) {
        value += (30 +(basevalue[c->getType()]-basevalue[a->getType()])/10)/10;
    }
    value += attacks.size();
    return value;
}


int SearchEngine::evaluate(const ChessVecSptr & cb, bool isred) {
    int red = 0;
    int black = 0;
    for(auto& row : cb) {
        for(auto& chess : row) {
            if (chess) {
                int value = 1;
                int base = basevalue[chess->getType()];
                // add the flexiability of chess
                value += flexvalue[chess->getType()] * chess->attackRegion().size();
                // add position value
                value += getPosValue(chess);
                // add base value
                value += base;

                int unit = base / 16;
                if (chess->isRed()) {
                    if (!chess->getChain()->getAssaulteds().empty()) {
                        // chess is threatened, and now is red turn
                        if (isred) {
                            if (chess->getType() == REDKING)
                                value -= 20;
                            value -= unit * 2;
                            if (!chess->getChain()->getGuardeds().empty())
                                value += unit;

                        } else {
                            if (chess->getType() == REDKING)
                                return 20000;
                            value -= unit * 10;
                            if (!chess->getChain()->getGuardeds().empty())
                                value += unit * 9;
                        }
                        value -= getAssaultedScore(chess);
                    } else {
                        // no threaten
                        if (!chess->getChain()->getGuardeds().empty())
                            value += 5;
                    }
                    red += value;
                } else {
                    // black is the same
                    if (!chess->getChain()->getAssaulteds().empty()) {
                        if (!isred) {
                            if (chess->getType() == BLACKKING)
                                value -= 20;
                            value -= unit * 2;
                            if (!chess->getChain()->getGuardeds().empty())
                                value += unit;
                        } else {
                            if (chess->getType() == BLACKKING)
                                return 20000;
                            value -= unit * 10;
                            if (!chess->getChain()->getGuardeds().empty())
                                value += unit * 9;
                        }
                        value -= getAssaultedScore(chess);
                    } else {
                        if (!chess->getChain()->getGuardeds().empty())
                            value += 5;
                    }
                    black += value;
                }
            }
        }
    }
    if (isred)
        return black-red;
    else
        return red-black;
}
