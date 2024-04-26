#include "startwindow.h"
#include <QPainter>
#include <QIcon>

startwindow::startwindow(QWidget *parent) : QWidget(parent)
{
    // 设置窗口标题和图标
    setWindowTitle("冲鸭！粉色妖精小姐！");
    QIcon winicon(":/beijing/image/btn2.png");
    this->setWindowIcon(winicon);

    // 设置窗口大小并创建返回按钮
    setFixedSize(1400, 900);
    return1 = new QPushButton("<<返回", this);
    return1->setStyleSheet("background-color: rgba(0, 0, 0, 0); border: none; font-family: 方正粗黑宋简体; font-size: 20pt;");
    return1->resize(150, 50);
    return1->move(130, 20);
    connect(return1, &QPushButton::clicked, this, &startwindow::onReturnclicked);

    // 创建往世乐土按钮
    letu = new QPushButton(this);
    letu->resize(300, 200);
    letu->move(540, 650);
    letu->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // 设置按钮的背景图像
    QPixmap pixmap(":/beijing/image/beijing3.png");
    QPixmap fmap = pixmap.scaled(letu->size(), Qt::KeepAspectRatio);
    letu->setStyleSheet("QPushButton { background-color: rgba(0, 0, 0, 0); font-weight: bold; font-size: 30px; text-align: center; }");
    letu->setIcon(QIcon(fmap));
    letu->setIconSize(letu->size());
    letu->setFlat(true);

    // 创建按钮上的文本
    QLineEdit *first = new QLineEdit("往世乐土", this);
    first->setReadOnly(true);
    first->setStyleSheet("background-color: rgba(255, 255, 255, 0); border: none; font-family: 方正粗黑宋简体; font-size: 20pt;");
    first->resize(200, 100);
    first->move(613, 760);

    // 连接乐图按钮的点击事件和开始游戏槽函数
    connect(letu, &QPushButton::clicked, this, &startwindow::onFirstclicked);
}

startwindow::~startwindow()
{

}

void startwindow::paintEvent(QPaintEvent *event)
{
    // 绘制窗口背景图片
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), QPixmap(":/beijing/image/beijing2.jpg"));
}

void startwindow::onReturnclicked()
{
    // 隐藏当前窗口
    this->hide();
}

void startwindow::onFirstclicked()
{
    // 隐藏当前窗口并创建并显示主游戏窗口
    this->hide();
    first_cham *fir = new first_cham();
    fir->show();
    fir->gameStart();
}

void startwindow::showStartWindow()
{
    // 显示开始窗口
    this->show();
}
