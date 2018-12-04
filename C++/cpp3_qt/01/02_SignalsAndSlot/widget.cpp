#include "widget.h"'

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
    // 连接老师和学生
    connect(teacher, &Teacher::hungry, student, &Student::treat );
}

Widget::~Widget()
{

}

void Widget::classIsOver()
{

}
