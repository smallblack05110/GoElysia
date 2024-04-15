
#include "startwindow.h"

startwindow::startwindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("冲鸭！粉色妖精小姐！");
    QIcon winicon(":/beijing/image/btn2.png");
    this->setWindowIcon(winicon);

    // 设置新窗口大小
    setFixedSize(1400, 900);
    return1=new QPushButton;
    return1->setParent(this);
    return1->setText("<<返回");
    return1->resize(150,50);
    return1->move(130,20);
    return1->setStyleSheet("background-color: rgba(0, 0, 0, 0); border: none;"
                           "font-family: 方正粗黑宋简体;"
                            " font-size: 20pt;"
                           );
    connect(return1,&QPushButton::clicked,this,&startwindow::onReturnclicked);
    letu=new QPushButton;
    letu->setParent(this);
    letu->resize(300,200);

    letu->move(540,650);
    letu->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // 获取按钮的大小
    int buttonWidth = letu->width();
    int buttonHeight = letu->height();
    // 缩放背景图像以适应按钮的大小
    QPixmap pixmap(":/beijing/image/beijing3.png");
    QPixmap fmap = pixmap.scaled(buttonWidth, buttonHeight, Qt::KeepAspectRatioByExpanding);
    letu->setStyleSheet("QPushButton { "
                        "background-color: rgba(0, 0, 0, 0);"
                         "font-weight: bold; "
                         "font-size: 30px; "
                         "text-align: center; "
                         "}");
    // 设置按钮的背景图像
    letu->setIcon(QIcon(fmap));
    letu->setIconSize(QSize(buttonWidth, buttonHeight));
    letu->setFlat(true);
    QLineEdit *first = new QLineEdit(this);
    first->setText("往世乐土");
    first->setReadOnly(true);
    first->setStyleSheet("background-color: rgba(255, 255, 255, 0); border: none;"
                         "font-family: 方正粗黑宋简体;"
                          " font-size: 20pt;");
    first->resize(200,100);
    first->move(615,700);
    connect(letu, &QPushButton::clicked, this, &startwindow::onFirstclicked);

}
startwindow::~startwindow()
{
}
void startwindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,1400,900,QPixmap(":/beijing/image/beijing2.jpg"));
}
void startwindow::onReturnclicked()
{
    this->hide();
}
void startwindow::onFirstclicked()
{
    this->hide();
    fir.show();

}
