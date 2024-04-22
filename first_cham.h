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
    QTimer add_Barrier;
    QTimer barrier_timer;
    QTimer updateTimer;
    QTimer updatebackgroundTimer;
    QTimer updategroundTimer;
    QTimer dialogueTimer;
    QTimer powerTimer;
    Grounds *grounds; // 地面对象指针
    aili *ailiObject;
    diedPeople *die1;
    QVector<barriers*>barriers;//管理屏幕中的障碍物
    Dialogue1 *dialogueWidget;
    void updateGround();
    void updatebarriers();
    void storeBarriers();
    void gameOver();
    void gameStart();
    void ifCollision();
    void showRestartDialog(QWidget *parent);
    void increasePower();
    ~first_cham();
signals:
    void restartGameSignal();

private slots:
    void changeBackground();
    void updateBackground();

private:
    QTimer *timer;
    QVector<QPixmap> backgrounds; // 存储背景图片
    int currentBackgroundIndex;   // 当前背景图片索引

};

#endif // FIRST_CHAM_H


