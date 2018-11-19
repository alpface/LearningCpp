//
//  11常量引用.cpp
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

void test01()
{
//    int &ref = 10; // 引用了不合法的内存，编译不通过
    const int &ref = 10; // 加入const后，编译器的处理方式为:
    // int temp = 10; const int &ref = temp;
//    ref = 10;
    
    // 通过指针简介修改const修饰的引用变量的值
    int *p = (int *)&ref;
    *p = 100;
    cout << ref << endl;
    
}

// 常量引用使用的场景：用来修饰形参
// 如果只想显示内存，而不想修改内存，则使用const修饰这个形参
void showValue(const int &a)
{
    cout << a << endl;
}

void test2()
{
    int a = 10;
    showValue(a);
}

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
