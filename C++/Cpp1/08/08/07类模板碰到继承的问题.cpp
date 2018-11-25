//
//  07类模板碰到继承的问题.cpp
//  08
//
//  Created by swae on 2018/11/25.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

template <class T>
class Base {
    
public:
    T m_a;
};

// Child类继承Base时，必须告诉Base中的T类型，不然T无法分配内存
class Child:public Base<int> {
    
public:
    
};

// Child2继承自Base类，使用template声明，他也是模板类
template <class T1, class T2>
class Child2: public Base<T1> {
    
public:
    Child2(T1 a, T2 b)
    {
        this->m_b = b;
        this->m_a = a;
        cout << typeid(this->m_a).name() << endl;
        cout << typeid(this->m_b).name() << endl;
    }
    T2 m_b;
};

void test01()
{
    // 指定类型
    Child2<int, double> c2(10, 20.9);
    
}

int main(int argc, const char*argv[])
{
    test01();
    return EXIT_SUCCESS;
}
