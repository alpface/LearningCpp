//
//  02函数运算符重载.cpp
//  06
//
//  Created by xiaoyuan on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class MyPoint {
    
public:
    // 重载函数调用运算符()
    void operator()(string text)
    {
        cout << text << endl;
    }
};

class MyAdd {
    
public:
    // 重载函数调用运算符()
    int operator()(int a, int b)
    {
        return a+b;
    }
};

void test01()
{
    MyPoint p;
    // p 是变量，但是p()的执行类似函数，这是因为MyPoint类中重载了()运算符，而p("哈哈哈");执行的是()重载的函数
    p("哈哈哈");
}

void test02()
{
    MyAdd add;
    int num = add(10, 20);
    cout << num  << endl;
    // 匿名对象
    int num2 = MyAdd()(20, 30);
    cout << num2 << endl;
}

int main(int argc, const char *argv[])
{
//    test01();
    test02();
    return EXIT_SUCCESS;
}
