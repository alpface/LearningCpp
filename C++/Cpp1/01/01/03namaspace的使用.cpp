//
//  03namaspace的使用.cpp
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include "game1.hpp"
#include "game2.hpp"


// 命名空间的左右主要用来解决命名冲突问题
void test01()
{
    LOL::goAtk();
    KingGlory::goAtk();
}

// 1.命名空间下可以放 函数 变量 结构体 类 命名空间
// 2.命名空间必须定义在全局作用域下
// 3.命名空间可以嵌套命名空间
namespace A {
    int a;
    void test();
    struct Person {
        
    };
    class Animatal {
        
    };
    namespace B {
        int a;
    }
}
void test2()
{
    A::B::a = 10;
    cout << A::B::a << endl;
}
// 4.命名空间是开放的，可以往其他命名空间中添加内容
namespace A {
    void getA();
}

// 5.匿名命名空间
namespace {
    int age = 20;
    char ch = 'a';
}

// 匿名命名空间的变量int age = 20; 相当于staic int age = 20;
// 只能在当前文件中使用

// 6.命名空间可以起别名
namespace MyNameSpace {
    int num = 900;
}

void test3()
{
    // 为MyNameSpace命名空间起别名为mns
    namespace mns = MyNameSpace;
    cout << mns::num<<endl;
}


int main(int argc, const char *argv[])
{
//    test2();
    test3();
    return EXIT_SUCCESS;
}
