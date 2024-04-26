#ifndef AILI_H
#define AILI_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QDateTime>
#include <QDebug>

class Aili : public QObject
{
    Q_OBJECT
public:
    explicit Aili(QObject *parent = nullptr);
    QRect aili_Rect; // Aili 对象的矩形区域
    QPixmap aili_pixmap; // Aili 对象的图片
    void jump(); // 跳跃动作
    void rush(); // 冲刺动作
    void trick(); // 技能动作
    void rise(); // 上升动作
    void fall(); // 下落动作
    QPixmap getPixmap() const; // 获取 Aili 对象的图片
    int getX() const; // 获取 Aili 对象的 X 坐标
    int getY() const; // 获取 Aili 对象的 Y 坐标
    void setPosition(int x, int y); // 设置 Aili 对象的位置
    bool isJumping; // 是否正在跳跃
    bool isRushing; // 是否正在冲刺
    bool isTricking; // 是否正在使用技能
    int horispeed; // 水平速度
    QTimer jumpTimer; // 跳跃计时器
    QTimer rushTimer; // 冲刺计时器
    QTimer trickTimer; // 技能计时器

signals:

};

#endif // AILI_H
