#define MAINWINDOW_H

#include "startwindow.h"
#include "introduce.h"
#include "prize.h"
#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QIcon>
#include <QSize>
#include <QLineEdit>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); // 构造函数
    startwindow sta; // 开始窗口对象
    Introduce *introduceWindow; // 介绍窗口指针
    Prize *prize; // 奖品窗口指针
    void Init(); // 初始化函数
    void paintEvent(QPaintEvent *event); // 绘制事件
    void showMainWindow(); // 显示主窗口
    void onExitClicked(); // 退出按钮点击事件
    void onStaClicked(); // 开始按钮点击事件
    void onIntroClicked(); // 介绍按钮点击事件
    void onPriClicked(); // 成就按钮点击事件
    ~MainWindow(); // 析构函数

private:
    Ui::MainWindow *ui; // UI界面指针

signals:

};
