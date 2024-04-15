#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "startwindow.h"
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
    MainWindow(QWidget *parent = nullptr);
    startwindow sta;
    void Init();
    void paintEvent(QPaintEvent *event);
    void showMainWindow();
    void onExitClicked();
    void onStaClicked();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
