#include "prize.h"

Prize::Prize(QWidget *parent) : QWidget(parent)
{
    // 设置窗口标题
    setWindowTitle("冲鸭！粉色妖精小姐");
    this->setFixedSize(1400, 900);
    QIcon winicon(":/beijing/image/btn2.png");
    this->setWindowIcon(winicon);

    // 创建标题标签
    titleLabel = new QLabel("以下是你获得的成就", this);
    titleLabel->setFont(QFont("方正粗黑宋简体", 20, QFont::Bold));
    titleLabel->move(455, 100); // 设置标题标签的位置
    titleLabel->setStyleSheet("color: #2E0854; font-size: 25pt; font-weight: bold;");

    // 创建关闭按钮
    closeButton = new QPushButton("<<返回",this);
    closeButton->resize(150,50);
    closeButton->move(20,30);
    closeButton->setStyleSheet("background-color: rgba(0, 0, 0, 0); border: none;"
                           "font-family: 方正粗黑宋简体;"
                            " font-size: 20pt;"
                            " font-weight: bold;"
                             "color : white;"
                           );

    // 连接关闭按钮的点击信号到槽函数
    connect(closeButton, &QPushButton::clicked, this, &Prize::closeWindow);

    Prize1 = new QLabel(this);
    Prize1->resize(300,150);
    Prize1->move(50,200);
    QPixmap priPixmap(":/beijing/image/prizeimg.jpg");
    QPixmap scaledPixmap = priPixmap.scaled(Prize1->size(), Qt::KeepAspectRatio);
    Prize1->setPixmap(scaledPixmap);
    Prize1text = new QLabel(this);
    Prize1text->setText("如花朵般娇羞的少女");
    Prize1text->resize(300,150);
    Prize1text->move(53,190);
    Prize1text->setFont(QFont("方正粗黑宋简体", 14));
    Prize1text->setStyleSheet("color: pink;");
    Prize1exp = new QLabel(this);
    Prize1exp->setText("点击开始游戏");
    Prize1exp->resize(300,150);
    Prize1exp->move(100,300);
    Prize1exp->setFont(QFont("方正粗黑宋简体", 12));
    Prize1exp->setStyleSheet("color: pink;");
    Prize1->setVisible(false);
    Prize1text->setVisible(false);
    Prize1exp->setVisible(false);
}

void Prize::paintEvent(QPaintEvent *event)
{
    // 创建 QPainter 对象
    QPainter painter(this);

    // 绘制背景图片
    QPixmap bgImage(":/beijing/image/pricebeijing.webp");
    painter.drawPixmap(0, 0, width(), height(), bgImage);
}

void Prize::closeWindow()
{
    this->close();
}
