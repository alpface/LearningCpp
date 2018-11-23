//
//  03多态示例1.cpp
//  07
//
//  Created by xiaoyuan on 2018/11/23.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 一般情况下(不涉及虚函数)，当我们用一个指针/引用调用一个函数的时候，被调用的函数是取决于这个指针/引用的类型。
 
 当设计到多态性的时候，采用了虚函数和动态绑定，此时的调用就不会在编译时候确定而是在运行时确定。不在单独考虑指针/引用的类型而是看指针/引用的对象的类型来判断函数的调用，根据对象中虚指针指向的虚表中的函数的地址来确定调用哪个函数
 */

class CA {
    
public:
   void f()
    {
        cout << "CA f()" << endl;
    }
    virtual void ff()
    {
        cout << "CA ff()" << endl;
        this->f();
    }
};

class CB: public CA {
    
public:
    virtual void f()
    {
        cout << "CB f()" << endl;
    }
    void ff()
    {
        cout << "CB ff()" << endl;
        f(); // 执行f()函数，按照就进原则，会执行本类的
        CA::ff();
    }
};

class CC: public CB {
    
public:
    void f()
    {
        cout << "CC f()" << endl;
    }
};

void test()
{
    CB b;
    CA *ap = &b;
    CC c;
    CB &br = c;
    CB *bp = &c;
    
    // 执行的是CA的f()函数，虽然ap的真实类型是CB(CB继承自CA)，但是CA中的f()函数并未使用virtual(不是虚函数)，是静态绑定，而ap此时是(CA*)类型的指针，那么CA的f()函数在编译时已确定地址
    ap->f();
    cout << endl;
    
    // 执行的是CC的f()函数，br一个CB类型的引用，但是他的真实的类型是CC，CC继承自CB，CB的f()函数使用virtual(是虚函数)，属于动态绑定
    br.f();
    cout << endl;

    // 执行的是CC的f()函数，bp真实类型为CC
    bp->f();
    cout << endl;
    
    // 执行CB的ff()函数，CB的父类CA中声明ff()为virtual，属于多态
    ap->ff();
    cout << endl;

    // 执行CB的ff()函数，bp的真实类型为CC，而CC的父类为CB，CC中并未实现ff()函数，而CB的父类为CA，CA中定义ff()为虚函数，CB中实现了ff()函数，所以执行的是CB中的ff()函数
    bp->ff();
    cout << endl;
}

int main(int argc, const char*argv[])
{
    test();
    return EXIT_SUCCESS;
}
