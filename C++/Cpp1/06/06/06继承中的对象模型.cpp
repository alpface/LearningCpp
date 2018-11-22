//
//  06继承中的对象模型.cpp
//  06
//
//  Created by swae on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Base {
    
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};

void test()
{
    Base b;
    
    cout << sizeof(b) << endl;
    // b对象占用12个字节，通过打印可以看出Base实例的对象为它全部属性的内存大小
    // 在子类中，实际上是继承父类的全部属性包括私有属性，我们无法使用是因为被编译器隐藏起来了
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
