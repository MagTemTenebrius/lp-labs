#include "qslotwidget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>
#include "maingamewindow.h"

QSlotWidget::QSlotWidget(QObject* wind, StepType* step, WinType* win, QWidget *parent) : QWidget(parent), step(step),win(win) {
    noImageMsg = "";
    backgroundColor = Qt::color0;

    connect(this, SIGNAL(marginChanged()), SLOT(repaint()));
    connect(this, SIGNAL(pixmapChanged()), SLOT(repaint()));

}
QSlotWidget::~QSlotWidget() {

}

void QSlotWidget::setPixmap(QPixmap pixmap) {
    originalImage = pixmap;
    emit pixmapChanged();
}

void QSlotWidget::setMargin(int value) {
    if(value < 0)
        value = 0;

    margin = value;
    emit marginChanged();
}

bool QSlotWidget::setCell(CellType cell) {
    if(this->field != empty)
        return false;
    else {
        this->field = cell;
    }
    return true;
}
CellType QSlotWidget::getCell() {
    return this->field;
}

void QSlotWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.save();

//    painter.setBrush(backgroundColor);
    painter.drawRect(rect());

    painter.restore();
    if(originalImage.isNull()) {
        painter.drawText(rect(), Qt::AlignCenter, noImageMsg);
    } else {
        QRect imageRect = rect();
        painter.drawPixmap(imageRect, originalImage);
    }

}


void QSlotWidget::mousePressEvent(QMouseEvent *event){
    if(event->button() != Qt::LeftButton)
            return;
//    event->
    if(*(win) != none) return;
    if(field!=empty) return;
    if(*(step) == xStep) {
        field = krestik;
        setPixmap(QPixmap("/home/tenebrius/Univer/LP/labs/2_1/GomoKu/img/krestik.png"));
        *(step) = nStem;
        emit stepShanged();
        return;
    }
    if(*(step) == nStem) {
        field = nolik;
        setPixmap(QPixmap("/home/tenebrius/Univer/LP/labs/2_1/GomoKu/img/nolik.png"));
        *(step) = xStep;
        emit stepShanged();
        return;
    }
    return;
}
