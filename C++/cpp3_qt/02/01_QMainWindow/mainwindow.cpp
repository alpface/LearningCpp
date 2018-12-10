#include "mainwindow.h"
#include <QMenuBar> // 菜单栏
#include <QToolBar> // 工具栏
#include <QStatusBar> // 状态栏
#include <QLabel>
#include <QDockWidget> // 铆接部件
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(600, 400);

    // 添加菜单栏，只能有一个
    QMenuBar *bar = this->menuBar();
    this->setMenuBar(bar);

    // 添加菜单
    // 文件菜单
    QMenu *fileMenu = bar->addMenu("文件");
    // 编辑菜单
    QMenu *editMenu = bar->addMenu("编辑");

    // 注意: qt4.7 mac上菜单栏必须添加了菜单项才会显示
    // 添加菜单项
    QAction *newAction = fileMenu->addAction("新建");
    // 添加分割线
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");

    // 添加工具栏，可以有多个
    QToolBar *toolBar = new QToolBar;
    // 添加toolBar到当前窗口，并 设置工具栏默认停靠的范围
    this->addToolBar(Qt::LeftToolBarArea, toolBar);
    // 设置toolBar允许停靠的范围
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    // 设置浮动 在mac 上不管用 不能拖动 qt4.7
    toolBar->setFloatable(true);
    // 设置移动 （总开关） 在mac 上不管用 不能移动 qt4.7
    toolBar->setMovable(true);

    // 给工具栏添加菜单项
    toolBar->addAction(newAction);
    // 添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    // 设置状态栏 只能有一个
    QStatusBar *sBar = this->statusBar();
    this->setStatusBar(sBar);
    // 给状态栏添加label  添加提示信息到左侧
    QLabel *label1 = new QLabel("提示信息", this);
    sBar->addWidget(label1);
    // 添加提示信息到右侧
    QLabel *label2 = new QLabel("右侧的提示信息", this);
    sBar->addPermanentWidget(label2);

    // 铆接部件： 浮动窗口 可以有多个
    QDockWidget *dock = new QDockWidget;
    // 添加铆接部件到窗口中 并设置默认停靠在底部
    this->addDockWidget(Qt::BottomDockWidgetArea, dock);
    // 设置停靠范围
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt:: BottomDockWidgetArea);

    // 核心部件 只能有一个
    QTextEdit *edit = new QTextEdit;
    setCentralWidget(edit);

    // 注意：只能有一个的部件使用set进行设置，可以添加多个的使用add方法添加
}

MainWindow::~MainWindow()
{

}
