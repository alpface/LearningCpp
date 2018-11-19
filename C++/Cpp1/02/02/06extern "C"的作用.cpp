//
//  06extern "C"的作用.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include "ModuleA.h"
#include "ModuleB.hpp"

/*
 extern "C"包含双重含义，从字面上可以知道，首先，被它修饰的目标是"extern"的；其次，被它修饰的目标代码是"C"的。
 下面是详细的介绍：
 
 由于C、C++编译器对函数的编译处理是不完全相同的，尤其对于C++来说，支持函数的重载，编译后的函数一般是以函数名和形参类型来命名的。
 
 例如函数void fun(int, int)，编译后的可能是（不同编译器结果不同）_fun_int_int(不同编译器可能不同，但都采用了类似的机制，用函数名和参数类型来命名编译后的函数名)；而C语言没有类似的重载机制，一般是利用函数名来指明编译后的函数名的，对应上面的函数可能会是_fun这样的名字。
 */

int main(int argc, const char *argv[])
{
    return EXIT_SUCCESS;
}
