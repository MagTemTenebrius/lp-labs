#ifndef BOARDVIEW_H
#define BOARDVIEW_H
//
// Created by tenebrius on 9/20/19.
//


#include "Board.h"

class BoardView {
    Board board = 0;
    WinType startGame(int i);
    void show();
};


#endif // BOARDVIEW_H
