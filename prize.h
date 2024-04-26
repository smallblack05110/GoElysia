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
    QPushButton *closeButton;

signals:

};

#endif // PRIZE_H
