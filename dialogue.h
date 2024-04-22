#define DIALOGUE_H
#define DIALOGUE_H

#include <QObject>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QMouseEvent>
#include <QTimer>

class Dialogue1 : public QWidget {
    Q_OBJECT
public:
    Dialogue1(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);
        label = new QLabel("点击鼠标继续对话", this);
        label->setAlignment(Qt::AlignCenter);
        label->setGeometry(40,20,900,200); // 设置 label 的位置和大小
        QFont font("宋体", 16);
        font.setBold(true);
        label->setFont(font);

        layout->addWidget(label);

        // 创建定时器
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Dialogue1::showNextDialog);
    }

    void startDialog() {
        currentDialogIndex = -1;
        // 开始定时器，每隔一段时间显示下一条对话
        timer->start(2000); // 间隔3秒
    }

private slots:
    void showNextDialog() {
        currentDialogIndex++;
        if (currentDialogIndex < dialogs.size()) {
            label->setText(dialogs[currentDialogIndex]);
        } else {
            label->setText(" ");
            // 对话结束时停止定时器，并发出对话结束信号
            timer->stop();
            this->hide();
            emit dialogueFinished();
        }
    }

private:
    QLabel *label;
    QStringList dialogs = {
        "爱莉希雅：通过计算，我已经找到了世界泡与世界泡之间最薄弱的连接点。",
        "爱莉希雅：只要前往计算所得地点，理论上我就能够打破世界泡之间的连接。",
        "爱莉希雅：这样，我就能够见到舰长了！",
        "爱莉希雅：前方检测到大量崩坏兽能量。",
        "爱莉希雅：要冲了，舰长！"
    };
    int currentDialogIndex = -1;
    QTimer *timer;
signals:
    void dialogueFinished();
};
