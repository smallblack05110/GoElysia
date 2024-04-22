#ifndef BARRIERS_H
#define BARRIERS_H

#include <QObject>
#include <QPixmap>
#include <QDebug>
#include <ctime>
class barriers : public QObject
{
    Q_OBJECT
public:
    explicit barriers(QObject *parent = nullptr);
    virtual void updatePosition()=0;
    virtual int ifCollision(QRect)=0;
    virtual bool ifGoOut()=0;
    virtual QPixmap getPixmap()=0;
    int w, h;
    int speed;
    mutable QPixmap img; // 将 img 修改为 mutable
    QRect barrier;

signals:

};

class diedPeople : public barriers
{
public:
    diedPeople();
    virtual void updatePosition();
    virtual bool ifGoOut();
    virtual int ifCollision(QRect);
    virtual QPixmap getPixmap();
};

class hongkaimonster : public barriers
{
public:
    hongkaimonster();
    virtual void updatePosition();
    virtual int ifCollision(QRect);
    virtual bool ifGoOut();
    virtual QPixmap getPixmap();
};
class thirteenheroes : public barriers
{
public:
    thirteenheroes();
    virtual void updatePosition();
    virtual int ifCollision(QRect);
    virtual bool ifGoOut();
    virtual QPixmap getPixmap();
};
#endif // BARRIERS_H
