#ifndef GROUND_H
#define GROUND_H

#include <QPixmap>
#include <QRect>

// 地面基类
class Ground
{
public:
    Ground(); // 构造函数
    void calculatePosition(); // 计算位置

public:
    QPixmap ground; // 地面图片对象
    int ground_posX; // 地面 X 坐标
    int ground_scroll_speed; // 地面滚动速度
    void setScrollSpeed(int speed);
};

// 将地面连起来，实现滚动效果
class Grounds
{
public:
    Grounds();
    void calculatePositions(); // 计算多个地面位置

public:
    Ground grounds[10]; // 存储多个地面对象的数组
    int distance; // 距离
};

#endif // GROUND_H
