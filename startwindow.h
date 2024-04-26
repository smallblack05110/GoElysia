#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "first_cham.h" // 包含主游戏窗口的头文件
#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include <QPixmap>
#include <QHBoxLayout>
#include <QLineEdit>

class startwindow : public QWidget
{
    Q_OBJECT
public:
    explicit startwindow(QWidget *parent = nullptr); // 构造函数
    QPushButton *letu; // 往世乐土按钮
    QPushButton *return1; // 返回按钮
//    first_cham *fir; // 主游戏窗口对象
    void onReturnclicked(); // 返回按钮点击事件
    void onFirstclicked(); // 开始游戏按钮点击事件
    void showStartWindow(); // 显示开始窗口
    void paintEvent(QPaintEvent *event); // 绘制事件
    ~startwindow(); // 析构函数

signals:

};

#endif // STARTWINDOW_H

