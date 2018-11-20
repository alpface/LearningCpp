//
//  04构造函数的分类及调用.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/20.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>

/*
 在面向对象编程中，创建对象时系统会自动调用构造函数来初始化对象，构造函数是一种特殊的类成员函数，它有如下特点：
 
 1. 构造函数的名子必须和类名相同，不能任意命名；
 2. 构造函数没有返回值；
 3. 构造函数可以被重载，但是每次对象创建时只会调用其中的一个；
 */

using namespace std;

class Person {
public:
    // 1. 普通构造函数
    // 普通构造函数是最为常见的构造函数，它没有特殊的特点，其函数形参参数可有多个，其函数原型和测试代码如下：
    Person(int age, string name)
    {
        cout << "带参数的构造函数被调用了" << endl;
        m_age = age;
        m_name = name;
    }
    
    Person(int age)
    {
        m_age = age;
        m_name = "person";
    }
    
    // 2. 默认构造函数
    // 相对于普通构造函数而言，默认构造函数是指用户可以指定实参值，也可以不指定实参值，不指定实参值，系统就使用默认的值，而且默认构造函数只可以有一个，否则有歧义；默认构造函数原型和测试代码如下：
    // 构造函数必须写在public下才可以被调用
    Person()
    {
        cout << "默认构造函数被调用了" << endl;
    }
    
    // 3. 拷贝构造函数
    // 拷贝构造函数，也叫做复制构造函数，主要应用于使用一个已存在的对象去初始化一个新对象，使新对象的属性和该对象保持一致。
    // 若用户未定义拷贝构造函数，编译器就自动提供一个默认的复制构造函数，其作用仅是简单地复制类中的每个数据成员；为了安全起见，类设计者需要提供拷贝构造函数；
    Person(const Person &p)
    {
        cout << "拷贝构造函数被调用了" << endl;
        m_name = p.getName();
        m_age = p.getAge();
    }
    
    int getAge() const
    {
        return m_age;
    }
    
    string getName() const
    {
        return m_name;
    }
    
    ~Person()
    {
        cout << "析构函数被调用了" << endl;
    }
    
private:
    int m_age;
    string m_name;
};

void test()
{
    // 构造函数的调用方式:
    
    /* 括号调用 */
    // 1.带参数的构造函数初始化
    Person p(10, "xiaoyuan");
    
    // 2.默认构造函数初始化
    Person p1; // 注意：默认的构造函数不加()，如果加括号就变成Person p1(),这种写法是函数名为p1返回值为Person类型的函数声明。
    
    // 3.拷贝构造函数的初始化
    Person p2(p);
    
    /* 显示法调用 */
    Person p3 = Person(20, "hahah");
    Person p4 = Person();
    Person p5 = Person(p3);
    
    // 匿名构造函数
    Person();
    
    Person p6 = 200; // 相当于调用了 Person p6 = Person(200)
    Person p7 = p3;  // 相当于调用了 Person p7 = Person(p7)
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
