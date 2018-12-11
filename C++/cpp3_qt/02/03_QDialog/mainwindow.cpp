#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击新建按钮弹出对话框
    connect(ui->actionnew, &QAction::triggered, this, [=](){
        // 弹出对话框：
//       this->dialogDemo1();

        // 使用系统的标准对话框
//        this->dialogDemo2();

        // 询问对话框
//        this->dialogDemo3();

        // 警告对话框
    //    this->dialogDemo4();

        // 颜色对话框
//        this->dialogDemo5();

        // 文件选择对话框
        this->dialogDemo6();
    });
}

void MainWindow::dialogDemo1()
{
    // 对话框有两种：模态对话框和非模态对话框
    // 模态对话框弹出时，不可以对其他对话框操作；非模态对话框弹出时可以对其他对话框进行操作
    QDialog dlg(this);
    // 弹出模态对话框
    dlg.exec(); // 模态对话框弹出后会阻塞后面的代码执行

    // 非模态对话框需要创建在堆上，如果创建在栈上会一闪而过
    QDialog *dlg1 = new QDialog(this);
    dlg1->resize(500, 300);
    // 弹出非模态对话框，非模态对话框不会阻塞后面的代码执行
    dlg1->show();
    // 由于在堆上创建，而堆上创建的对象只有在当前主窗口关掉后才会被释放，所以需要给QDialog设置属性：关闭窗口后释放
    dlg1->setAttribute(Qt::WA_DeleteOnClose);
    qDebug() << "弹出对话框";
}
void MainWindow::dialogDemo2()
{
    // 使用标准对话框 QMessageBox
    // 错误对话框
//        QMessageBox::critical(this, "错误！", "critical");
    //信息对话框
//    QMessageBox::information(this,"信息","info");


}

void MainWindow::dialogDemo3()
{
    // 询问对话框 会阻塞后面的代码执行，知道点击了选项或者关闭这个dialog
    // 参数说明：
    // 1. 父控件 2.标题 3.提示内容 4.弹出的按钮类型 5.默认高亮的按钮，关联回车类型
    // 返回值为点击的按钮的枚举值
    int actionButton = QMessageBox::question(this, "问题", "question", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel);
    if (QMessageBox::Save == actionButton)
    {
        qDebug() << "点击的是保存";
    }
    else
    {
        qDebug() << "点击的是取消";
    }
}

void MainWindow::dialogDemo4()
{
    // 警告对话框
    QMessageBox::warning(this, "警告!", "这是警告详情");
}

void MainWindow::dialogDemo5()
{
    // 颜色对话框，弹出系统的选择颜色对话框
   QColor color = QColorDialog::getColor(QColor(255, 0, 0));
    qDebug() << color.red() << color.green() << color.blue();

}

void MainWindow::dialogDemo6()
{
    // 文件选择对话框
    // 弹出一个对话框，这个对话框展示的是传入的文件目录，选择文件后对话框消失，并返回选择的文件的完整路径
    // 第一个参数：父控件 第二个参数：默认打开文件的目录 第三个参数：只允许选择的文件的类型，不是这种类型的不能选择
    QString path = QFileDialog::getOpenFileName(this, "打开文件", "/Users/xiaoyuan/Desktop/work", "(*.txt *.png)");
    qDebug() << path;
}
MainWindow::~MainWindow()
{
    delete ui;
}
