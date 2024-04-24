
#include "aili.h"

aili::aili(QObject *parent) : QObject(parent)
{
    isJumping=false;
    isRushing=false;
    isTricking=false;
    horispeed=20;
    aili_Rect.setWidth(300);
    aili_Rect.setHeight(500);
    QPixmap pixmap(":/beijing/image/aili5.png");
    aili_pixmap = pixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);
    // 初始化定时器
    rushTimer.setInterval(1500); // 设置定时器间隔为 1.5 秒
    connect(&rushTimer, &QTimer::timeout, this, &aili::rush);

}
QPixmap aili::getPixmap() const
{
    return aili_pixmap;
}
int aili::getX() const
{
    return aili_Rect.x();
}
int aili::getY() const
{
    return aili_Rect.y();
}
void aili::setPosition(int x, int y)
{
    aili_Rect.moveTo(x, y);
}
void aili::jump()
{
    if(isJumping==false)
 {
    isJumping=true;
    isRushing=true;
    QPixmap jumpingPixmap(":/beijing/image/ailijumping.png");
    aili_pixmap = jumpingPixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);

    // 获取当前位置
    int currentY = aili_Rect.y();

    // 计算目标位置（向上移动 300 个像素）
    int targetY = currentY - 300;

    // 创建一个定时器，用于控制跳跃动作的上升阶段
    QTimer *riseTimer = new QTimer(this);
    connect(riseTimer, &QTimer::timeout, [=]() mutable {
        // 将 aili 向上移动一定距离
        currentY -= 23; // 每次移动 23 个像素
        aili_Rect.moveTo(aili_Rect.x(), currentY);

        // 当 aili 达到目标位置时，停止上升定时器并启动下降定时器
        if (currentY <= targetY) {
            riseTimer->stop();
            delete riseTimer; // 删除上升定时器对象，释放内存

            // 创建下降定时器
            QTimer *fallTimer = new QTimer(this);
            connect(fallTimer, &QTimer::timeout, [=]() mutable {
                // 将 aili 向下移动一定距离
                currentY += 23; // 每次移动 23 个像素
                aili_Rect.moveTo(aili_Rect.x(), currentY);

                // 当 aili 回到原位置时，停止下降定时器
                if (currentY >= 470) {
                    fallTimer->stop();
                    aili_Rect.moveTo(aili_Rect.x(), 470); // 将 aili 恢复到原位置
                    delete fallTimer; // 删除下降定时器对象，释放内存
                    isJumping=false;
                    isRushing=false;
                }
                QPixmap pixmap(":/beijing/image/aili5.png");
                aili_pixmap = pixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);

            });

            // 启动下降定时器，控制下降动作
            fallTimer->start(40); // 每 40 毫秒移动一次
        }


    });

    // 启动上升定时器，控制上升动作
    riseTimer->start(40); // 每 40 毫秒移动一次
}
}
void aili::rush()
{
    if(isRushing==false)
{
    aili_Rect.setHeight(410);
     aili_Rect.setWidth(300);
     QPixmap rushingPixmap(":/beijing/image/ailirushing.png");
     aili_pixmap = rushingPixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);
     aili_Rect.moveTo(50,570);
    isJumping=true;
    isRushing=true;
        // 创建定时器，用于在 0.8 秒后恢复矩形的原始大小
        QTimer::singleShot(800, [=]() {
            // 恢复矩形的原始高度
            aili_Rect.setHeight(500);
            aili_Rect.setWidth(300);
            isJumping=false;
            isRushing=false;
            aili_Rect.moveTo(50,470);
            QPixmap pixmap(":/beijing/image/aili5.png");
            aili_pixmap = pixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);
        });
}
}

void aili::trick()
{
    isTricking = true; // 设置为受保护状态
        isJumping = true;
        isRushing = true;

        // 上升阶段
        rise();

        // 启动定时器，8秒后执行下降动作
        QTimer::singleShot(8000, this, &aili::fall);
}

void aili::rise()
{
    int currentY = aili_Rect.y();
        int targetY = currentY - 300;

        // 创建一个定时器，用于控制跳跃动作的上升阶段
        QTimer *riseTimer = new QTimer(this);
        connect(riseTimer, &QTimer::timeout, [=]() mutable {
            // 计算移动距离，并将 aili 向上移动
            int deltaY = (currentY - targetY) / 10; // 使上升速度随时间递增
            currentY -= deltaY;
            aili_Rect.moveTo(aili_Rect.x(), currentY);
            QPixmap jumpingPixmap(":/beijing/image/ailiTricking.png");
            aili_pixmap = jumpingPixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);

            // 当 aili 达到目标位置时，停止上升定时器
            if (currentY <= 179) {
                riseTimer->stop();
               delete riseTimer;
            }
        });
        riseTimer->start(20); // 每 20 毫秒移动一次
}
void aili::fall()
{
    // 初始化当前位置和目标位置
    int currentY = aili_Rect.y();
    int targetY = 470;
    int deltaY = 30; // 初始下降速度

    // 创建下降动作的定时器
    QTimer *fallTimer = new QTimer(this);
    connect(fallTimer, &QTimer::timeout, [=]() mutable {
        // 将 aili 向下移动
        currentY += deltaY;
        aili_Rect.moveTo(aili_Rect.x(), currentY);
        QPixmap jumpingPixmap(":/beijing/image/ailiTricking.png");
        aili_pixmap = jumpingPixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);

        // 更新下降速度，使其逐渐减小
        deltaY *= 0.9; // 逐渐减小下降速度
        if (deltaY < 20) {
            deltaY = 20; // 下降速度最小为 1 像素
        }

        // 当 aili 回到原位置时，停止下降定时器
        if (currentY >= targetY) {
            fallTimer->stop();
            delete fallTimer; // 删除下降定时器对象，释放内存
            isJumping = false;
            isRushing = false;
            aili_Rect.moveTo(50,465);
            QPixmap pixmap(":/beijing/image/aili5.png");
            aili_pixmap = pixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);
//            isTricking=false;
        }
    });

    // 更新 pixmap 显示为跳跃状态

    fallTimer->start(20); // 每 20 毫秒移动一次

}
