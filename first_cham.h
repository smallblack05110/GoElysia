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
#include "ground.h"
#include "aili.h"
#include "barriers.h"

class first_cham : public QWidget
{
    Q_OBJECT

public:
    explicit first_cham(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    QTimer add_Barrier;
    QTimer barrier_timer;
    QTimer updateTimer;
    Grounds *grounds; // 地面对象指针
    aili *ailiObject;
    diedPeople *die1;
    QVector<barriers*>barriers;//管理屏幕中的障碍物
    void updateGround();
    void updatebarriers();
    void storeBarriers();
    ~first_cham();

private slots:
    void changeBackground();
    void updateBackground();

private:
    QTimer *timer;
    QVector<QPixmap> backgrounds; // 存储背景图片
    int currentBackgroundIndex;   // 当前背景图片索引

};

#endif // FIRST_CHAM_H


