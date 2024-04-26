#ifndef PRIZE_H
#define PRIZE_H

#include <QWidget>
#include <QIcon>
#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QPainter>

//本功能未完全实现，所以不给出注释
class Prize : public QWidget
{
    Q_OBJECT
public:
    explicit Prize(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void closeWindow();
    QLabel *titleLabel;
    QLabel *Prize1;
    QLabel *Prize1text;
    QLabel *Prize1exp;
    QLabel *Prize2;
    QLabel *Prize2text;
    QLabel *Prize2exp;
    QLabel *Prize3;
    QLabel *Prize3text;
    QLabel *Prize3exp;
    QLabel *Prize4;
    QLabel *Prize4text;
    QLabel *Prize4exp;
    QLabel *Prize5;
    QLabel *Prize5text;
    QLabel *Prize5exp;
    QPushButton *closeButton;

signals:

};

#endif // PRIZE_H
