#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "student.h"
#include "teacher.h"
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    Teacher *teacher;
    Student *student;
    QPushButton *btn2;
    void classIsOver();
    void buttonClick();
};

#endif // WIDGET_H
