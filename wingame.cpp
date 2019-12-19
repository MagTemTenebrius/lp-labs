#include "wingame.h"
#include "ui_wingame.h"

wingame::wingame(QWidget *parent, QString winners) :
    QDialog(parent),
    ui(new Ui::wingame)
{
    ui->setupUi(this);
    ui->label->setText(winners);
}

wingame::~wingame()
{
    delete ui;
}

void wingame::on_pushButton_clicked()
{
    emit closegame();
}
