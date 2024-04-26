#include "prize.h"

//本功能未完全实现，故不给出注释
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
    titleLabel->move(475, 100); // 设置标题标签的位置
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
    QPixmap pri1Pixmap(":/beijing/image/prizeimg.jpg");
    QPixmap scaledPixmap = pri1Pixmap.scaled(Prize1->size(), Qt::KeepAspectRatio);
    Prize1->setPixmap(scaledPixmap);
    Prize1text = new QLabel(this);
    Prize1text->setText("如花朵般娇羞的少女");
    Prize1text->resize(300,150);
    Prize1text->move(53,195);
    Prize1text->setFont(QFont("方正粗黑宋简体", 14));
    Prize1text->setStyleSheet("color: pink;");
    Prize1exp = new QLabel(this);
    Prize1exp->setText("点击开始游戏");
    Prize1exp->resize(300,150);
    Prize1exp->move(100,300);
    Prize1exp->setFont(QFont("方正粗黑宋简体", 12));
    Prize1exp->setStyleSheet("color: pink;");
//    Prize1->setVisible(false);
//    Prize1text->setVisible(false);
//    Prize1exp->setVisible(false);
    Prize2 = new QLabel(this);
    Prize2->resize(300,150);
    Prize2->move(550,200);
    QPixmap pri2Pixmap(":/beijing/image/pri2beijing.jpg");
    QPixmap scaled2Pixmap = pri2Pixmap.scaled(Prize1->size(), Qt::KeepAspectRatio);
    Prize2->setPixmap(scaled2Pixmap);
    Prize2text = new QLabel(this);
    Prize2text->setText("星月送来神的女儿");
    Prize2text->resize(330,150);
    Prize2text->move(573,195);
    Prize2text->setFont(QFont("方正粗黑宋简体", 14));
    Prize2text->setStyleSheet("color: pink;");
    Prize2exp = new QLabel(this);
    Prize2exp->setText("发现特殊的爱莉");
    Prize2exp->resize(300,150);
    Prize2exp->move(600,300);
    Prize2exp->setFont(QFont("方正粗黑宋简体", 12));
    Prize2exp->setStyleSheet("color: pink;");

    Prize3 = new QLabel(this);
    Prize3->resize(300,150);
    Prize3->move(1050,200);
    QPixmap pri3Pixmap(":/beijing/image/pri3beijing.jpg");
    QPixmap scaled3Pixmap = pri3Pixmap.scaled(Prize1->size(), Qt::KeepAspectRatio);
    Prize3->setPixmap(scaled3Pixmap);
    Prize3text = new QLabel(this);
    Prize3text->setText("我如今来过");
    Prize3text->resize(330,150);
    Prize3text->move(1103,195);
    Prize3text->setFont(QFont("方正粗黑宋简体", 14));
    Prize3text->setStyleSheet("color: pink;");
    Prize3exp = new QLabel(this);
    Prize3exp->setText("得分达到500");
    Prize3exp->resize(300,150);
    Prize3exp->move(1100,300);
    Prize3exp->setFont(QFont("方正粗黑宋简体", 12));
    Prize3exp->setStyleSheet("color: pink;");

    Prize4 = new QLabel(this);
    Prize4->resize(300,150);
    Prize4->move(50,500);
    QPixmap pri4Pixmap(":/beijing/image/pri4beijing.jpg");
    QPixmap scaled4Pixmap = pri4Pixmap.scaled(Prize1->size(), Qt::KeepAspectRatio);
    Prize4->setPixmap(scaled4Pixmap);
    Prize4text = new QLabel(this);
    Prize4text->setText("我从未离去");
    Prize4text->resize(330,150);
    Prize4text->move(88,495);
    Prize4text->setFont(QFont("方正粗黑宋简体", 14));
    Prize4text->setStyleSheet("color: purple;");
    Prize4exp = new QLabel(this);
    Prize4exp->setText("得分达到1000");
    Prize4exp->resize(300,150);
    Prize4exp->move(100,600);
    Prize4exp->setFont(QFont("方正粗黑宋简体", 12));
    Prize4exp->setStyleSheet("color: pink;");

    Prize5 = new QLabel(this);
    Prize5->resize(300,150);
    Prize5->move(550,500);
    QPixmap pri5Pixmap(":/beijing/image/pri5beijing.jpg");
    QPixmap scaled5Pixmap = pri5Pixmap.scaled(Prize1->size(), Qt::KeepAspectRatio);
    Prize5->setPixmap(scaled5Pixmap);
    Prize5text = new QLabel(this);
    Prize5text->setText("回应我吧！爱莉希雅！");
    Prize5text->resize(330,150);
    Prize5text->move(553,495);
    Prize5text->setFont(QFont("方正粗黑宋简体", 12));
    Prize5text->setStyleSheet("color: purple;");
    Prize5exp = new QLabel(this);
    Prize5exp->setText("得分达到2000");
    Prize5exp->resize(300,150);
    Prize5exp->move(600,600);
    Prize5exp->setFont(QFont("方正粗黑宋简体", 12));
    Prize5exp->setStyleSheet("color: pink;");
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
