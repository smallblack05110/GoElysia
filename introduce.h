#ifndef INTRODUCEWINDOW_H
#define INTRODUCEWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class Introduce : public QWidget
{
    Q_OBJECT
public:
    explicit Introduce(QWidget *parent = nullptr);

signals:

private slots:
    void closeWindow();

private:
    QLabel *titleLabel;
    QLabel *descriptionLabel;
    QPushButton *closeButton;
};

#endif // INTRODUCEWINDOW_H
