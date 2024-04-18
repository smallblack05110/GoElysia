#ifndef FIRST_CHAM_H
#define FIRST_CHAM_H

#include <QWidget>
#include <QTimer>
#include <QPixmap>
#include <QVector>
#include <QPainter>
#include <QIcon>
#include <QKeyEvent>
#include "ground.h"
#include "aili.h"

class first_cham : public QWidget
{
    Q_OBJECT

public:
    explicit first_cham(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event) override;
    Grounds *grounds; // 地面对象指针
    aili *ailiObject;
    void updateGround();
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


