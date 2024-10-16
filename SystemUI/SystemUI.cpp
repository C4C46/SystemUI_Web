#include "SystemUI.h"
#pragma execution_character_set("utf-8")
SystemUI::SystemUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    init();
    tablewidgetTest();
    tableWidget2Test();
    tablewidget3Test();
    tablewidget4Test();
    tablewidget5Test();
    tablewidget6Test();
    tableWidget7Test();
    tableWidget9Test();



}

SystemUI::~SystemUI()
{}

void SystemUI::init()
{


    this->setStyleSheet(R"(
        QMainWindow {
            background-image: url(C:/Users/Leaper/source/repos/SystemUI/x64/Release/img/backImg.jpg);
            background-repeat: no-repeat;
            background-position: center;
            background-size: cover; /* 或 contain */
        }
        QWidget {
             background-color: rgba(14, 53, 84, 0.5); /* 设置背景颜色和透明度 */
        }
        QPushButton {
            background-color: rgb(27, 58, 86);
            border: none;
            color: white;
        }
        QPushButton:pressed {
            background-color: rgb(28, 164, 253); /* 天蓝色 */
        }
        QLabel {
            color: white;
        }
        QTabWidget::pane {
            border: none; /* 去掉边框 */
        }
        QTabBar::tab {
            background: transparent;
            color: white;
            padding: 10px;
            border: 1px solid #1B3A56;
            border-bottom: none;
            border-top-left-radius: 10px;
            border-top-right-radius: 10px;
            margin-right: -1px; /* 去掉间隙 */
        }
        QTabBar::tab:selected {
            background: rgb(23, 168, 250); /* 选中时为深蓝色 */
        }
        QComboBox { color: white; }
        QLineEdit { color: white; }
        QTableWidget {
            border: none; /* 去掉边框 */
        }
        QTextEdit { color: white; }
    )");

    ui.comboBox->addItem("请选择");
    ui.comboBox_2->addItem("请选择");
    ui.comboBox_3->addItem("请选择");
    ui.lineEdit->setPlaceholderText("请输入");

    // 创建水平布局
    QHBoxLayout *layout6 = new QHBoxLayout(ui.widget_6);

    // 第一个进度条和标签
    QVBoxLayout *vbox1 = new QVBoxLayout();
    CircularProgressBar *progressBar1 = new CircularProgressBar();
    progressBar1->setValue(87); // 设置进度值
    QLabel *label1 = new QLabel("进度进度");
    label1->setAlignment(Qt::AlignCenter);
    label1->setStyleSheet("color: white;");
    vbox1->addWidget(progressBar1);
    vbox1->addWidget(label1);
    layout6->addLayout(vbox1, 1); // 设置伸缩因子

    // 第二个进度条和标签
    QVBoxLayout *vbox2 = new QVBoxLayout();
    CircularProgressBar *progressBar2 = new CircularProgressBar();
    progressBar2->setValue(87);
    progressBar2->setColor(QColor(255, 204, 0));
    QLabel *label2 = new QLabel("岗位人数");
    label2->setAlignment(Qt::AlignCenter);
    label2->setStyleSheet("color: white;");
    vbox2->addWidget(progressBar2);
    vbox2->addWidget(label2);
    layout6->addLayout(vbox2, 1); // 设置伸缩因子

    // 设置布局
    ui.widget_6->setLayout(layout6);


    // 创建 widget_3 的垂直布局
    QVBoxLayout *layout3 = new QVBoxLayout(ui.widget_3);

    // 第一行：标签
    QLabel *taskLabel = new QLabel("任务名称：任务一");
    QLabel *nowmultiple = new QLabel("当前倍数： 0 倍");
    QLabel *sceneLabel = new QLabel("场景名称：场景一");
    QHBoxLayout *labelLayout = new QHBoxLayout();
    labelLayout->addWidget(taskLabel);
    labelLayout->addWidget(nowmultiple);
    labelLayout->addWidget(sceneLabel);
    layout3->addLayout(labelLayout);


    // 第二行：按钮

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QVBoxLayout *startButtonLayout = new QVBoxLayout();
    QVBoxLayout *stopButtonLayout = new QVBoxLayout();
    QVBoxLayout *pauseButtonLayout = new QVBoxLayout();
    QVBoxLayout *forwardButtonLayout = new QVBoxLayout();
    QVBoxLayout *backwardButtonLayout = new QVBoxLayout();
    QVBoxLayout *loadButtonLayout = new QVBoxLayout();


    QToolButton *startButton = new QToolButton();
    QToolButton *stopButton = new QToolButton();
    QToolButton *pauseButton = new QToolButton();
    QToolButton *forwardButton = new QToolButton();
    QToolButton *backwardButton = new QToolButton();
    QToolButton *loadButton = new QToolButton();

    QString logoPath = QCoreApplication::applicationDirPath();
    // 设置图标
    startButton->setIcon(QIcon(logoPath + "/logo/4.png"));
    stopButton->setIcon(QIcon(logoPath + "/logo/10.png"));
    pauseButton->setIcon(QIcon(logoPath + "/logo/8.png"));
    forwardButton->setIcon(QIcon(logoPath + "/logo/12.png"));
    backwardButton->setIcon(QIcon(logoPath + "/logo/2.png"));
    loadButton->setIcon(QIcon(logoPath + "/logo/6.png"));

    // 设置点击后图标
    QString startClickedIconPath = logoPath + "/logo/3.png";
    QString stopClickedIconPath = logoPath + "/logo/9.png";
    QString pauseClickedIconPath = logoPath + "/logo/7.png";
    QString forwardClickedIconPath = logoPath + "/logo/11.png";
    QString backwardClickedIconPath = logoPath + "/logo/1.png";
    QString loadClickedIconPath = logoPath + "/logo/5.png";

    // 设置图标大小
    QSize iconSize(45, 45);
    startButton->setIconSize(iconSize);
    stopButton->setIconSize(iconSize);
    pauseButton->setIconSize(iconSize);
    forwardButton->setIconSize(iconSize);
    backwardButton->setIconSize(iconSize);
    loadButton->setIconSize(iconSize);
    // 设置按钮样式为圆形
    QString buttonStyle = "QToolButton { "
        "border: none; "
        "border-radius: 15px; "  // 圆形半径应为宽度/高度的一半
        "background-color: transparent; "
        "}";
    startButton->setStyleSheet(buttonStyle);
    stopButton->setStyleSheet(buttonStyle);
    pauseButton->setStyleSheet(buttonStyle);
    forwardButton->setStyleSheet(buttonStyle);
    backwardButton->setStyleSheet(buttonStyle);
    loadButton->setStyleSheet(buttonStyle);
    // 创建标签
    QLabel *startLabel = new QLabel("初始化");
    QLabel *stopLabel = new QLabel("开始");
    QLabel *pauseLabel = new QLabel("结束");
    QLabel *forwardLabel = new QLabel("跳时");
    QLabel *backwardLabel = new QLabel("倍速");
    QLabel *loadLabel = new QLabel("断点加载");

    // 添加按钮和标签到布局
    startButtonLayout->addWidget(startButton);
    startButtonLayout->addWidget(startLabel);
    stopButtonLayout->addWidget(stopButton);
    stopButtonLayout->addWidget(stopLabel);
    pauseButtonLayout->addWidget(pauseButton);
    pauseButtonLayout->addWidget(pauseLabel);
    forwardButtonLayout->addWidget(forwardButton);
    forwardButtonLayout->addWidget(forwardLabel);
    backwardButtonLayout->addWidget(backwardButton);
    backwardButtonLayout->addWidget(backwardLabel);
    loadButtonLayout->addWidget(loadButton);
    loadButtonLayout->addWidget(loadLabel);
    // 添加空白空间
    QSpacerItem *leftSpacer = new QSpacerItem(2, 2, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *rightSpacer = new QSpacerItem(2, 2, QSizePolicy::Expanding, QSizePolicy::Minimum);

    buttonLayout->addItem(leftSpacer);
    buttonLayout->addLayout(startButtonLayout);
    buttonLayout->addLayout(pauseButtonLayout);
    buttonLayout->addLayout(stopButtonLayout);
    buttonLayout->addLayout(forwardButtonLayout);
    buttonLayout->addLayout(backwardButtonLayout);
    buttonLayout->addLayout(loadButtonLayout);
    buttonLayout->addItem(rightSpacer);
    layout3->addLayout(buttonLayout);


    // 设置初始图标和点击后图标
    startButton->setProperty("defaultIcon", logoPath + "/logo/4.png");
    startButton->setProperty("clickedIcon", startClickedIconPath);

    stopButton->setProperty("defaultIcon", logoPath + "/logo/10.png");
    stopButton->setProperty("clickedIcon", stopClickedIconPath);

    pauseButton->setProperty("defaultIcon", logoPath + "/logo/8.png");
    pauseButton->setProperty("clickedIcon", pauseClickedIconPath);

    forwardButton->setProperty("defaultIcon", logoPath + "/logo/12.png");
    forwardButton->setProperty("clickedIcon", forwardClickedIconPath);

    backwardButton->setProperty("defaultIcon", logoPath + "/logo/2.png");
    backwardButton->setProperty("clickedIcon", backwardClickedIconPath);

    loadButton->setProperty("defaultIcon", logoPath + "/logo/6.png");
    loadButton->setProperty("clickedIcon", loadClickedIconPath);
    // 连接信号和槽
    auto toggleIcon = [](QToolButton *button) {
        static QMap<QToolButton*, bool> buttonStates;
        if (!buttonStates.contains(button)) {
            buttonStates[button] = false; // 初始化状态
        }

        QString defaultIcon = button->property("defaultIcon").toString();
        QString clickedIcon = button->property("clickedIcon").toString();

        if (buttonStates[button]) {
            button->setIcon(QIcon(defaultIcon));
        }
        else {
            button->setIcon(QIcon(clickedIcon));
        }
        buttonStates[button] = !buttonStates[button]; // 切换状态
    };


    connect(startButton, &QToolButton::clicked, [=]() { toggleIcon(startButton); });
    connect(stopButton, &QToolButton::clicked, [=]() { toggleIcon(stopButton); });
    connect(pauseButton, &QToolButton::clicked, [=]() { toggleIcon(pauseButton); });
    connect(forwardButton, &QToolButton::clicked, [=]() { toggleIcon(forwardButton); });
    connect(backwardButton, &QToolButton::clicked, [=]() { toggleIcon(backwardButton); });
    connect(loadButton, &QToolButton::clicked, [=]() { toggleIcon(loadButton); });

    // 第三行：进度条
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    slider->setValue(50);
    layout3->addWidget(slider);





    ui.widget_2->setLayout(new QVBoxLayout);
    ui.widget_2->layout()->addWidget(new TimeDisplayWidget(ui.widget_2));

    // 添加状态栏
    QStatusBar *statusBar = new QStatusBar(this);
    QLabel *leftLabel = new QLabel("当前训练: 当前训练 当前训练 当前训练");
    QLabel *rightLabel = new QLabel("V1.0.1");

    // 设置字体颜色为天蓝色
    QString statusBarStyle = "QLabel { color: #87CEEB; }"; // 天蓝色
    statusBar->setStyleSheet(statusBarStyle);


    statusBar->addWidget(leftLabel);
    statusBar->addPermanentWidget(rightLabel);

    setStatusBar(statusBar);


    // 在 widget_9 中创建时间和标题显示
    QLabel *timeLabel = new QLabel(ui.widget_9);
    QLabel *titleLabel = new QLabel("系统名称系统名称系统名称", ui.widget_9);

    // 设置字体样式
    QFont titleFont;
    titleFont.setPointSize(20); // 放大字体
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);

    QFont timeFont;
    timeFont.setPointSize(16);
    timeFont.setBold(true);
    timeLabel->setFont(timeFont);
    timeLabel->setStyleSheet("color: #87CEEB;"); // 天蓝色

    // 创建水平布局
    QHBoxLayout *headerLayout = new QHBoxLayout();
    headerLayout->addWidget(timeLabel);
    headerLayout->addStretch();
    headerLayout->addWidget(titleLabel);
    headerLayout->addStretch();

    // 将布局设置到 widget_9
    ui.widget_9->setLayout(headerLayout);

    // 定时器更新时间
    QTimer *timer = new QTimer(this);
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd  hh:mm");
    timeLabel->setText("北京时间：" + currentTime);
    connect(timer, &QTimer::timeout, [=]() {
        QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd  hh:mm");
        timeLabel->setText("北京时间：" + currentTime);
    });
    timer->start(1000); // 每秒更新一次
}

