#ifndef QSLOTWIDGET_H
#define QSLOTWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QMargins>
#include "EnumList.h"


class QSlotWidget : public QWidget {
    Q_OBJECT
public:
    explicit QSlotWidget(QObject* wind, StepType* step = nullptr, WinType* win = nullptr, QWidget *parent = nullptr);
    ~QSlotWidget();

    QPixmap pixmap(){ return originalImage; }
    int marin() {return margin; }
    void setPixmap(QPixmap pixmap);
    bool setCell(CellType cell);
    CellType getCell();
    
    StepType* step;
    WinType* win;


    
private:
    QPixmap originalImage;
    QString noImageMsg;
    int margin;
    QMargins margins;
    QColor backgroundColor;
    CellType field = empty;
signals:
    void pixmapChanged();
    void marginChanged();
    void stepShanged();

public slots:

    void setMargin(int value);
    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // QSLOTWIDGET_H
