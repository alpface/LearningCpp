//
//  03初始化和清理.cpp
//  03
//
//  Created by swae on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
public:
    // 构造函数 对象初始化时调用
    // 与类名相同，没有返回值，不写void 可以对构造函数重载(可以有参数)
    // 构造函数由编译器自动调用，而不是手动，且只会调用一次
    Person()
    {
        cout << "构造函数Person()被调用" << endl;
    }
    Person(int a)
    {
        cout << "构造函数Person(int a)被调用" << endl;
    }
    
    // 析构函数 对象释放时调用
    // 与类名相同，前面有~，没有返回值，不写void，不可以有参数，也不可以被重载
    ~Person()
    {
        cout << "析构函数被调用" << endl;
    }
};

void test()
{
    Person p(10);
    
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
