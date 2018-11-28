//
//  01函数对象的基本使用.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/28.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 函数对象
 重载函数调用操作符的类，其对象常称为函数对象（function object），即它们是行为类似函数的对象，也叫仿函数(functor),其实就是重载“()”操作符，使得类对象可以像函数那样调用。
 注意:
 1.函数对象(仿函数)是一个类，不是一个函数。
 2.函数对象(仿函数)重载了”() ”操作符使得它可以像函数一样调用。
 分类:假定某个类有一个重载的operator()，而且重载的operator()要求获取一个参数，我们就将这个类称为“一元仿函数”（unary functor）；相反，如果重载的operator()要求获取两个参数，就将这个类称为“二元仿函数”（binary functor）。
 函数对象的作用主要是什么？STL提供的算法往往都有两个版本，其中一个版本表现出最常用的某种运算，另一版本则允许用户通过template参数的形式来指定所要采取的策略。
 
 */

class MyPrint {
    
public:
    void operator()(int num)
    {
        cout << num << endl;
        this->count++;
    }
    int count;
};

void test01()
{
    // 函数对象
    //重载了()操作符的类实例化的对象，可以像普通函数那样调用,可以有参数 ，可以有返回值
    
    MyPrint p;
    p(111);
    p(222);
    p(333);
    cout << "p.count = " << p.count << endl;
}

void test02()
{
    // 匿名对象
    MyPrint()(1000);
}

void doPrint(MyPrint print, int num)
{
    print(num);
}

// 函数对象作为函数参数
void test03()
{
    MyPrint print;
    doPrint(print, 10);
}

/*
 总结：
 1、函数对象通常不定义构造函数和析构函数，所以在构造和析构时不会发生任何问题，避免了函数调用的运行时问题。
 2、函数对象超出普通函数的概念，函数对象可以有自己的状态
 3、函数对象可内联编译，性能好。用函数指针几乎不可能
 4、模版函数对象使函数对象具有通用性，这也是它的优势之一
 
 */

int main(int argc, const char*argv[])
{
//    test01();
//    test02();
    test03();
    return EXIT_SUCCESS;
}
