#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 让单选按钮默认选择男
    ui->manbtn->setChecked(true);

    //  点击女的 就打印选中了
    connect(ui->womanbtn, &QRadioButton::clicked, [=](){
        qDebug() << "点击了女的";
    });

    // 点击多选框
    // state 选中为2 未选中为0
    connect(ui->checkBox, &QCheckBox::stateChanged, [=](int state){
        qDebug() << state;
    });

    // 在listWidget上展示诗
//    QListWidgetItem *item = new QListWidgetItem("春眠不觉晓");
//    item->setTextAlignment(Qt::AlignTrailing);
//    ui->listWidget->addItem(item);

//    QListWidgetItem *item1 = new QListWidgetItem("处处闻啼鸟");
//    item1->setTextAlignment(Qt::AlignTrailing);
//    ui->listWidget->addItem(item1);

    QStringList strL;
    strL << "春眠不觉晓" << "处处闻啼鸟";
    ui->listWidget->addItems(strL);

}

Widget::~Widget()
{
    delete ui;
}
