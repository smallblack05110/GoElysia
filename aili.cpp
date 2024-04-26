#include "aili.h"

Aili::Aili(QObject *parent) : QObject(parent)
{
    // 初始化状态
    isJumping = false;
    isRushing = false;
    isTricking = false;
    horispeed = 20;

    // 设置 Aili 对象的矩形大小和图片
    aili_Rect.setWidth(300);
    aili_Rect.setHeight(500);
    QPixmap pixmap(":/beijing/image/aili5.png");
    aili_pixmap = pixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);

    // 初始化定时器，用于控制冲刺动作
    rushTimer.setInterval(1500); // 设置定时器间隔为 1.5 秒
    connect(&rushTimer, &QTimer::timeout, this, &Aili::rush);
}

// 获取 Aili 对象的图片
QPixmap Aili::getPixmap() const
{
    return aili_pixmap;
}

// 获取 Aili 对象的 X 坐标
int Aili::getX() const
{
    return aili_Rect.x();
}

// 获取 Aili 对象的 Y 坐标
int Aili::getY() const
{
    return aili_Rect.y();
}

// 设置 Aili 对象的位置
void Aili::setPosition(int x, int y)
{
    aili_Rect.moveTo(x, y);
}

// 跳跃动作
void Aili::jump()
{
    if (isJumping == false)
    {
        isJumping = true;
        isRushing = true;

        // 切换为跳跃图片
        QPixmap jumpingPixmap(":/beijing/image/ailijumping.png");
        aili_pixmap = jumpingPixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);

        // 获取当前位置和目标位置
        int currentY = aili_Rect.y();
        int targetY = currentY - 300;

        // 创建上升定时器，控制跳跃上升阶段
        QTimer *riseTimer = new QTimer(this);
        connect(riseTimer, &QTimer::timeout, [=]() mutable {
            // 上升一定距离
            currentY -= 23; // 上升速度
            aili_Rect.moveTo(aili_Rect.x(), currentY);

            // 到达目标位置时停止上升定时器，启动下降定时器
            if (currentY <= 179) {
                riseTimer->stop();
                delete riseTimer; // 删除上升定时器对象，释放内存

                // 创建下降定时器，控制跳跃下降阶段
                QTimer *fallTimer = new QTimer(this);
                connect(fallTimer, &QTimer::timeout, [=]() mutable {
                    // 下落一定距离
                    currentY += 23; // 下降速度
                    aili_Rect.moveTo(aili_Rect.x(), currentY);

                    // 到达原始位置时停止下降定时器
                    if (currentY >= 470) {
                        fallTimer->stop();
                        aili_Rect.moveTo(aili_Rect.x(), 470); // 恢复到原始位置
                        delete fallTimer; // 删除下降定时器对象，释放内存
                        isJumping = false;
                        isRushing = false;

                        // 切换回原始图片
                        QPixmap pixmap(":/beijing/image/aili5.png");
                        aili_pixmap = pixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);
                    }
                });

                // 启动下降定时器
                fallTimer->start(40); // 每 40 毫秒下降一次
            }
        });

        // 启动上升定时器
        riseTimer->start(40); // 每 40 毫秒上升一次
    }
}

// 冲刺动作
void Aili::rush()
{
    if (isRushing == false)
    {
        // 修改 Aili 对象的尺寸和图片
        aili_Rect.setHeight(410);
        aili_Rect.setWidth(300);
        QPixmap rushingPixmap(":/beijing/image/ailirushing.png");
        aili_pixmap = rushingPixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);
        aili_Rect.moveTo(50, 570); // 设置位置

        isJumping = true;
        isRushing = true;

        // 在 0.8 秒后恢复原始尺寸和图片
        QTimer::singleShot(800, [=]() {
            aili_Rect.setHeight(500);
            aili_Rect.setWidth(300);
            isJumping = false;
            isRushing = false;
            aili_Rect.moveTo(50, 470); // 恢复位置
            QPixmap pixmap(":/beijing/image/aili5.png");
            aili_pixmap = pixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);
        });
    }
}

// 技能动作
void Aili::trick()
{
    isTricking = true; // 设置为受保护状态
    isJumping = true;
    isRushing = true;

    // 上升阶段
    rise();

    // 8 秒后执行下降动作
    QTimer::singleShot(8000, this, &Aili::fall);
}

// 上升动作
void Aili::rise()
{
    int currentY = aili_Rect.y();
    int targetY = currentY - 300;

    // 创建上升定时器，控制上升阶段
    QTimer *riseTimer = new QTimer(this);
    connect(riseTimer, &QTimer::timeout, [=]() mutable {
        // 计算移动距离，并将 Aili 向上移动
        int deltaY = (currentY - targetY) / 10; // 使上升速度随时间递增
        currentY -= deltaY;
        aili_Rect.moveTo(aili_Rect.x(), currentY);

        // 切换为技能图片
        QPixmap jumpingPixmap(":/beijing/image/ailiTricking.png");
        aili_pixmap = jumpingPixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);

        // 到达目标位置时停止上升定时器
        if (currentY <= 179) {
            riseTimer->stop();
            delete riseTimer;
        }
    });
    riseTimer->start(20); // 每 20 毫秒上升一次
}

// 下降动作
void Aili::fall()
{
    // 初始化位置和目标位置
    int currentY = aili_Rect.y();
    int targetY = 470;
    int deltaY = 30; // 初始下降速度

    // 创建下降定时器，控制下降阶段
    QTimer *fallTimer = new QTimer(this);
    connect(fallTimer, &QTimer::timeout, [=]() mutable {
        // 下落一定距离
        currentY += deltaY;
        aili_Rect.moveTo(aili_Rect.x(), currentY);

        // 切换为技能图片
        QPixmap jumpingPixmap(":/beijing/image/ailiTricking.png");
        aili_pixmap = jumpingPixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);

        // 更新下降速度，使其逐渐减小
        deltaY *= 0.9; // 逐渐减小下降速度
        if (deltaY < 20) {
            deltaY = 20; // 下降速度最小为 1 像素
        }

        // 到达目标位置时停止下降定时器
        if (currentY >= targetY) {
            fallTimer->stop();
            aili_Rect.moveTo(50, 465); // 恢复位置
            QPixmap pixmap(":/beijing/image/aili5.png");
            aili_pixmap = pixmap.scaled(aili_Rect.size(), Qt::KeepAspectRatio);
            isJumping = false;
            isRushing = false;
        }
    });
    fallTimer->start(20); // 每 20 毫秒下降一次
}
