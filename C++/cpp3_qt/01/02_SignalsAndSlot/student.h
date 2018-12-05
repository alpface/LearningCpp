#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    // 自定义槽函数
    // 高版本可以写到 public下 或者全局函数
    // 槽函数返回值 void
    // 需要声明，也需要实现
    // 槽函数可以有参数，也可以重载
    void treat();

    // 槽函数重载 带参数
    void treat(QString foodName);
};

#endif // STUDENT_H
