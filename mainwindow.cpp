#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
    connect(sta.return1, &QPushButton::clicked, this, &MainWindow::showMainWindow);
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,1400,900,QPixmap(":/beijing/image/wangshiletu.jpg"));
    painter.drawPixmap(100,190,400,700,QPixmap(":/beijing/image/Aili4.png"));
    painter.drawPixmap(1100,600,300,300,QPixmap(":/beijing/image/aimen.png"));
}
void MainWindow::Init()
{
    {
        this->setFixedSize(1400,900);
        this->setWindowTitle("冲鸭！粉色妖精小姐！");
        QIcon winicon(":/beijing/image/btn2.png");
        this->setIconSize(QSize(40,40));
        this->setWindowIcon(winicon);
        QPushButton *sta=new QPushButton;
        sta->setParent(this);
        sta->setText("      开始游戏");//使文本和图标保持距离
        QIcon staicon(":/beijing/image/btn1.png");
        sta->setIcon(staicon);
        sta->setIconSize(QSize(83,83));
        sta->setStyleSheet(
        "color:black;"
        "background-color:pink;"
        "font-weight:bold;"
        "text-align: left; padding-left: 20px;"//左对齐并且空出位置
        "border-radius: 20px;"
        "font-size: 30px;"
        "border-style: solid;"
        "border-width: 5px;" // 设置边框宽度为2像素
        "border-color:#800080;"
        "border-style: outset;"
                    );
        sta->resize(500,100);
        sta->move(600,250);
        QPushButton *pri=new QPushButton;
        pri->setParent(this);
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
        "text-align: left; padding-left: 20px;"//左对齐并且空出位置
        "border-radius: 20px;"
        "font-size: 30px;"
        "border-style: solid;"
        "border-width: 5px;" // 设置边框宽度为5像素
        "border-color:#800080;"
        "border-style: outset;"
                    );
        QPushButton *prod=new QPushButton;
        prod->setParent(this);
        prod->setText("      游戏介绍");//使文本和图标保持距离
        prod->resize(500,100);
        prod->move(600,550);
        QIcon prodbtn(":/beijing/image/btn4.png");
        prod->setIcon(prodbtn);
        prod->setIconSize(QSize(80,80));
        prod->setStyleSheet(
        "color:black;"
        "background-color:pink;"
        "font-weight:bold;"
        "text-align: left; padding-left: 20px;"//左对齐并且空出位置
        "border-radius: 20px;"
        "font-size: 30px;"
        "border-style: solid;"
        "border-width: 5px;" // 设置边框宽度为5像素
        "border-color:#800080;"
        "border-style: outset;"
                    );
        QPushButton *exit=new QPushButton;
        exit->setParent(this);
        exit->setText("      退出游戏");//使文本和图标保持距离
        exit->resize(500,100);
        exit->move(600,700);
        QIcon exibtn(":/beijing/image/btn3.png");
        exit->setIcon(exibtn);
        exit->setIconSize(QSize(80,80));
        exit->setStyleSheet(
        "color:black;"
        "background-color:pink;"
        "font-weight:bold;"
        "text-align: left; padding-left: 20px;"//左对齐并且空出位置
        "border-radius: 20px;"
        "font-size: 30px;"
        "border-style: solid;"
        "border-width: 5px;" // 设置边框宽度为5像素
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
       connect(exit,&QPushButton::clicked,this,&MainWindow::onExitClicked);
       connect(sta,&QPushButton::clicked,this,&MainWindow::onStaClicked);
    }
}
void MainWindow::onExitClicked()
{
    // 创建一个问题消息框
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Exit");
    msgBox.setText("真的不陪爱莉再玩一会了吗？");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    // 设置消息框的背景颜色
    msgBox.setStyleSheet("QMessageBox { background-color: pink; }");
    QFont font("华文琥珀", 16);
    msgBox.setFont(font);
    // 显示消息框并获取用户的选择
    int reply = msgBox.exec();

    if (reply == QMessageBox::Yes) {
        // 用户点击了“Yes”按钮，关闭窗口
        this->close();
    } else {
        // 用户点击了“No”按钮，或者关闭了消息框，不执行任何操作
    }
}
void MainWindow::onStaClicked()
{
    this->hide();
    sta.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMainWindow()
{
  this->show();
}
