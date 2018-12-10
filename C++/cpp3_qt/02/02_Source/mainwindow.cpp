#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置ui中actionName为actionnew的action的图标 绝对路径
//    ui->actionnew->setIcon(QIcon("/Users/xiaoyuan/Desktop/poiIcon/sponsor/z_15022.png"));
    // 添加项目中的资源图片
    ui->actionnew->setIcon(QIcon(":/image/z_15021.png"));
    ui->actionopen->setIcon(QIcon(":/image/z_15022.png"));
    ui->actionnew1->setIcon(QIcon(":/image/z_15023.png"));
    ui->actionopen2->setIcon(QIcon(":/image/z_15023.png"));
    ui->statuslabel->setText("左侧");
}

MainWindow::~MainWindow()
{
    delete ui;
}
