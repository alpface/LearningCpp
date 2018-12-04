#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"

//命名规范 以及 快捷键
// 类名 首字母大写 单词与单词之间 首字母大写
// 函数、变量  首字母小写 单词与单词之间 首字母大写
// 快捷键
// 运行  ctrl + R
// 编译  ctrl + B
// 查找  ctrl + F
// 帮助文档 F1
// 字体缩放  ctrl + 鼠标滚轮
// 自动对齐  ctrl + i
// 整行移动 ctrl+ shift + ↑ 或者 ↓
// 同名之间的 .h .cpp切换  F4
// 帮助文档 第一种 ： F1  第二种 ：左侧按钮  第三种：C:\Qt\Qt5.6.0\5.6\mingw49_32\bin
// 注释快捷键  ctrl + /

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent) // 初始化列表
{
    // 创建按钮的第一种方式 默认构造方式
    QPushButton *btn = new QPushButton;
    // 通过窗口的方式显示按钮
//    btn->show(); //show用顶层方式弹出，如果想要在MyWidget窗口中显示，就需要依赖MyWidget窗口
    // 在当前窗口中显示btn
    btn->setParent(this); // 给btn设置父控件
    // 设置btn的文本
    btn->setText("我是btn1"); // 将char*隐士转换为QString类型

    // 创建按钮的第二种方式 注意:此种方式创建的按钮，会导致其父widget大小和btn按钮一样显示
    QPushButton *btn2 = new QPushButton("我是第二个按钮", this);
    // 重置widget的大小
    this->resize(600, 400);
    // 移动第二个按钮
    btn2->move(100, 100);
    // 重置btn的大小
    btn2->resize(120,30);
    // 设置窗口的标题
    this->setWindowTitle("我的第一个QT窗口");
    // 固定窗口大小 此时窗口无法通过鼠标调整大小
    this->setFixedSize(600, 400);

    // 创建自定义类型的按钮
    MyButton *myBtn = new MyButton;
    myBtn->setText("我的自定义按钮");
    myBtn->move(200, 200);
    myBtn->setParent(this);
    //在QT中一定程度下，简化了内存回收机制，使用QT中的类创建对象，我们不需要调用delete释放，当我们点击窗口关闭时，会被自动释放
    //可通过重写MyButton的析构函数验证

    // QT坐标系：和iOS的坐标系相同

    // 信号和槽
    // 点击myBtn关闭窗口
    // 参数1：信号的发送者，参数2：发送的信号类型地址（比如点击），参数3：信号的接受者，参数4：处理的槽函数的地址
    connect(myBtn, &MyButton::clicked, this, &MyWidget::close);

}

MyWidget::~MyWidget()
{

}
