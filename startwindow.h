#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "first_cham.h"
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QPixmap>
#include <QHBoxLayout>
#include <QLineEdit>
class startwindow : public QWidget
{
    Q_OBJECT
public:
    explicit startwindow(QWidget *parent = nullptr);
    QPushButton *letu;
    QPushButton *yezhicheng;
    QPushButton *return1;
    first_cham fir;
    void onReturnclicked();
    void onFirstclicked();
    void showStartWindow();
    void paintEvent(QPaintEvent *event);
    ~startwindow();

signals:

};

#endif // STARTWINDOW_H

