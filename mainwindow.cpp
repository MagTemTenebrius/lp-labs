#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    QPushButton *button = new QPushButton();
    button->setText("Buttom");
    QLabel *lab = new QLabel("Label");
    lab->setAlignment(Qt::AlignCenter);

    status = ui->label_3;



    status->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    label_x_y = ui->label;
    button_x_y = ui->label_2;




    TContainer *con1 = new TContainer(this, QPoint(100, 10), status, label_x_y, lab);

    connect(con1, &TContainer::MOVED, this, [&]() {
        status->setText(QString("Label move"));
    });
    connect(con1, &TContainer::RESIZE, this, [&]() {
        status->setText(QString("Label Resize"));
    });
    connect(con1, &TContainer::STOPED, this, [&]() {
        status->setText(QString("Stoit"));
    });

    TContainer *con2 = new TContainer(this, QPoint(100, 50), status, button_x_y, button);


    connect(con2, &TContainer::MOVED, this, [&]() {
        status->setText(QString("button move"));
    });
    connect(con2, &TContainer::RESIZE, this, [&]() {
        status->setText(QString("button Resize"));
    });
    connect(con2, &TContainer::STOPED, this, [&]() {
        status->setText(QString("Stoit"));
    });

    label_x_y->setText(
                      QString::number(con1->pos().x()) + QString(", ") + QString::number(con1->pos().y())
                   );

    button_x_y->setText(
                      QString::number(con2->pos().x()) + QString(", ") + QString::number(con2->pos().y())
                   );
    label_x_y->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    button_x_y->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    status->setText(QString("Stoit"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

