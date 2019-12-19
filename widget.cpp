#include "widget.h"


Widget::Widget(QWidget *parent) : QWidget(parent)
{
    int x = 0;
    x++;
//    return;
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *) {
    QPainter painter;
    painter.setRenderHint(QPainter::Antialiasing);
    painter.save();

    painter.setBrush(Qt::red);
    painter.drawRect(rect());

    painter.restore();

    painter.drawEllipse(0, 0, 50, 50);
//    if(originalImage.isNull()) {
//        painter.drawText(rect(), Qt::AlignCenter, noImageMsg);
//    }

}

//void Widget::moveEvent(QMoveEvent *event)
//{
//    qDebug() << "MMMM";
//}

void Widget::mousePressEvent(QMouseEvent *event) {
    qDebug() << "RRRRRRRR";
    QPoint point = event->pos();
//    QPoint oldpoint = event->oldPos();
//    QPoint newPoint = point - oldpoint;
//    emit signalMuvie(point);

}

//void Widget::dragMoveEvent(QDragMoveEvent *event)
//{
//    qDebug() << "KKKK";

//}


//void Widget::mousePressEvent(QMouseEvent *event) {

//    if(event->button() != Qt::LeftButton)
//            return;
//    event->
//    if(*(win) != none) return;
//    if(field!=empty) return;
//    if(*(step) == xStep) {
//        field = krestik;
//        setPixmap(QPixmap("/home/tenebrius/Univer/LP/labs/2_1/GomoKu/img/krestik.png"));
//        *(step) = nStem;
//        emit stepShanged();
//        return;
//    }
//    if(*(step) == nStem) {
//        field = nolik;
//        setPixmap(QPixmap("/home/tenebrius/Univer/LP/labs/2_1/GomoKu/img/nolik.png"));
//        *(step) = xStep;
//        emit stepShanged();
//        return;
//    }
//    return;
//}
