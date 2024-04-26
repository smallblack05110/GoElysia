#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init(); // 初始化界面
    connect(sta.return1, &QPushButton::clicked, this, &MainWindow::showMainWindow); // 连接返回按钮的点击事件和显示主窗口的槽函数
    introduceWindow = new Introduce; // 创建介绍窗口对象
    prize = new Prize; // 创建奖品窗口对象
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    // 在窗口上绘制背景图片和角色图片
    QPainter painter(this);
    painter.drawPixmap(0,0,1400,900,QPixmap(":/beijing/image/wangshiletu.jpg")); // 绘制背景图片
    painter.drawPixmap(100,190,400,700,QPixmap(":/beijing/image/Aili4.png")); // 绘制角色图片
    painter.drawPixmap(1100,600,300,300,QPixmap(":/beijing/image/aimen.png")); // 绘制角色图片
}

void MainWindow::Init()
{
    // 初始化主窗口界面
    setFixedSize(1400,900); // 设置窗口大小
    setWindowTitle("冲鸭！粉色妖精小姐！"); // 设置窗口标题
    QIcon winicon(":/beijing/image/btn2.png"); // 设置窗口图标
    setIconSize(QSize(40,40)); // 设置图标大小
    setWindowIcon(winicon); // 设置窗口图标

    // 创建开始按钮
    QPushButton *sta = new QPushButton(this);
    sta->setText("      开始游戏");
    QIcon staicon(":/beijing/image/btn1.png");
    sta->setIcon(staicon);
    sta->setIconSize(QSize(83,83));
    sta->setStyleSheet(
        "color:black;"
        "background-color:pink;"
        "font-weight:bold;"
        "text-align: left; padding-left: 20px;"
        "border-radius: 20px;"
        "font-size: 30px;"
        "border-style: solid;"
        "border-width: 5px;"
        "border-color:#800080;"
        "border-style: outset;"
    );
    sta->resize(500,100);
    sta->move(600,250);

    // 创建查看成就按钮
    QPushButton *pri = new QPushButton(this);
    pri->setText("      查看成就");
    pri->resize(500,100);
    pri->move(600,400);
    QIcon priicon(":/beijing/image/pribtn.png");
    pri->setIcon(priicon);
    pri->setIconSize(QSize(80,80));
    pri->setStyleSheet(
        "color:black;"
        "background-color:pink;"
        "font-weight:bold;"
        "text-align: left; padding-left: 20px;"
        "border-radius: 20px;"
        "font-size: 30px;"
        "border-style: solid;"
        "border-width: 5px;"
        "border-color:#800080;"
        "border-style: outset;"
    );
    connect(pri, &QPushButton::clicked, this, &MainWindow::onPriClicked); // 连接查看成就按钮的点击事件和槽函数

    // 创建游戏介绍按钮
    QPushButton *prod = new QPushButton(this);
    prod->setText("      游戏介绍");
    prod->resize(500,100);
    prod->move(600,550);
    QIcon prodbtn(":/beijing/image/btn4.png");
    prod->setIcon(prodbtn);
    prod->setIconSize(QSize(80,80));
    prod->setStyleSheet(
        "color:black;"
        "background-color:pink;"
        "font-weight:bold;"
        "text-align: left; padding-left: 20px;"
        "border-radius: 20px;"
        "font-size: 30px;"
        "border-style: solid;"
        "border-width: 5px;"
        "border-color:#800080;"
        "border-style: outset;"
    );
    connect(prod, &QPushButton::clicked, this, &MainWindow::onIntroClicked); // 连接游戏介绍按钮的点击事件和槽函数

    // 创建退出按钮
    QPushButton *exit = new QPushButton(this);
    exit->setText("      退出游戏");
    exit->resize(500,100);
    exit->move(600,700);
    QIcon exibtn(":/beijing/image/btn3.png");
    exit->setIcon(exibtn);
    exit->setIconSize(QSize(80,80));
    exit->setStyleSheet(
        "color:black;"
        "background-color:pink;"
        "font-weight:bold;"
        "text-align: left; padding-left: 20px;"
        "border-radius: 20px;"
        "font-size: 30px;"
        "border-style: solid;"
        "border-width: 5px;"
        "border-color:#800080;"
        "border-style: outset;"
    );
    QLineEdit *title = new QLineEdit("Go!  Elysia!", this);
    title->setGeometry(570,100,600,100);
    title->setStyleSheet("background-color: rgba(0, 0, 0, 0); "
                           "border: 1px solid rgba(0, 0, 0, 0);"
                           "font-family: 方正粗黑宋简体;"
                           " font-size: 50pt;"
                           "color: #2E0854;");
    connect(exit, &QPushButton::clicked, this, &MainWindow::onExitClicked); // 连接退出按钮的点击事件和槽函数
    connect(sta, &QPushButton::clicked, this, &MainWindow::onStaClicked); // 连接开始按钮的点击事件和槽函数
}

void MainWindow::onExitClicked()
{
    // 创建一个问题消息框询问是否退出游戏
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Exit");
    msgBox.setText("真的不陪爱莉再玩一会了吗？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setStyleSheet("QMessageBox { background-color: pink; }"); // 设置消息框的背景颜色
    QFont font("华文琥珀", 16);
    msgBox.setFont(font);
    int reply = msgBox.exec(); // 显示消息框并获取用户的选择

    if (reply == QMessageBox::Yes) {
        // 用户点击了“Yes”按钮，关闭窗口
        close();
    } else {
        // 用户点击了“No”按钮，或者关闭了消息框，不执行任何操作
    }
}

void MainWindow::onStaClicked()
{
    // 显示开始窗口，隐藏主窗口
    hide();
    sta.show();
}

void MainWindow::onPriClicked()
{
    // 显示奖品窗口
    prize->show();
}

void MainWindow::onIntroClicked()
{
    // 显示介绍窗口
    introduceWindow->show();
}

MainWindow::~MainWindow()
{
    delete ui; // 删除UI界面对象
    delete introduceWindow; // 删除介绍窗口对象
}

void MainWindow::showMainWindow()
{
    show(); // 显示主窗口
}