void SystemUI::tablewidgetTest()
{

    // 设置列数和列标题
    ui.tableWidget->setColumnCount(2);
    QStringList headers = { "事件名称", "事件时间" };
    ui.tableWidget->setHorizontalHeaderLabels(headers);

    // 设置行数
    ui.tableWidget->setRowCount(3);
    ui.tableWidget->verticalHeader()->setVisible(false);
    ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: rgb(13, 77, 125); color: white; font-size: 10pt; text-align: left; padding-left: 5px; border: none;}");
    // 设置表头行高
    ui.tableWidget->horizontalHeader()->setFixedHeight(50);
    ui.tableWidget->setShowGrid(false);

    ui.tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 添加数据
    QStringList eventNames = { "事件名称", "事件名称", "事件名称" };
    QStringList eventTimes = { "2024-07-31 02:00:00", "2024-07-31 02:00:00", "2024-07-31 02:00:00" };
    QList<QColor> colors = { QColor(58, 137, 205), QColor(79, 154, 163), QColor(255, 69, 69) }; // 青色, 绿色, 红色

    for (int i = 0; i < eventNames.size(); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(eventNames[i]);
        nameItem->setForeground(colors[i]);  // 设置文本颜色
        nameItem->setTextAlignment(Qt::AlignCenter); // 内容居中
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget->setItem(i, 0, nameItem);

        QTableWidgetItem *timeItem = new QTableWidgetItem(eventTimes[i]);
        timeItem->setForeground(colors[i]); // 设置时间颜色为相同颜色
        timeItem->setTextAlignment(Qt::AlignCenter); // 内容居中
        timeItem->setFlags(timeItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget->setItem(i, 1, timeItem);
    }
    // 设置第一列的列宽
    ui.tableWidget->setColumnWidth(0, 100); // 例如设置为100像素

    // 调整第二列宽度以占满控件
    ui.tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui.tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);



}

