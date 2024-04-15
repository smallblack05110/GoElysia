
#ifndef AILI_H
#define AILI_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QTimer>
class aili : public QObject
{
    Q_OBJECT
public:
    explicit aili(QObject *parent = nullptr);
    QRect aili_Rect;
    QPixmap aili_pixmap;
    void jump();
    void rush();
    QPixmap getPixmap() const;
    int getX() const;
    int getY() const;
    void setPosition(int x,int y);
    bool isJumping;
    bool isRushing;
    int horispeed;
    QTimer jumpTimer;
    QTimer rushTimer;
signals:

};

#endif // AILI_H
