
#ifndef AILI_H
#define AILI_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
class aili : public QObject
{
    Q_OBJECT
public:
    explicit aili(QObject *parent = nullptr);
    QRect aili_Rect;
    QPixmap aili_pixmap;
    void jump();
    void rush();
    void trick();
    void rise();
    void fall();
    QPixmap getPixmap() const;
    int getX() const;
    int getY() const;
    void setPosition(int x,int y);
    bool isJumping;
    bool isRushing;
    bool isTricking;
    int horispeed;
    QTimer jumpTimer;
    QTimer rushTimer;
    QTimer trickTimer;
signals:

};

#endif // AILI_H
