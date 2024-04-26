#ifndef FIRST_CHAM_H
#define FIRST_CHAM_H

#include <QWidget>
#include <QTimer>
#include <QPixmap>
#include <QVector>
#include <QPainter>
#include <QIcon>
#include <QKeyEvent>
#include <QDebug>
#include <QVector>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "ground.h"
#include "aili.h"
#include "barriers.h"
#include "dialogue.h"

class first_cham : public QWidget
{
    Q_OBJECT

public:
    explicit first_cham(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    int power;
    int grade;
    QTimer add_Barrier;
    QTimer barrier_timer;
    QTimer updateTimer;
    QTimer updatebackgroundTimer;
    QTimer updategroundTimer;
    QTimer dialogueTimer;
    QTimer powerTimer;
    QTimer gradeTimer;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    bool isProtected;
    Grounds *grounds; // 地面对象指针
    Aili *ailiObject;
    diedPeople *die1;
    QVector   <barriers*>barriers; // 管理屏幕中的障碍物的向量
    Dialogue1 *dialogueWidget; // 对话框窗口指针
    void updateGround(); // 更新地面状态
    void updatebarriers(); // 更新障碍物状态
    void storeBarriers(); // 存储障碍物状态
    void gameOver(); // 游戏结束处理函数
    void gameStart(); // 游戏开始处理函数
    void ifCollision(); // 碰撞检测函数
    void showRestartDialog(QWidget *parent); // 显示重新开始对话框
    void increasePower(); // 增加能量函数
    void increaseGrade(); // 增加分数函数
    bool isDiaBoxShow; // 对话框是否显示标志
    ~first_cham(); // 析构函数

signals:
    void restartGameSignal(); // 重新开始游戏信号

private slots:
    void changeBackground(); // 切换背景
    void updateBackground(); // 更新背景

private:
    QTimer *timer;
    QVector<QPixmap> backgrounds; // 存储背景图片的向量
    int currentBackgroundIndex;   // 当前背景图片索引

};

#endif // FIRST_CHAM_H
