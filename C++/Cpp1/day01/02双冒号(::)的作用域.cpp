//
//  02双冒号(::)的作用域.cpp
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 全局变量
int num = 20;

void test()
{
    // 局部变量
    int num = 100;
    // 打印局部变量num
    cout << "局部变量num = " << num << endl;
    // 打印全局变量num
    // 双冒号:: 作用域运算符 全局变量
    cout << "全局变量num = " << ::num << endl;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
