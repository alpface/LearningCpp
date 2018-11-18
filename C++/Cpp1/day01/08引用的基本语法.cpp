//
//  08引用的基本语法.cpp
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 1.引用的基本语法 Type &别名 = 原名
void test1()
{
    int a = 100;
    int &b = a;
    b = 20;
    
    cout << "a = " << a << " b = " << b << endl;
}

// 2.引用必须要初始化
void test2()
{
//    int &a; // 必须要初始化
    int a = 10;
    int &b = a; // 引用初始化以后就不能修改了
    int c = 100;
    b = c; // 这是赋值
}

// 3.对数组建议引用
void test3()
{
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = 10+ i;
    }
    
    // 给数组起别名
    int (&pArr)[10] = arr;
    for (int i = 0; i < 10; ++i) {
        cout << pArr[i] << " ";
    }
    cout << endl;
    
    // 第二种方式起别名
    typedef int(TYPE_ARRAY)[10]; // 具有10个元素为int类型的数组
    TYPE_ARRAY & array = pArr;
    for (int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    test3();
    return 0;
}
