#include "maingamewindow.h"
#include "ui_maingamewindow.h"
#include "mainwindow.h"
#include <iostream>


QSlotWidget*** pole;

maingamewindow::maingamewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maingamewindow)
{
    ui->setupUi(this);

    pole = new QSlotWidget**[size];
    for(int i = 0; i < size; i++) {
        pole[i] = new QSlotWidget*[size];
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
//            void(*adr)();
//            adr = setStep;
            pole[i][j] = new QSlotWidget(this, &step, &win);
            ui->gridLayout->addWidget(pole[i][j], i, j);
            connect(ui->gridLayout, SIGNAL(valueChanged(int)),
                    pole[i][j], SLOT(setMargin(int)));
            QObject::connect(pole[i][j], &QSlotWidget::stepShanged, this, &maingamewindow::setStep);
        }
    }
}

void maingamewindow::setStep(){
//    this->hide();
    int empt = 0;
    CellType selectCell = empty;
    for(int j = 0; j < size*size; j++) {
        if(selectCell!=(pole[j/3][j%3])->getCell()) {
            empt=1;
        } else {
            empt=0;
            break;
        }
    }
    if(empt==1) {
        isWin(empty);
    }
    bool isWiner = true;
    // Строки
    for(int i = 0; i < size; i++){
        selectCell = pole[i][0]->getCell();
        isWiner = true;
        for(int j = 0; j < size; j++) {
            if(selectCell!=pole[i][j]->getCell()) {
                isWiner = false;
                break;
            }
        }
        if(isWiner && selectCell!=empty) {
            isWin(selectCell);
        }
    }
    // Вертикально
    for(int i = 0; i < size; i++){
        selectCell = pole[0][i]->getCell();
        isWiner = true;
        for(int j = 0; j < size; j++){
            if(selectCell!=pole[j][i]->getCell()) {
                isWiner = false;
                break;
            }
        }
        if(isWiner && selectCell!=empty) {
            isWin(selectCell);
        }
    }
    // Диаг.
    selectCell = pole[0][0]->getCell();
    isWiner = true;
    for(int i = 0; i < size; i++){
        if(selectCell!=pole[i][i]->getCell()) {
            isWiner = false;
            break;
        }
    }
    if(isWiner && selectCell!=empty) {
        isWin(selectCell);
    }
    selectCell = pole[size-1][0]->getCell();
    isWiner = true;
    for(int i = 0; i < size; i++){
        if(selectCell!=pole[size-i-1][i]->getCell()) {
            isWiner = false;
            break;
        }
    }
    if(isWiner && selectCell!=empty) {
        isWin(selectCell);
    }

    return;
}

maingamewindow::~maingamewindow() {
    delete ui;
}

void maingamewindow::closeGame() {
    close();
    closewindow->close();
}

bool maingamewindow::isWin(CellType cell) {
    if(cell == empty) {
        win = draw;
        closewindow = new wingame(this, "Победила дружба!");
    }
    if(cell == xStep) {
        win = xWin;
        closewindow = new wingame(this, "Победили крестики!");
    }
    if(cell == nStem) {
        win = nWin;
        closewindow = new wingame(this, "Победили нолики!");
    }
    closewindow->show();
    QObject::connect(closewindow, &wingame::closegame, this, &maingamewindow::closeGame);
    return false;
}
//void maingamewindow::ShangeStep() {
//    if(isWin()) step = non;
//    if(step == xStep)
//        return;
//}
