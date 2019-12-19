#include <iostream>
#include "ConsoleGraphic.h"

//Board, BoardView

using namespace std;

// Board зависит от BV

enum CellType {
    none = 0, x = 1, o = 2
};

enum WinType {
    nowin = 0, draw = 1, xwin = 2, owin = 3
};

class BoardView {
    CellType* cells;
    int n;
public:
    BoardView(CellType * cells, int n) {
        this->cells = cells;
        this->n = n;
    }
    void show() {
        for(int i = 0; i < n; i++) {
            cout << " " << i;
        }
        for(int i = 0; i < n; i++) {
            cout << endl << i;
            for(int j = 0; j < n; j++) {
                cout << " " << (cells[i*n+j]? (cells[i*n+j] == 1 ? 'X' : 'O') : ' ');
            }
        }
    }
};

class Board {
    CellType * cells;
    WinType winner = nowin;
    BoardView* bv;
    CellType first_step;
    int n;
    int number;
public:
    Board(int n, CellType cell) {
        this->n = n;
        first_step = cell;
        cells = new CellType[n*n];
        for(int i = 0; i < n*n; i++) {
            cells[i] = CellType(0);
        }
        bv = new BoardView(cells, n);
    }
    // i - str
    // j - col
    int getij(int i, int j){
        return cells[i*n+j];
    }
    bool setij(int i, int j, CellType cell) {
        cells[i*n+j] = cell;
    }
    int geti(int i){
        return cells[i];
    }

    void show() {
        cout << endl;
        bv->show();
        cout << endl;
    }

    void step() {
        int x0, y0;
        cin >> x0;
        cin >> y0;
        if(x0>=n || y0>=n) {
            cout << endl << "bad index!";
            step();
            return;
        }
        if(getij(x0, y0) != 0){
            cout << endl << "cell is't empty!";
            step();
            return;
        }
        setij(x0, y0, number%2==0? (first_step==x?x:o) : (first_step==x?o:x));
        number++;
    }

    bool isWin() {
        int empt = 0;
        CellType selectCell = none;
        for(int j = 0; j < n*n; j++) {
            if(selectCell!=(getij(j/n,j%n))) {
                empt=1;
            } else {
                empt=0;
                break;
            }
        }
        if(empt==1) {
            winner = draw;
            return true;
        }
        for(int i = 0; i < n; i++){
            selectCell = CellType(getij(i, 0));
            bool isWiner = true;
            for(int j = 0; j < n; j++) {
                if(selectCell!=CellType(getij(i, j))) {
                    isWiner = false;
                    break;
                }
            }
            if(isWiner && selectCell!=none) {
                winner = selectCell == x ? xwin : owin;
                return true;
            }
        }
        for(int i = 0; i < n; i++){
            selectCell = CellType (getij(0, i));
            bool isWiner = true;
            for(int j = 0; j < n; j++){
                if(selectCell!=CellType (getij(j, i))) {
                    isWiner = false;
                    break;
                }
            }
            if(isWiner && selectCell!=none) {
                winner = selectCell == x ? xwin : owin;
                return true;
            }
        }
        selectCell = CellType (getij(0, 0));
        bool isWiner = true;
        for(int i = 0; i < n; i++){
            if(selectCell!=CellType (getij(i, i))) {
                isWiner = false;
                break;
            }
        }
        if(isWiner && selectCell!=none) {
            winner = selectCell == x ? xwin : owin;
            return true;
        }
        selectCell = CellType (getij(n-1, 0));
        isWiner = true;
        for(int i = 0; i < n; i++){
            if(selectCell!=CellType (getij(n-i-1, i))) {
                isWiner = false;
                break;
            }
        }
        if(isWiner && selectCell!=none) {
            winner = selectCell == x ? xwin : owin;
            return true;
        }
        return false;
    }

    void result() {
        cout << endl << endl << endl
        << "=============================" << endl
        << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl
        << "         " << whoWin() << " is win!" << endl
        << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl
        << "=============================" << endl;
    }

    string whoWin(){
        switch (winner) {
            case nowin:
                return " ";
            case draw:
                return "Friends";
            case xwin:
                return "X";
            case owin:
                return "O";
        }
    }
    string whoStep(){
        switch (number%2) {
            case 0:
                return "X";
            case 1:
                return "O";
        }
    }
};

int main() {
    int n = 3;
    CellType first_step = x;
    while(true) {
        cout << endl
             << "Main menu:" << endl
             << "==========================" << endl
            << "s = start game" << endl
            << "o = options game" << endl
            << "e = exit" << endl
        << "==========================" << endl;
        char select;
        cin >> select;
        if(select != 's' && select != 'o' && select != 'e') {
            cout << "bad index";
            continue;
        }
        switch (select) {
            case 's': {
                Board board(n, first_step);
                while (true) {
                    cout << endl << board.whoStep() << " your turn!" << endl;
                    board.show();
                    board.step();
                    if(board.isWin()) {
                        clrscr();
                        board.show();
                        board.result();
                        break;
                    }
                }
                break;
            }
            case 'o':
                while(true) {
                    cout << "Optiond list:" << endl
                    << "==========================" << endl
                    << "s (size = " << n << " ) = change size" << endl
                    << "f (first player = " << (first_step == 1 ? 'x' : '0') << " ) = change ferst player" << endl
                    << "e = exit" << endl
                    << "==========================" << endl;
                    bool exit = false;
                    char select_;
                    cin >> select_;
                    if(select_ != 's' && select_ != 'f' && select_ != 'e') {
                        cout << "bad index" << endl;
                        continue;
                    }
                    switch (select_) {
                        case 's': {
                            cout << "Print new size" << endl;
                            int newsize = 1;
                            cin >> newsize;
                            if(newsize <=1 || newsize > 30) {
                                cout << "bad number" << endl;
                                break;
                            }
                            n = newsize;
                            cout << "Set new size is compl!" << endl;
                            break;

                        }
                        case 'f': {
                            first_step = first_step == x ? o : x;
                            cout << "Set new ferst player is compl!" << endl;
                            break;

                        }
                        case 'e':
                            exit = true;
                            break;
                    }
                    if(exit) break;
                }
                break;
            case 'e':
                return 0;
        }
        system("pause");
    }
    return 0;
}