#ifndef BOARD_H
#define BOARD_H

#include "EnumList.h"

class Board {
private:
    int n;
    CellType** field;
public:
    Board(int i);
    void init(int i);
    bool makeMove(int i, int j, CellType sign);
    WinType isWin();
    int getN();
};
#endif // BOARD_H
