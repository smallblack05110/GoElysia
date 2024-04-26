#include "barriers.h"

// barriers 类的构造函数
barriers::barriers(QObject *parent) : QObject(parent)
{
    speed = 20; // 初始化速度为 20
}

// diedPeople 类的构造函数
diedPeople::diedPeople()
{
    // 生成随机种子
    std::time_t currentTime = std::time(nullptr);
    std::srand(static_cast<unsigned int>(currentTime));

    // 随机选择图片
    int randomNumber = std::rand() % 3;
    switch (randomNumber)
    {
    case 0:
        img.load(":/beijing/image/diedpeople1.png");
        break;
    case 1:
        img.load(":/beijing/image/diedpeople2.png");
        break;
    case 2:
        img.load(":/beijing/image/diedpeople3.png");
        break;
    default:
        break;
    }

    // 初始化位置和大小
    w = 1400;
    h = 470;
    barrier.setWidth(150);
    barrier.setHeight(300);
    img = img.scaled(barrier.size(), Qt::KeepAspectRatio);
    barrier.moveTo(w + 20, h + 100);
}

// 更新 diedPeople 障碍物的位置
void diedPeople::updatePosition()
{
    w -= speed;
    barrier.moveTo(w + 20, h + 100);
}

// 判断 diedPeople 是否移出屏幕
bool diedPeople::ifGoOut()
{
    return w < -img.width();
}

// 获取 diedPeople 障碍物的图片
QPixmap diedPeople::getPixmap()
{
    return img;
}

// 判断 diedPeople 是否与玩家发生碰撞
int diedPeople::ifCollision(QRect r)
{
    // 调整矩形边界
    QRect adjustedRect(r.x() + 220, r.y() + 300, r.width() - 220, r.height() - 400);
    QRect adjustedRect2(barrier.x() + 70, barrier.y() + 200, barrier.width() - 70, barrier.height() - 190);

    // 进行碰撞检测
    if (adjustedRect2.intersects(adjustedRect)) {
        return 1; // 碰撞
    } else {
        return 0; // 未碰撞
    }
}

// hongkaimonster 类的构造函数
hongkaimonster::hongkaimonster()
{
    // 生成随机种子
    std::time_t currentTime = std::time(nullptr);
    std::srand(static_cast<unsigned int>(currentTime));

    // 随机选择图片
    int randomNumber = std::rand() % 4;
    switch (randomNumber)
    {
    case 0:
        img.load(":/beijing/image/hongkaimonster1.png");
        break;
    case 1:
        img.load(":/beijing/image/hongkaimonster2.png");
        break;
    case 2:
        img.load(":/beijing/image/hongkaimonster3.png");
        break;
    case 3:
        img.load(":/beijing/image/hongkaimonster4.png");
        break;
    default:
        break;
    }

    // 初始化位置和大小
    w = 1400;
    h = 470;
    barrier.setWidth(300);
    barrier.setHeight(450);
    img = img.scaled(barrier.size(), Qt::KeepAspectRatio);
    barrier.moveTo(w + 50, h - 170);
}

// 更新 hongkaimonster 障碍物的位置
void hongkaimonster::updatePosition()
{
    w -= speed;
    barrier.moveTo(w + 50, h - 200);
}

// 判断 hongkaimonster 是否移出屏幕
bool hongkaimonster::ifGoOut()
{
    return w < -img.width();
}

// 获取 hongkaimonster 障碍物的图片
QPixmap hongkaimonster::getPixmap()
{
    return img;
}

// 判断 hongkaimonster 是否与玩家发生碰撞
int hongkaimonster::ifCollision(QRect r)
{
    // 调整矩形边界
    QRect adjustedRect(r.x() + 250, r.y() + 400, r.width() - 180, r.height() - 400);
    QRect adjustedRect2(barrier.x() + 280, barrier.y() - 300, barrier.width() - 280, barrier.height() + 520);

    // 进行碰撞检测
    if (adjustedRect2.intersects(adjustedRect)) {
        return 1; // 碰撞
    } else {
        return 0; // 未碰撞
    }
}

// thirteenheroes 类的构造函数
thirteenheroes::thirteenheroes()
{
    // 生成随机种子
    std::time_t currentTime = std::time(nullptr);
    std::srand(static_cast<unsigned int>(currentTime));

    // 随机选择图片
    int randomNumber = std::rand() % 6;
    switch (randomNumber)
    {
    case 0:
        img.load(":/beijing/image/thirteenheroes1.png");
        break;
    case 1:
        img.load(":/beijing/image/thirteenheroes2.png");
        break;
    case 2:
        img.load(":/beijing/image/thirteenheroes3.png");
        break;
    case 3:
        img.load(":/beijing/image/thirteenheroes4.png");
        break;
    case 4:
        img.load(":/beijing/image/thirteenheroes5.png");
        break;
    default:
        break;
    }

    // 初始化位置和大小
    w = 1400;
    h = 470;
    barrier.setWidth(300);
    barrier.setHeight(500);
    img = img.scaled(barrier.size(), Qt::KeepAspectRatio);
    barrier.moveTo(w + 30, h);
}

// 更新 thirteenheroes 障碍物的位置
void thirteenheroes::updatePosition()
{
    w -= speed;
    barrier.moveTo(w + 30, h);
}

// 判断 thirteenheroes 是否移出屏幕
bool thirteenheroes::ifGoOut()
{
    return w < -img.width();
}

// 获取 thirteenheroes 障碍物的图片
QPixmap thirteenheroes::getPixmap()
{
    return img;
}

// 判断 thirteenheroes 是否与玩家发生碰撞
int thirteenheroes::ifCollision(QRect r)
{
    // 调整矩形边界
    QRect adjustedRect(r.x() + 250, r.y() + 400, r.width() - 180, r.height() - 400);
    QRect adjustedRect2(barrier.x() + 250, barrier.y() + 400, barrier.width() - 180, barrier.height() - 400);

    // 进行碰撞检测
    if (adjustedRect2.intersects(adjustedRect)) {
        return 2; // 碰撞
    } else {
        return 0; // 未碰撞
    }
}
