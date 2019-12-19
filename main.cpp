#include "graphwidget.h"

#include <QApplication>
#include <QTime>
#include <QMainWindow>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    GraphWidget *widget = new GraphWidget;

    QMainWindow mainWindow;
    mainWindow.setCentralWidget(widget);
//    mainWindow.addToolBarBreak();
//    mainWindow.addToolBar("test");
    mainWindow.show();
    return app.exec();
}
