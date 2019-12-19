#ifndef WINGAME_H
#define WINGAME_H

#include <QDialog>
#include <QString>

namespace Ui {
class wingame;
}

class wingame : public QDialog
{
    Q_OBJECT

public:
    explicit wingame(QWidget *parent = nullptr, QString winners = nullptr);
    ~wingame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::wingame *ui;

signals:
    void closegame();

};

#endif // WINGAME_H
