//
//  09参数的传递方式.cpp
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 值传递
void mySwap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "mySwap::a= " << a << " ";
    cout << "mySwap::b= " << b << " ";
    cout << endl;
}

void test01()
{
    // 测试值传递
    int a = 10;
    int b = 30;
    mySwap(a, b); // 值传递
    cout << "test01::a= " << a << " ";
    cout << "test01::b= " << b << " ";
    cout << endl;
}

// 地址传递
void mySwap1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "mySwap1::a= " << *a << " ";
    cout << "mySwap1::b= " << *b << " ";
    cout << endl;
}

void test02()
{
    // 测试值传递
    int a = 10;
    int b = 30;
    mySwap1(&a, &b); // 地址
    cout << "test02::a= " << a << " ";
    cout << "test02::b= " << b << " ";
    cout << endl;
}

// 引用传递 类似地址传递
void mySwap2(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "mySwap2::a= " << a << " ";
    cout << "mySwap2::b= " << b << " ";
    cout << endl;
}

void test03()
{
    // 测试值传递
    int a = 10;
    int b = 30;
    mySwap2(a, b); // 引用传递
    cout << "test03::a= " << a << " ";
    cout << "test03::b= " << b << " ";
    cout << endl;
}


/*
 引用注意事项：
 1.引用必须引用的是一块合法的内存
 2.不要返回局部变量的引用
*/

int &dowork()
{
    // 返回局部变量的引用是错误的
    int a = 10;
    return a;
}

int &dowork1()
{
    // ok
    static int a = 10;
    return a;
}

// 如果函数的返回值是引用，name这个函数可以可以作为左值
void test04()
{
    dowork1() = 100;
    cout << "dowork1 = " << dowork1() << endl;
}

int main(int argc, const char *argv[])
{
//    test01();
//    test02();
//    test03();
    test04();
    return EXIT_SUCCESS;
}
