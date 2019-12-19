#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsView>
#include "widget.h"
#include "QGraphicsProxyWidget"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void changeRedElipse(QPoint point);
    void changeGreenElipse(QPoint point);
    void changeBlueElipse(QPoint point);
//    void setX(int idLabel, double x);
//    void setY(int idLabel, double x);
//    void setZ(int idLabel, double x);

private:
    QGraphicsScene* scene;
    QGraphicsEllipseItem *ellipse;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
