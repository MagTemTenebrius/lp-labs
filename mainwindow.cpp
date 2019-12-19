#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    qDebug() << "DDDDDDDDDDDDDDDDDD";



    scene = new QGraphicsScene(this);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);


    ellipse = scene->addEllipse(0, 0, 60, 60, outlinePen, greenBrush);

    ellipse->setFlag(QGraphicsItem::ItemIsMovable);

    ui->graphicsView->setScene(scene);

//    scene.addWidget()
//    scene.addText("Hello, world!");

//    QGraphicsView* view = new QGraphicsView(&scene);

//    ui->graphicsView = view;
//    ui->graphicsView->scene()->addText("Test TEXT");
//    scene =  new QGraphicsScene(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
//    red = new Widget();
//    green = new Widget();
//    blue = new Widget();
//    red_item = scene->addWidget(red);
//    green_item = scene->addWidget(green);
//    blue_item = scene->addWidget(blue);
//    connect(red, SIGNAL(red->signalMuvie(QPoint)), this, SLOT(changeRedElipse(QPoint)));
//    connect(green, SIGNAL(green->signalMuvie(QPoint)), this, SLOT(changeRedElipse(QPoint)));
//    connect(blue, SIGNAL(blue->signalMuvie(QPoint)), this, SLOT(changeRedElipse(QPoint)));
//    item.
//    item->setParentItem(anOtherItem);
//    int x1 = 0;
//    int y1 = -25;

//    int x2 = -200;
//    int y2 = -25;

//    int x3 = 200;
//    int y3 = -25;

//    red_item->setGeometry(QRectF(x1, y1, 50, 50));
//    green_item->setGeometry(QRectF(x2, y2, 50, 50));
//    blue_item->setGeometry(QRectF(x3, y3, 50, 50));
//    scene->addEllipse(QRectF(0,0, 50, 50), QPen(Qt::black), QBrush(Qt::red));
//    item->setZValue(1);
//    scene->update();
//    for(int x = 0; x <= ui->graphicsView->width(); x += 10){
//        scene->addLine(x,0,x,ui->graphicsView->height(),QPen(Qt::green));
//    }
//    for(int y = 0; y <= ui->graphicsView->height(); y += 10){
//        scene->addLine(0,y,ui->graphicsView->width(),y,QPen(Qt::green));
//    }

//    for(int x = 10; x <= ui->graphicsView->width(); x += 100){
//        scene->addLine(x,0,x,ui->graphicsView->height(),QPen(Qt::darkGreen));
//    }

//    for(int y = 10; y <= ui->graphicsView->height(); y += 100){
//        scene->addLine(0,y,ui->graphicsView->width(),y,QPen(Qt::darkGreen));
//    }

//    ui->graphicsView->setScene(scene);

//    ui->graphicsView->repaint();
//    ui->centralwidget->
//    view.show();



//    ui->graphicsView->add
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeRedElipse(QPoint point)
{
//    red_item->setGeometry(QRectF(50, 50, 100, 100));
    scene->update();

    qDebug() << "BBB";
}
void MainWindow::changeGreenElipse(QPoint point)
{

}
void MainWindow::changeBlueElipse(QPoint point)
{

}

