//
//  05指针运算符重载.cpp
//  05
//
//  Created by xiaoyuan on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
    
public:
    Person(int age)
    {
        this->m_age = age;
    }
    void showInfo()
    {
        cout << "年龄:" << this->m_age << endl;
    }
    int m_age;
};

// 智能指针类
// 用来托管自定义类型对象，让对象自动释放
class SmartPointer {
    
public:
    SmartPointer(Person *p)
    {
        this->person = p;
    }
    // 重载*
    Person &operator*()
    {
        return *this->person;
    }
    // 重载->，让智能指针对象和Person *p一样使用
    Person *operator->()
    {
        return this->person;
    }
    ~SmartPointer()
    {
        cout << "SmartPointer析构" << endl;
        if (this->person != NULL) {
            delete this->person;
            this->person = NULL;
        }
    }
private:
    Person *person;
};

void test()
{
    // 在栈上开辟sp，会自动释放
    SmartPointer sp = SmartPointer(new Person(20));
    // sp->showInfo(); 实际上编译帮我们优化了，实际上是sp->->showInfo(); sp->是返回的是指向Person类型的指针，所以可以使用其调用Person的方法
    sp->showInfo();
    (*sp).showInfo();
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
