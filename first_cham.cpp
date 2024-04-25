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
    backgrounds.append(QPixmap(":/beijing/image/beijing2.png"));
    backgrounds.append(QPixmap(":/beijing/image/beijing3.webp"));
    backgrounds.append(QPixmap(":/beijing/image/beijing4.jpg"));
    backgrounds.append(QPixmap(":/beijing/image/beijing5.jpg"));
    updateBackground();

    // 创建定时器并连接槽函数

    updatebackgroundTimer.setInterval(15000);
    connect(&updatebackgroundTimer, &QTimer::timeout, this, &first_cham::changeBackground);
    updatebackgroundTimer.start(15000); // 15秒触发一次
    add_Barrier.setInterval(2000);
    connect(&add_Barrier,&QTimer::timeout,[=](){
        storeBarriers();
    });
    barrier_timer.setInterval(3500);
    updateTimer.setInterval(40);
    updategroundTimer.setInterval(50);
    connect(&updategroundTimer, &QTimer::timeout, this, &first_cham::updateGround);
    dialogueTimer.setInterval(7500);
    powerTimer.setInterval(3000);
    connect(&powerTimer, &QTimer::timeout, this, &first_cham::increasePower);

    grounds = new Grounds();
    dialogueWidget = new Dialogue1(this); // 创建 Dialogue1 对象
    dialogueWidget->setParent(this);
    dialogueWidget->startDialog();

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
           painter.drawPixmap(obstacle->barrier.topLeft(), obstacle->getPixmap());
    }
    painter.setPen(Qt::black);
       QFont font = painter.font();
       font.setPointSize(20); // 设置字体大小
       font.setBold(true);
       painter.setFont(font);
       painter.drawText(width() - 200, 50, QString("Power: %1").arg(power)); // 在右上角绘制 power 的数值
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
    if (event->key() == Qt::Key_X && power == 100) {
        if (!ailiObject->isTricking) {
            power = 0;
            powerTimer.stop();
            ailiObject->trick();

            // 检查碰撞并删除相应物体
            for (int i = 0; i < barriers.size(); ++i) {
                if (barriers[i]->ifCollision(ailiObject->aili_Rect) == 1) {
                    delete barriers[i];
                    barriers.remove(i);
                    --i; // 因为删除了元素，需要将索引回退
                }
            }

            for (int i = 0; i < 10; ++i) {
                grounds->grounds[i].setScrollSpeed(40);
            }
            for (int i = 0; i < barriers.size(); ++i) {
                barriers[i]->speed = 40;
            }

            QTimer::singleShot(10000, this, [=]() {
                for (int i = 0; i < 10; ++i) {
                    grounds->grounds[i].setScrollSpeed(20);
                }
                for (int i = 0; i < barriers.size(); ++i) {
                    barriers[i]->speed = 20;
                }
                powerTimer.start();
                ailiObject->isTricking = false;
            });
        }
    }
}

void first_cham::storeBarriers(){                        //生成障碍物
    srand((unsigned int)time(NULL));
    int i=rand()%5;
    switch (i) {
    case 0:
        barriers.append(new diedPeople);
        break;
    case 1:
        barriers.append(new hongkaimonster);
        break;
    case 2:
        barriers.append(new thirteenheroes);
        break;
    case 3:
        barriers.append(new diedPeople);
        break;
    case 4:
        barriers.append(new hongkaimonster);
        break;
    default:
        break;
    }
}

void first_cham::ifCollision(){
    if (!ailiObject->isTricking) {
        for (int i = 0; i < barriers.size();) {
            int collisionResult = 0;
            collisionResult = barriers[i]->ifCollision(ailiObject->aili_Rect);
            switch (collisionResult) {
                case 0: // 无碰撞
                    ++i;
                    break;
                case 1: // 障碍物
                    gameOver();
                    collisionResult=0;
                    break;
                case 2: // thirteenheroes
                    if (power + 20 <= 100) {
                        power += 20;
                    } else {
                        power = 100;
                    }
                    delete barriers[i]; // 删除碰撞的 barrier 对象
                    barriers.remove(i); // 从向量中移除 barrier
                    break;
            }
        }
    }
}
void first_cham::increasePower()
{
    if(power+5<=100)
        power+=5;
    else
        power=100;
}

void first_cham::gameStart(){
    barriers.clear();
    ailiObject = new aili(this);
    ailiObject->setPosition(50,470);
    for(int i=0;i<10;i++)
    {
        grounds->grounds[i].ground_scroll_speed=20;
    }
    power=0;

    add_Barrier.start();
    barrier_timer.start();
    updateTimer.start();
    updatebackgroundTimer.start();
     updategroundTimer.start();
     powerTimer.start();
    connect(&updateTimer,&QTimer::timeout,[=](){
        updatebarriers();    //更新坐标
        ifCollision();  //碰撞检测
        update();          //刷新屏幕
    });
}
void first_cham::gameOver(){
    for(int i=0;i<10;i++)
    {
        grounds->grounds[i].setScrollSpeed(0);
    }
    add_Barrier.stop();
    barrier_timer.stop();
    updateTimer.stop();
    updatebackgroundTimer.stop();
    showRestartDialog(this);
}

void first_cham::showRestartDialog(QWidget *parent) {
    static bool isDialogShown = false; // 静态变量跟踪消息框是否已经弹出
    if (isDialogShown) {
        return; // 如果消息框已经弹出，则直接返回，不再弹出新的消息框
    }

    // 创建一个问题消息框
    QMessageBox msgBox(parent); // 将 parent 作为父窗口
    msgBox.setWindowTitle("游戏结束");
    msgBox.setText("要再陪爱莉玩一把吗？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    // 设置消息框的背景颜色
    msgBox.setStyleSheet("QMessageBox { background-color: pink; }");
    QFont font("华文琥珀", 16);
    msgBox.setFont(font);

    // 显示消息框并获取用户的选择
    int reply = msgBox.exec();
    isDialogShown = true; // 将标志设置为 true，表示消息框已经弹出

    if (reply == QMessageBox::Yes) {
        // 用户点击了“Yes”按钮，关闭窗口
        gameStart();
    } else {
        // 用户点击了“No”按钮，或者关闭了消息框，不执行任何操作
        emit restartGameSignal();
        this->close();
        isDialogShown = false; // 将标志重新设置为 false，表示消息框已经关闭
    }
}
