#ifndef INTRODUCEWINDOW_H
#define INTRODUCEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPainter>
//实现游戏介绍功能
class Introduce : public QWidget
{
    Q_OBJECT
public:
    explicit Introduce(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;

signals:

private slots:
    void closeWindow();

private:
    QLabel *titleLabel;
    QLabel *descriptionLabel;
    QPushButton *closeButton;
};

#endif // INTRODUCEWINDOW_H
