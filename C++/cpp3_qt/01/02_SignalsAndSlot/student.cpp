#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "请老师吃饭";

}

void Student::treat(QString foodName)
{
//    qDebug() << "请老师吃饭，老师要吃：" << foodName;
    // QString 转换 char*：先转换为QByteArray，再转char*
    char *name = foodName.toUtf8().data();
    qDebug() << "请老师吃饭，老师要吃：" << name;
}
