#include "introduce.h"
Introduce::Introduce(QWidget *parent) : QWidget(parent)
{
    // 设置窗口标题
    setWindowTitle("冲鸭！粉色妖精小姐");
    this->setFixedSize(1400, 900);
    QIcon winicon(":/beijing/image/btn2.png");
    this->setWindowIcon(winicon);

    // 创建标题标签
    titleLabel = new QLabel("游戏介绍", this);
    titleLabel->setFont(QFont("方正粗黑宋简体", 20, QFont::Bold));
    titleLabel->move(600, 100); // 设置标题标签的位置
    titleLabel->setStyleSheet("color: #2E0854; font-size: 25pt; font-weight: bold;");
    // 创建描述标签
    descriptionLabel = new QLabel("我们的世界，均是虚数之树上的叶子，\n"
                                  "叶子飘落进入量子之海，便变成了世界泡，\n"
                                  "经过计算，爱莉希雅得出了从崩坏世界通过几个世界泡到达我们世界的路径。\n"
                                  "现在需要你，聪明的舰长，来控制爱莉跨越重重障碍，使爱莉到达你的面前。\n"
                                  "在游戏中，你将控制爱莉避过重重障碍\n。"
                                  "使用‘w’键，你将实现跳跃效果;\n"
                                  "使用‘shift’键，你将实现滑铲俯冲效果;\n"
                                  "当power值达到100时，按下‘x’键，你将获得一段时间的无敌。\n"
                                  "路上不仅有阻挡你的障碍物，还有能够帮助你的伙伴，接受这些伙伴的帮助。\n"
                                  "遇到他们时，请直接接受他们的好意（不要使用‘w’或是‘shift’键)。\n", this);
//    descriptionLabel->setWordWrap(true); // 自动换行
    descriptionLabel->move(50, 150); // 设置描述标签的位置
    descriptionLabel->resize(1300, 600); // 设置描述标签的大小
    descriptionLabel->setStyleSheet("color: #2E0854; font-size: 18pt; font-weight: bold; font-family: 华文仿宋;");

    // 创建关闭按钮
    closeButton = new QPushButton("<<返回",this);
    closeButton->resize(150,50);
    closeButton->move(135,30);
    closeButton->setStyleSheet("background-color: rgba(0, 0, 0, 0); border: none;"
                           "font-family: 方正粗黑宋简体;"
                            " font-size: 20pt;"
                            " font-weight: bold "
                           );

    // 连接关闭按钮的点击信号到槽函数
    connect(closeButton, &QPushButton::clicked, this, &Introduce::closeWindow);
}

void Introduce::paintEvent(QPaintEvent *event)
{
    // 创建 QPainter 对象
    QPainter painter(this);

    // 绘制背景图片
    QPixmap bgImage(":/beijing/image/introbeijing.webp");
    painter.drawPixmap(0, 0, width(), height(), bgImage);
}

void Introduce::closeWindow()
{
    // 关闭窗口
    close();
}
