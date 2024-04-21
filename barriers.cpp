#include "barriers.h"

barriers::barriers(QObject *parent) : QObject(parent)
{
   speed=20;
}
diedPeople::diedPeople()
{
    std::time_t currentTime = std::time(nullptr);
        // 将当前时间作为种子传递给随机数生成函数
        std::srand(static_cast<unsigned int>(currentTime));
        // 生成一个随机数，范围在 0 到 2 之间
        int randomNumber = std::rand() % 3;
        // 根据随机数选择对应的图片
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
            // 默认情况，不做任何操作
            break;
        }
        w=1400;
        h=470;
        barrier.setWidth(150);
        barrier.setHeight(300);
        img = img.scaled(barrier.size(), Qt::KeepAspectRatio);

        barrier.moveTo(w+20,h+100);
}
void diedPeople::updatePosition(){
    w-=speed;
    barrier.moveTo(w+20,h+100);
}
bool diedPeople::ifGoOut()
{
    return w<-img.width();
}
QPixmap diedPeople::getPixmap()
{
    return img;
}

int diedPeople::ifCollision(QRect r) {
    // 调整矩形的宽度和高度
    QRect adjustedRect(r.x() + 250, r.y()+300, r.width() - 250, r.height()-400);
    // 调整 barrier 的大小和位置
    QRect adjustedRect2(barrier.x()+100,barrier.y()+200, barrier.width() - 100, barrier.height()-200);
    // 进行相交检测
    if (adjustedRect2.intersects(adjustedRect)) {
        return 1; // 相交
    } else {
        return 0; // 不相交
    }
}
hongkaimonster::hongkaimonster()
{
    std::time_t currentTime = std::time(nullptr);
        // 将当前时间作为种子传递给随机数生成函数
        std::srand(static_cast<unsigned int>(currentTime));
        // 生成一个随机数，范围在 0 到 2 之间
        int randomNumber = std::rand() % 4;
        // 根据随机数选择对应的图片
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
            // 默认情况，不做任何操作
            break;
        }
        w=1400;
        h=470;
        barrier.setWidth(300);
        barrier.setHeight(450);
        img = img.scaled(barrier.size(), Qt::KeepAspectRatio);
        barrier.moveTo(w+50,h-170);
}
void hongkaimonster::updatePosition(){
    w-=speed;
    barrier.moveTo(w+50,h-200);
}
bool hongkaimonster::ifGoOut()
{
    return w<-img.width();
}
QPixmap hongkaimonster::getPixmap()
{
    return img;
}
int hongkaimonster::ifCollision(QRect r) {
    // 调整矩形的宽度和高度
    QRect adjustedRect(r.x() + 250, r.y()+400, r.width() - 250, r.height()-400);
    qDebug() << "Adjusted Rectangle 1:" << adjustedRect; // 输出调整后的矩形1的位置和大小
    // 调整 barrier 的大小和位置
    QRect adjustedRect2(barrier.x()+280,barrier.y(), barrier.width() - 280, barrier.height()+220);
     qDebug() << "Adjusted Rectangle 2:" << adjustedRect; // 输出调整后的矩形1的位置和大小
    // 进行相交检测
    if (adjustedRect2.intersects(adjustedRect)) {
        return 1; // 相交
    } else {
        return 0; // 不相交
    }
}