void SystemUI::tableWidget2Test()
{
    // 设置列数和列标题
    ui.tableWidget_2->setColumnCount(3);
    QStringList headers = { "训练类型", "训练状态", "训练状态" };
    ui.tableWidget_2->setHorizontalHeaderLabels(headers);

    // 设置行数
    ui.tableWidget_2->setRowCount(6);

    // 隐藏行号
    ui.tableWidget_2->verticalHeader()->setVisible(false);

    // 设置表头背景颜色、字体和对齐方式
    ui.tableWidget_2->horizontalHeader()->setStyleSheet(
        "QHeaderView::section { background-color: rgb(13, 77, 125); color: white; border: none;}"
    );

    // 设置表头行高
    ui.tableWidget_2->horizontalHeader()->setFixedHeight(30);
    ui.tableWidget_2->setShowGrid(false);

    ui.tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 设置表格背景颜色
    ui.tableWidget_2->setStyleSheet("background-color: rgb(4, 35, 56);");

    // 添加数据
    QStringList dataNames = { "训练名称", "训练名称", "训练名称", "训练名称", "训练名称", "训练名称" };
    QStringList dataTypes = { "训练名称", "训练名称", "训练名称", "训练名称", "训练名称", "训练名称" };
    QStringList dataStatuses = { "训练名称", "训练名称", "训练名称", "训练名称", "训练名称", "训练名称" };


    for (int i = 0; i < dataNames.size(); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(dataNames[i]);
        nameItem->setForeground(QColor(255, 255, 255));  // 设置文本颜色为白色
        nameItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        nameItem->setTextAlignment(Qt::AlignCenter); // 内容居中
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_2->setItem(i, 0, nameItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(dataTypes[i]);
        typeItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        typeItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        typeItem->setTextAlignment(Qt::AlignCenter);
        typeItem->setFlags(typeItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_2->setItem(i, 1, typeItem);

        QTableWidgetItem *statusItem = new QTableWidgetItem(dataStatuses[i]);
        statusItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        statusItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        statusItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setFlags(statusItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_2->setItem(i, 2, statusItem);

    }

    // 调整列宽以占满控件
    ui.tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void SystemUI::tablewidget3Test()
{
    // 设置列数和列标题
    ui.tableWidget_3->setColumnCount(4);
    QStringList headers = { "数据名称", "数据类型", "数据状态", "指标状态" };
    ui.tableWidget_3->setHorizontalHeaderLabels(headers);

    // 设置行数
    ui.tableWidget_3->setRowCount(6);

    // 隐藏行号
    ui.tableWidget_3->verticalHeader()->setVisible(false);

    // 设置表头背景颜色、字体和对齐方式
    ui.tableWidget_3->horizontalHeader()->setStyleSheet(
        "QHeaderView::section { background-color: rgb(13, 77, 125); color: white; border: none;}"
    );

    // 设置表头行高
    ui.tableWidget_3->horizontalHeader()->setFixedHeight(30);
    ui.tableWidget_3->setShowGrid(false);
    ui.tableWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.tableWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 设置表格背景颜色
    ui.tableWidget_3->setStyleSheet("background-color: rgb(4, 35, 56);");

    // 添加数据
    QStringList dataNames = { "数据名称", "数据名称", "数据名称", "数据名称", "数据名称", "数据名称" };
    QStringList dataTypes = { "数据类型", "数据类型", "数据类型", "数据类型", "数据类型", "数据类型" };
    QStringList dataStatuses = { "数据状态", "数据状态", "数据状态", "数据状态", "数据状态", "数据状态" };
    QStringList indicatorStatuses = { "指标状态", "指标状态", "指标状态", "指标状态", "指标状态", "指标状态" };

    for (int i = 0; i < dataNames.size(); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(dataNames[i]);
        nameItem->setForeground(QColor(255, 255, 255));  // 设置文本颜色为白色
        nameItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        nameItem->setTextAlignment(Qt::AlignCenter);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_3->setItem(i, 0, nameItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(dataTypes[i]);
        typeItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        typeItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        typeItem->setTextAlignment(Qt::AlignCenter);
        typeItem->setFlags(typeItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_3->setItem(i, 1, typeItem);

        QTableWidgetItem *statusItem = new QTableWidgetItem(dataStatuses[i]);
        statusItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        statusItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        statusItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setFlags(statusItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_3->setItem(i, 2, statusItem);

        QTableWidgetItem *indicatorItem = new QTableWidgetItem(indicatorStatuses[i]);
        indicatorItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        indicatorItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        indicatorItem->setTextAlignment(Qt::AlignCenter);
        indicatorItem->setFlags(indicatorItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_3->setItem(i, 3, indicatorItem);
    }

    // 调整列宽以占满控件
    ui.tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void SystemUI::tablewidget4Test()
{

    // 设置列数和列标题
    ui.tableWidget_4->setColumnCount(2);
    QStringList headers = { "事件名称", "事件时间" };
    ui.tableWidget_4->setHorizontalHeaderLabels(headers);

    // 设置行数
    ui.tableWidget_4->setRowCount(6);

    // 隐藏行号
    ui.tableWidget_4->verticalHeader()->setVisible(false);

    ui.tableWidget_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.tableWidget_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 设置表头背景颜色、字体和对齐方式
    ui.tableWidget_4->horizontalHeader()->setStyleSheet(
        "QHeaderView::section { background-color: rgb(13, 77, 125); color: white; font-size: 8pt; text-align: left; padding-left: 5px; border: none;}"
    );

    // 设置表头行高
    ui.tableWidget_4->horizontalHeader()->setFixedHeight(30);
    ui.tableWidget_4->setShowGrid(false);
    // 添加数据
    QStringList eventNames = { "事件名称", "事件名称", "事件名称", "事件名称", "事件名称", "事件名称" };
    QStringList eventTimes = { "2024-07-31 02:00:00", "2024-07-31 02:00:00", "2024-07-31 02:00:00",
                               "2024-07-31 02:00:00", "2024-07-31 02:00:00", "2024-07-31 02:00:00" };

    for (int i = 0; i < eventNames.size(); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(eventNames[i]);
        nameItem->setForeground(QColor(255, 255, 255));  // 设置文本颜色为白色
        nameItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        nameItem->setTextAlignment(Qt::AlignCenter);  // 设置背景颜色
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_4->setItem(i, 0, nameItem);

        QTableWidgetItem *timeItem = new QTableWidgetItem(eventTimes[i]);
        timeItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        timeItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        timeItem->setTextAlignment(Qt::AlignCenter);
        timeItem->setFlags(timeItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_4->setItem(i, 1, timeItem);
    }

    // 设置第一列的列宽
    ui.tableWidget_4->setColumnWidth(0, 100); // 例如设置为100像素

    // 调整第二列宽度以占满控件
    ui.tableWidget_4->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
}

void SystemUI::tablewidget5Test()
{
    // 设置列数和列标题
    ui.tableWidget_5->setColumnCount(4);
    QStringList headers = { "导调名称", "导调类型", "场景时间", "执行状态" };
    ui.tableWidget_5->setHorizontalHeaderLabels(headers);

    // 设置行数
    ui.tableWidget_5->setRowCount(6);

    // 隐藏行号
    ui.tableWidget_5->verticalHeader()->setVisible(false);

    // 设置表头背景颜色、字体和对齐方式
    ui.tableWidget_5->horizontalHeader()->setStyleSheet(
        "QHeaderView::section { background-color: rgb(13, 77, 125); color: white; border: none;}"
    );

    // 设置表头行高
    ui.tableWidget_5->horizontalHeader()->setFixedHeight(30);
    ui.tableWidget_5->setShowGrid(false);
    ui.tableWidget_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.tableWidget_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 设置表格背景颜色
    ui.tableWidget_5->setStyleSheet("background-color: rgb(4, 35, 56);");

    // 添加数据
    QStringList dataNames = { "导调名称", "导调名称", "导调名称", "导调名称", "导调名称", "导调名称" };
    QStringList dataTypes = { "导调类型", "导调类型", "导调类型", "导调类型", "导调类型", "导调类型" };
    QStringList dataStatuses = { "2024-07-31 02:00:00", "2024-07-31 02:00:00", "2024-07-31 02:00:00",
                               "2024-07-31 02:00:00", "2024-07-31 02:00:00", "2024-07-31 02:00:00" };
    QStringList indicatorStatuses = { "初始化", "初始化", "待发送", "初始化", "待发送", "初始化" };

    for (int i = 0; i < dataNames.size(); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(dataNames[i]);
        nameItem->setForeground(QColor(255, 255, 255));  // 设置文本颜色为白色
        nameItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        nameItem->setTextAlignment(Qt::AlignCenter);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_5->setItem(i, 0, nameItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(dataTypes[i]);
        typeItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        typeItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        typeItem->setTextAlignment(Qt::AlignCenter);
        typeItem->setFlags(typeItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_5->setItem(i, 1, typeItem);

        QTableWidgetItem *statusItem = new QTableWidgetItem(dataStatuses[i]);
        statusItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        statusItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        statusItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setFlags(statusItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_5->setItem(i, 2, statusItem);

        QTableWidgetItem *indicatorItem = new QTableWidgetItem(indicatorStatuses[i]);
        indicatorItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        indicatorItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        indicatorItem->setTextAlignment(Qt::AlignCenter);
        indicatorItem->setFlags(indicatorItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_5->setItem(i, 3, indicatorItem);
    }

    // 调整列宽以占满控件
    ui.tableWidget_5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void SystemUI::tablewidget6Test()
{
    // 设置列数和列标题
    ui.tableWidget_6->setColumnCount(4);
    QStringList headers = { "导调名称", "导调类型", "场景时间", "执行状态" };
    ui.tableWidget_6->setHorizontalHeaderLabels(headers);

    // 设置行数
    ui.tableWidget_6->setRowCount(6);

    // 隐藏行号
    ui.tableWidget_6->verticalHeader()->setVisible(false);

    // 设置表头背景颜色、字体和对齐方式
    ui.tableWidget_6->horizontalHeader()->setStyleSheet(
        "QHeaderView::section { background-color: rgb(13, 77, 125); color: white; border: none;}"
    );

    // 设置表头行高
    ui.tableWidget_6->horizontalHeader()->setFixedHeight(30);
    ui.tableWidget_6->setShowGrid(false);
    ui.tableWidget_6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.tableWidget_6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 设置表格背景颜色
    ui.tableWidget_6->setStyleSheet("background-color: rgb(4, 35, 56);");

    // 添加数据
    QStringList dataNames = { "导调名称", "导调名称", "导调名称", "导调名称", "导调名称", "导调名称" };
    QStringList dataTypes = { "导调类型", "导调类型", "导调类型", "导调类型", "导调类型", "导调类型" };
    QStringList dataStatuses = { "2024-07-31 02:00:00", "2024-07-31 02:00:00", "2024-07-31 02:00:00",
                               "2024-07-31 02:00:00", "2024-07-31 02:00:00", "2024-07-31 02:00:00" };
    QStringList indicatorStatuses = { "初始化", "初始化", "待发送", "初始化", "待发送", "初始化" };

    for (int i = 0; i < dataNames.size(); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(dataNames[i]);
        nameItem->setForeground(QColor(255, 255, 255));  // 设置文本颜色为白色
        nameItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        nameItem->setTextAlignment(Qt::AlignCenter);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_6->setItem(i, 0, nameItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(dataTypes[i]);
        typeItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        typeItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        typeItem->setTextAlignment(Qt::AlignCenter);
        typeItem->setFlags(typeItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_6->setItem(i, 1, typeItem);

        QTableWidgetItem *statusItem = new QTableWidgetItem(dataStatuses[i]);
        statusItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        statusItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        statusItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setFlags(statusItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_6->setItem(i, 2, statusItem);

        QTableWidgetItem *indicatorItem = new QTableWidgetItem(indicatorStatuses[i]);
        indicatorItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        indicatorItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        indicatorItem->setTextAlignment(Qt::AlignCenter);
        indicatorItem->setFlags(indicatorItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_6->setItem(i, 3, indicatorItem);
    }

    // 调整列宽以占满控件
    ui.tableWidget_6->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void SystemUI::tableWidget7Test()
{
    ui.tableWidget_7->setColumnCount(2);
    // 设置行数
    ui.tableWidget_7->setRowCount(5);

    ui.tableWidget_7->horizontalHeader()->setVisible(false);
    // 隐藏行号
    ui.tableWidget_7->verticalHeader()->setVisible(false);
    ui.tableWidget_7->setShowGrid(false);

    ui.tableWidget_7->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.tableWidget_7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 设置表头背景颜色、字体和对齐方式
    //ui.tableWidget_7->horizontalHeader()->setStyleSheet(
    //    "QHeaderView::section { background-color: rgb(13, 77, 125); color: white; border: none;}"
    //);

    //// 设置表头行高
    //ui.tableWidget_7->horizontalHeader()->setFixedHeight(30);
    

    // 设置表格背景颜色
    ui.tableWidget_7->setStyleSheet("background-color: rgb(4, 35, 56);");

    // 添加数据
    QStringList dataNames = { "admindamin", "adminad", "admindaminadmin", "admin","admin" };
    QStringList dataTypes = { "2024-07-31 02:00:00", "2024-07-31 02:00:00", "2024-07-31 02:00:00",
                               "2024-07-31 02:00:00","2024-07-31 02:00:00" };

    for (int i = 0; i < dataNames.size(); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(dataNames[i]);
        nameItem->setForeground(QColor(255, 255, 255));  // 设置文本颜色为白色
        nameItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        nameItem->setTextAlignment(Qt::AlignCenter);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_7->setItem(i, 0, nameItem);

        QTableWidgetItem *typeItem = new QTableWidgetItem(dataTypes[i]);
        typeItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        typeItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        typeItem->setTextAlignment(Qt::AlignCenter);
        typeItem->setFlags(typeItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_7->setItem(i, 1, typeItem);

     
    }

    // 调整列宽以占满控件
    ui.tableWidget_7->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void SystemUI::tableWidget9Test()
{
    // 设置列数和列标题
    ui.tableWidget_9->setColumnCount(2);
    QStringList headers = { "事件名称", "事件时间" };
    ui.tableWidget_9->setHorizontalHeaderLabels(headers);

    // 设置行数
    ui.tableWidget_9->setRowCount(6);

    // 隐藏行号
    ui.tableWidget_9->verticalHeader()->setVisible(false);

    ui.tableWidget_9->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui.tableWidget_9->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 设置表头背景颜色、字体和对齐方式
    ui.tableWidget_9->horizontalHeader()->setStyleSheet(
        "QHeaderView::section { background-color: rgb(13, 77, 125); color: white; font-size: 8pt; text-align: left; padding-left: 5px; border: none;}"
    );

    // 设置表头行高
    ui.tableWidget_9->horizontalHeader()->setFixedHeight(30);
    ui.tableWidget_9->setShowGrid(false);
    // 添加数据
    QStringList eventNames = { "事件名称", "事件名称", "事件名称", "事件名称", "事件名称", "事件名称" };
    QStringList eventTimes = { "2024-07-31 02:00:00", "2024-07-31 02:00:00", "2024-07-31 02:00:00",
                               "2024-07-31 02:00:00", "2024-07-31 02:00:00", "2024-07-31 02:00:00" };

    for (int i = 0; i < eventNames.size(); ++i) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(eventNames[i]);
        nameItem->setForeground(QColor(255, 255, 255));  // 设置文本颜色为白色
        nameItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        nameItem->setTextAlignment(Qt::AlignCenter);  // 设置背景颜色
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_9->setItem(i, 0, nameItem);

        QTableWidgetItem *timeItem = new QTableWidgetItem(eventTimes[i]);
        timeItem->setForeground(QColor(255, 255, 255)); // 设置文本颜色为白色
        timeItem->setBackground(QColor(4, 35, 56));  // 设置背景颜色
        timeItem->setTextAlignment(Qt::AlignCenter);
        timeItem->setFlags(timeItem->flags() & ~Qt::ItemIsSelectable & ~Qt::ItemIsEditable); // 不可点击
        ui.tableWidget_9->setItem(i, 1, timeItem);
    }

    // 设置第一列的列宽
    ui.tableWidget_9->setColumnWidth(0, 100); // 例如设置为100像素

    // 调整第二列宽度以占满控件
    ui.tableWidget_9->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
}


