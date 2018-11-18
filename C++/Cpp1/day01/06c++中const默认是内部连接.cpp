//
//  06c++中const默认是内部连接.cpp
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>


int main(int argc, const char *argv[])
{
    // extern 告诉编译器a变量在外部，从外部查找a变量
    // 编译报错：Undefined symbols for architecture x86_64: "_a_const",
    extern const int a_const;
    printf("%d\n", a_const);
    return 0;
}
