#include "first_cham.h"

first_cham::first_cham(QWidget *parent) : QWidget(parent)
{
    currentBackgroundIndex = 0;
    setFixedSize(1400, 900);
    setWindowTitle("冲鸭！粉色妖精小姐！");
    QIcon winicon(":/beijing/image/btn2.png");
    setWindowIcon(winicon);

    // 加载背景图片
    backgrounds.append(QPixmap(":/beijing/image/beijing1.jpg"));
    backgrounds.append(QPixmap(":/beijing/image/beijing2.jpg"));
    backgrounds.append(QPixmap(":/beijing/image/beijing3.webp"));
    backgrounds.append(QPixmap(":/beijing/image/beijing4.jpg"));
    backgrounds.append(QPixmap(":/beijing/image/beijing5.jpg"));


    // 创建定时器并连接槽函数
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &first_cham::changeBackground);
    timer->start(15000); // 15秒触发一次

    // 设置窗口背景
    updateBackground();

    grounds = new Grounds();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &first_cham::updateGround);
    timer->start(50); // 每50毫秒更新一次地面

    ailiObject = new aili(this);
    ailiObject->setPosition(50,470);

    add_Barrier.setInterval(2000);
    add_Barrier.start();
    connect(&add_Barrier,&QTimer::timeout,[=](){
        storeBarriers();
    });
    barrier_timer.setInterval(3500);
    barrier_timer.start();

    updateTimer.setInterval(40);
    updateTimer.start();
    connect(&updateTimer,&QTimer::timeout,[=](){
        updatebarriers();    //更新坐标
//        collisionDetection();  //碰撞检测
        update();          //刷新屏幕
    });

}

first_cham::~first_cham()
{
    // 清理资源
    delete timer;
    delete grounds; // 删除地面对象
    delete ailiObject;
}

void first_cham::changeBackground()
{
    // 更新背景索引
    currentBackgroundIndex = (currentBackgroundIndex + 1) % backgrounds.size();

    // 更新窗口背景
    updateBackground();
}

void first_cham::updateBackground()
{
    // 创建调色板
    QPalette palette;
    // 设置背景图片
    palette.setBrush(backgroundRole(), QBrush(backgrounds[currentBackgroundIndex].scaled(size())));
    // 应用调色板
    setPalette(palette);
    // 自动填充背景
    setAutoFillBackground(true);
}

void first_cham::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // 绘制地面
    for (int i = 0; i < 10; ++i) {
        painter.drawPixmap(grounds->grounds[i].ground_posX, 600, 700, 250, grounds->grounds[i].ground);
    }

    // 绘制 aili
    QPixmap ailiPixmap = ailiObject->getPixmap();
    painter.drawPixmap(ailiObject->getX(), ailiObject->getY(), ailiPixmap);

    // 绘制障碍物
    for (auto& obstacle : barriers) {
//        qDebug() << "Obstacle position:" << obstacle->barrier.topLeft();
           painter.drawPixmap(obstacle->barrier.topLeft(), obstacle->getPixmap());
    }
}
void first_cham::updateGround()
{
    // 更新地面位置
    grounds->calculatePositions();

    // 重新绘制窗口
    update();
}
void first_cham::updatebarriers()
{

    for (int i = 0; i < barriers.size();) {
        if (barriers[i]->ifGoOut())
         {
            delete barriers[i];
            barriers.remove(i);
        } else {
            barriers[i]->updatePosition();
            ++i;
        }
    }
}

void first_cham:: keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_Space) {
            // 启动 aili 的跳跃动作
           ailiObject->jump();
}
    if (event->key() == Qt::Key_Shift) {
        if(ailiObject->isRushing==false)
        {
        for(int i=0;i<10;i++)
            grounds->grounds[i].setScrollSpeed(40);
        for (int i = 0; i < barriers.size();i++)
        {
            barriers[i]->speed=40;
        }

        QTimer::singleShot(800, this, [=]() {
            for(int i = 0; i < 10; ++i) {
                grounds->grounds[i].setScrollSpeed(20); // 将速度恢复到原始值
            }
            for (int i = 0; i < barriers.size();i++)
            {
                barriers[i]->speed=20;
            }

        });
        }
        ailiObject->rush();

       }
}

void first_cham::storeBarriers(){                        //生成障碍物
    srand((unsigned int)time(NULL));
    int i=rand()%2;
    switch (i) {
    case 0:
        barriers.append(new diedPeople);
        break;
    case 1:
        barriers.append(new hongkaimonster);
        break;
    default:
        break;
    }
}