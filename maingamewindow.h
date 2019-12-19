#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QDialog>
#include "qslotwidget.h"
#include "wingame.h"

namespace Ui {
class maingamewindow;
}

class maingamewindow : public QDialog
{
    Q_OBJECT

public:
    int size = 5;
    explicit maingamewindow(QWidget *parent = nullptr);
    ~maingamewindow();

private:
    wingame *closewindow;
    Ui::maingamewindow *ui;
    StepType step = xStep;
    WinType win = none;
//    void ShangeStep();
    bool isWin(CellType cell);

public slots:
    void setStep();
    void closeGame();

};

#endif // MAINGAMEWINDOW_H
