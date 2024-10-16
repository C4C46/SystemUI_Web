#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SystemUI.h"
#include <QPainter>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QSlider>
#pragma execution_character_set("utf-8")
class TimeDisplayWidget : public QWidget {
    Q_OBJECT

public:
    TimeDisplayWidget(QWidget *parent = nullptr) : QWidget(parent) {
  
        launchTimeLabel = new QLabel;
        runTimeLabel = new QLabel;
        beijingTimeLabel = new QLabel;

     
        QFont smallFont;
        smallFont.setPointSize(12);
        smallFont.setBold(true);

        QFont largeFont;
        largeFont.setPointSize(20); 
        largeFont.setBold(true);

        launchTimeLabel->setFont(smallFont);
        runTimeLabel->setFont(largeFont);
        beijingTimeLabel->setFont(smallFont);

        launchTimeLabel->setAlignment(Qt::AlignCenter);
        runTimeLabel->setAlignment(Qt::AlignCenter);
        beijingTimeLabel->setAlignment(Qt::AlignCenter);


        QHBoxLayout *hLayout = new QHBoxLayout;
        hLayout->addWidget(launchTimeLabel);
        hLayout->addStretch();
        hLayout->addWidget(runTimeLabel);
        hLayout->addStretch(); 
        hLayout->addWidget(beijingTimeLabel);

   
        setLayout(hLayout);

        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &TimeDisplayWidget::updateTime);
        timer->start(1000);

   
        updateTime();
    }

private slots:
    void updateTime() {
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        launchTimeLabel->setText(QString("<font color='white'>航天时间</font><br><font color='#49B4B7'>%1</font>").arg(currentTime));
        runTimeLabel->setText(QString("<font color='white'>运行时间</font><br><font color='#00FFFF'>%1</font>").arg(currentTime));
        beijingTimeLabel->setText(QString("<font color='white'>北京时间</font><br><font color='#FFD700'>%1</font>").arg(currentTime));
    }

private:
    QLabel *launchTimeLabel;
    QLabel *runTimeLabel;
    QLabel *beijingTimeLabel;
};


class CircularProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit CircularProgressBar(QWidget *parent = nullptr)
        : QWidget(parent), m_value(0), m_color(QColor(5, 184, 204)) {
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    void setValue(int value) {
        if (value != m_value) {
            m_value = value;
            update();
        }
    }

    void setMaxValue(int maxValue) {
        m_maxValue = maxValue;
        update();
    }


    void setColor(const QColor &color) {
        m_color = color;
        update();
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        int width = size().width();
        int height = size().height();
        int side = qMin(width, height);

        painter.setViewport((width - side) / 2, (height - side) / 2, side, side);
        painter.setWindow(-70, -70, 140, 140);

        // 绘制背景圆
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(7, 40, 75));
        painter.drawEllipse(-60, -60, 120, 120);

        // 绘制进度弧
        painter.setBrush(Qt::NoBrush);
        painter.setPen(QPen(m_color, 10));
        painter.drawArc(-60, -60, 120, 120, 90 * 16, -m_value * 3.6 * 16);

        // 绘制数字
        painter.setPen(Qt::white);
        QFont numberFont = painter.font();
        numberFont.setPointSize(28);
        numberFont.setBold(true);
        painter.setFont(numberFont);
        painter.drawText(-40, -20, 80, 40, Qt::AlignCenter, QString::number(m_value));

        // 绘制百分号
        QFont percentFont = painter.font();
        percentFont.setPointSize(14);
        painter.setFont(percentFont);
        painter.drawText(20, -20, 20, 20, Qt::AlignLeft, "%");

        // 计算并绘制分数
        QString fraction = QString("%1/%2").arg(m_value).arg(100);
        painter.drawText(-40, 10, 80, 40, Qt::AlignCenter, fraction);
    }

    int m_value;
    int m_maxValue;
    QColor m_color;
};


class SystemUI : public QMainWindow
{
    Q_OBJECT

public:
    SystemUI(QWidget *parent = nullptr);
    ~SystemUI();

public:
   void init();
   void tablewidgetTest();
   void tableWidget2Test();
   void tablewidget3Test();
   void tablewidget4Test();
   void tablewidget5Test();
   void tablewidget6Test();
   void tableWidget7Test();
   void tableWidget9Test();

private:
    Ui::SystemUIClass ui;
};
