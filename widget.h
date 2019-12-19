#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QWidget>
#include <QPainter>
#include <QMoveEvent>

class Widget : public QWidget
{
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QWidget parent;
signals:
    void signalMuvie(QPoint point);
public slots:
protected:
    virtual void paintEvent(QPaintEvent *event);
//    virtual void moveEvent(QMoveEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
//    virtual void dragMoveEvent(QDragMoveEvent *event);
//    virtual void mouseReleaseEvent(QMouseEvent *event);
//    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // WIDGET_H
