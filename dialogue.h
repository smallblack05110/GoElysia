#define DIALOGUE_H
#define DIALOGUE_H

#include <QObject>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QMouseEvent>
#include <QTimer>

//设置显示在关卡之上的文本
class Dialogue1 : public QWidget {
    Q_OBJECT
public:
    Dialogue1(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);
        label = new QLabel("爱莉希雅：前方检测到大量崩坏兽能量。", this);
        label->setAlignment(Qt::AlignLeft);
        label->setGeometry(40,20,1400,200); // 设置 label 的位置和大小
        label->raise();
           label->setAlignment(Qt::AlignLeft); // 设置文本左对齐
        label->setFont(QFont("方正粗黑宋简体", 20));
        label->setStyleSheet("color: #2E0854; font-size: 25pt;");
        layout->addWidget(label);

        // 创建定时器
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Dialogue1::showNextDialog);
    }

    void startDialog() {
        currentDialogIndex = -1;
        // 开始定时器，每隔一段时间显示下一条对话
        timer->start(2000); // 间隔2秒
    }

private slots:
    void showNextDialog() {
        currentDialogIndex++;
        if (currentDialogIndex < dialogs.size()) {
            label->setText(dialogs[currentDialogIndex]);
        } else {
            label->setText("爱莉希雅：别忘了按x释放终极技能!");
            // 对话结束时停止定时器，并发出对话结束信号
            timer->stop();
            emit dialogueFinished();
        }
    }

private:
    QLabel *label;
    QStringList dialogs = {
        "爱莉希雅：要冲了，舰长！"
    };
    int currentDialogIndex = -1;
    QTimer *timer;
signals:
    void dialogueFinished();
};
