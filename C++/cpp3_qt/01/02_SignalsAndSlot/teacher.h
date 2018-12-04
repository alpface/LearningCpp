#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    // 自定义信号，需要携带signals下
    // 返回值类型 必须是void
    // 信号只需要声明，不用实现
    // 信号可以有参数，可以重载
    void hungry();

public slots:
};

#endif // TEACHER_H
