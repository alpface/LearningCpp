//
//  05空指针访问成员函数.cpp
//  04
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
public:
    void show () {
        cout << "show func" << endl;
    }
    void showAge()
    {
        cout << "show age = " << age << endl;
    }
    int age;
};

void test01()
{
    Person *p = NULL;
    p->show();
    p->showAge();
    
    /*
     结果是输出“show age =”后程序崩溃，原因如下：
     p->show(); 不会崩溃 因为p指针调用show()函数时，实际上编译器是写成show(Person *this)的方式，也就是说编译器将p作为show的函数参数传递，而show函数内未使用这个空指针，所以不会报错
     p->showAge();//当调用成员函数时，只是将实参null传给this指针，而函数内如果调用了成员变量时，实际是使用this指针调用这个成员变量，而this指针指向的是NULL，所以会crash
     */
}
/*
 更详细的解释：从c++静态绑定谈起
 
 因为对于非虚成员函数，Ｃ++这门语言是静态绑定的。这也是Ｃ++语言和其它语言Java, Python的一个显著区别。以此下面的语句为例：
 pA->test();
 这语句的意图是：调用对象 pA 的 test 成员函数。如果这句话在Java或Python等动态绑定的语言之中，编译器生成的代码大概是：
 找到 pA 的 test 成员函数，调用它。（注意，这里的找到是程序运行的时候才找的，这也是所谓动态绑定的含义：运行时才绑定这个函数名与其对应的实际代码。有些地方也称这种机制为迟绑定，晚绑定。）
 但是对于C++。为了保证程序的运行时效率，Ｃ++的设计者认为凡是编译时能确定的事情，就不要拖到运行时再查找了。所以C++的编译器看到这句话会这么干：
 1. 查找 pA 的类型，发现它有一个非虚的成员函数叫 test 。（编译器干的）
 2. 找到了，在这里生成一个函数调用，直接调A:: test ( pA )。
 所以到了运行时，由于 test ()函数里面并没有任何需要解引用 pA 指针的代码，所以真实情况下也不会引发segment fault。这里对成员函数的解析，和查找其对应的代码的工作都是在编译阶段完成而非运行时完成的，这就是所谓的静态绑定，也叫早绑定。
 正确理解C++的静态绑定可以理解一些特殊情况下C++的行为。
 */

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
