#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "chess.h"

class SearchEngine
{
public:
    using ChessVecSptr=QVector<QVector<QSharedPointer<Chess>>>;
    SearchEngine();

    int evaluate(const ChessVecSptr&, bool);

private:
    const int BA0[10][9] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {90,90,110,120,120,120,110,90,90},
        {90,90,110,120,120,120,110,90,90},
        {70,90,110,110,110,110,110,90,70},
        {70,70,70,70,70,70,70,70,70},
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    };

    const int BA1[10][9] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 70,70,70,70,70,70,70,70,70 },
        { 70,90,110,110,110,110,110,90,70 },
        { 90,90,110,120,120,120,110,90,90 },
        { 90,90,110,120,120,120,110,90,90 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    };

    int basevalue[15];
    int flexvalue[15];

    int getPosValue(QSharedPointer<Chess>);
    int getAssaultedScore(QSharedPointer<Chess>);
};

#endif // SEARCHENGINE_H
