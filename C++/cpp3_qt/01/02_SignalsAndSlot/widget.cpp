#include "widget.h"

/*
需求：创建两个类 Teacher类和Student类
下课后老师Teacher发出一个信号 饿了
学生响应信号，处理信号的槽函数 请老师吃饭
*/

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    teacher = new Teacher(this);
    student = new Student(this);
    // 连接老师和学生 无参数的信号和槽
//    connect(teacher, &Teacher::hungry, student, &Student::treat );
    // 触发事件
//    classIsOver();

    // 有参数的信号和槽
    // 通过函数指针执行函数地址
//    void (Student::*treatSlots)(QString) = &Student::treat;
//    void (Teacher::*hungrySignal)(QString) = &Teacher::hungry;
//    connect(teacher, hungrySignal, student, treatSlots);

//    classIsOver();

    // 点击按钮触发下课
    QPushButton *btn = new QPushButton("下课", this);
    this->resize(600, 400);
    // 触发无参信号和槽
    void (Teacher:: *noParameterHungrySignal)(void) = &Teacher::hungry;
    void (Student:: *noParameterTreatSlots)(void) = &Student::treat;
    connect(btn, &QPushButton::clicked, teacher, noParameterHungrySignal); // 信号连接信号
    // 一个信号可以连接多个槽函数
//    connect(btn, &QPushButton::clicked, this, &QWidget::close);
    connect(teacher, noParameterHungrySignal, student, noParameterTreatSlots); // 信号连接槽

    // 断开信号和槽
//    disconnect(teacher, noHungrySignal, student, noTreatSignal);

    /*
     * 信号和槽的拓展：
     * 1.信号可以连接信号
     * 2.信号和槽可以断开 disconnect
     * 3.一个信号可以连接多个槽函数
     * 4.多个信号可以连接同一个槽函数
     * 5.信号的参数个数可以多余，槽函数的参数个数不可以多余，但是信号和槽的参数类型必须是一一对应的
    */

    // QT4 版本 信号和槽的写法
    connect(teacher, SIGNAL(hungry(QString)), student, SLOT(treat(QString)));
    // 不推荐QT4版本信号和槽的写法，原因：类型匹配不检测
    // 优点：参数类型比较直观，发送函数重载也不需要写函数指针
    // 不检测参数类型的原因：SIGNAL和SLOT里面的代码当做字符串处理，比如：
    //  SIGNAL("hungry(QString)")  和 SLOT("treat(QString)")
    classIsOver();

    ////////////////////////
    btn2 = new QPushButton("aaaa", this);
    btn2->move(100, 100);
    connect(btn2, &QPushButton::clicked, this, &Widget::buttonClick);
}

Widget::~Widget()
{

}

void Widget::buttonClick()
{
    btn2->setText("88888888");
}

void Widget::classIsOver()
{
    // 触发老师饿了吗的信号
    // 老师饿了吗信号属于自定义信号，触发自定义信号的关键字 emit
    emit teacher->hungry("宫保鸡丁");
//    emit teacher->hungry();
}
