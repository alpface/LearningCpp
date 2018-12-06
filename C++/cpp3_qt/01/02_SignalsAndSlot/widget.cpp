#include "widget.h"
#include <QDebug>

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

    // lambda 表达式
    /*
    C++11中的Lambda表达式用于定义并创建匿名的函数对象，以简化编程工作。首先看一下Lambda表达式的基本构成：
    [capture](parameters) mutable ->return-type
    {
        statement
    }
    =。函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this），并且是值传递方式（相当于编译器自动为我们按值传递了所有局部变量）。
    &。函数体内可以使用Lambda所在作用范围内所有可见的局部变量（包括Lambda所在类的this），并且是引用传递方式（相当于编译器自动为我们按引用传递了所有局部变量）。

    */

    QPushButton *myBtn = new QPushButton(this);
    QPushButton *myBtn1 = new QPushButton(this);
    myBtn->move(200, 200);
    myBtn1->move(300, 300);
    int m = 10;
    connect(myBtn, &QPushButton::clicked, this, [m]()mutable {
        m = 100+10;
        qDebug() << m;
    });
    connect(myBtn1, &QPushButton::clicked, this, [=]()mutable {
        qDebug() << m ;
    });
    qDebug() << m;

    // 待返回值的lambda表达式
    int ret = []()->int {
            return 20;
    }();
    qDebug() << ret ;

    // 用到最频繁的是[=](){}

    // 信号槽连接，lambda表达式内默认使用外部的变量是只读的，如果进行写操作，会挂掉
    // 但是我在mac上测试 qt4.7.1不挂
    QPushButton *myBtn2 = new QPushButton("ccccc", this);
    myBtn2->move(400, 300);
    connect(myBtn2, &QPushButton::clicked, this, [=](){
        myBtn2->setText("aaaaaa");
    });


    // 使用lambda表达式 信号槽无参数调用有参数的槽
    connect(myBtn2, &QPushButton::clicked, this, [=](){
        teacher->hungry("吃好吃的西红柿鸡蛋");
    });
    // 点击按钮关闭窗口
    connect(myBtn2, &QPushButton::clicked, [=](){
        this->close();
    });
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
