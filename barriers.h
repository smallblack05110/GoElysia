#ifndef BARRIERS_H
#define BARRIERS_H

#include <QObject>
#include <QPixmap>
#include <QDebug>
#include <ctime>

// 抽象基类，定义障碍物的通用行为
class barriers : public QObject
{
    Q_OBJECT
public:
    explicit barriers(QObject *parent = nullptr);
    virtual void updatePosition() = 0; // 更新障碍物位置的纯虚函数
    virtual int ifCollision(QRect) = 0; // 检查是否碰撞的纯虚函数
    virtual bool ifGoOut() = 0; // 检查障碍物是否移出屏幕的纯虚函数
    virtual QPixmap getPixmap() = 0; // 获取障碍物图片的纯虚函数

    int w, h; // 障碍物的宽度和高度
    int speed; // 障碍物的速度
    mutable QPixmap img; // 障碍物图片（mutable 修饰，因为在 const 成员函数中可能需要修改）

    QRect barrier; // 障碍物的矩形边界

signals:

};

// diedPeople 类，表示死士的障碍物
class diedPeople : public barriers
{
public:
    diedPeople();
    virtual void updatePosition(); // 更新障碍物位置
    virtual bool ifGoOut(); // 检查障碍物是否移出屏幕
    virtual int ifCollision(QRect); // 检查是否碰撞
    virtual QPixmap getPixmap(); // 获取障碍物图片
};

// hongkaimonster 类，表示崩坏兽的障碍物
class hongkaimonster : public barriers
{
public:
    hongkaimonster();
    virtual void updatePosition(); // 更新障碍物位置
    virtual int ifCollision(QRect); // 检查是否碰撞
    virtual bool ifGoOut(); // 检查障碍物是否移出屏幕
    virtual QPixmap getPixmap(); // 获取障碍物图片
};

// thirteenheroes 类，表示十三英雄的障碍物
class thirteenheroes : public barriers
{
public:
    thirteenheroes();
    virtual void updatePosition(); // 更新障碍物位置
    virtual int ifCollision(QRect); // 检查是否碰撞
    virtual bool ifGoOut(); // 检查障碍物是否移出屏幕
    virtual QPixmap getPixmap(); // 获取障碍物图片
};

#endif // BARRIERS_H
