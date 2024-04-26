#include "ground.h"

Ground::Ground()
{
    ground.load(":/beijing/image/ground1.png"); // 加载地面图片
    ground = ground.scaled(700,300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation); // 设置地面小为 700x300，并进行平滑缩放
    ground_posX = -31; // 初始 X 坐标
    ground_scroll_speed = 20; // 滚动速度为 20 像素每秒
}

void Ground::calculatePosition()
{
    ground_posX -= ground_scroll_speed; // 根据滚动速度计算新的 X 坐标
}

Grounds::Grounds()
{
    for (int i = 0; i < 10; ++i) {
        // 设置每个地面对象的初始 X 坐标
        grounds[i].ground_posX += 700 * i;
    }
}

void Grounds::calculatePositions()
{
    for (int i = 0; i < 10; ++i) {
        grounds[i].calculatePosition(); // 计算每个地面对象的位置

        // 如果地面对象超出左边界，将其移动到最右边，从而实现循环效果
        if (grounds[i].ground_posX <= -grounds[i].ground.width()) {
            grounds[i].ground_posX += 700 * 9;
            distance += 5; // 更新距离
        }
    }
}

//重新设置地面的滚动速度
void Ground::setScrollSpeed(int speed)
{
    ground_scroll_speed = speed;
}
