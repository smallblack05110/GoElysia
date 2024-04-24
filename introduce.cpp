#include "introduce.h"

Introduce::Introduce(QWidget *parent) : QWidget(parent)
{
    // 设置窗口标题
    setWindowTitle("冲鸭！粉色妖精小姐");
    this->setFixedSize(1400,900);
    QIcon winicon(":/beijing/image/btn2.png");
    this->setWindowIcon(winicon);

    // 创建标题标签
    titleLabel = new QLabel("游戏介绍");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setFont(QFont("Arial", 20, QFont::Bold));

    // 创建描述标签
    descriptionLabel = new QLabel("我们的世界，均是虚数之树上的叶子，"
                                  "叶子飘落进入量子之海，便变成了世界泡，"
                                  "经过计算，爱莉希雅得出了从崩坏世界通过几个世界泡到达我们世界的路径。"
                                  "现在需要你，聪明的舰长，来控制爱莉跨越重重障碍，使爱莉到达你的面前。"
                                  "在游戏中，你将控制爱莉避过重重障碍。"
                                  "使用‘w’键，你将实现跳跃效果"
                                  "使用‘shift’键，你将实现冲刺效果"
                                  "当power值达到100时，按下‘x’键，你将获得一段时间的无敌"
                                  "当然，路上不仅有阻挡你的障碍物，还有能够帮助你的伙伴，接受这些伙伴的帮助，你将会收获意外惊喜"
                                  "遇到他们时，请直接接受他们的好意（不要使用‘w’或是‘shift’键");
    descriptionLabel->setWordWrap(true); // 自动换行

    // 创建关闭按钮
    closeButton = new QPushButton("关闭");
    connect(closeButton, &QPushButton::clicked, this, &Introduce::closeWindow);

    // 创建布局管理器
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
    layout->addWidget(descriptionLabel);
    layout->addWidget(closeButton);
    layout->setAlignment(Qt::AlignCenter);

    // 设置窗口布局
    setLayout(layout);
}

void Introduce::closeWindow()
{
    // 关闭窗口
    close();
}
