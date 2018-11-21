//
//  04this指针的理解.cpp
//  04
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
/*
 C++类中this指针的理解
 
 理解this指针，先要理解class的意思。class应该理解为一种类型，象int,char一样，是用户自定义的类型。用这个类型可以来声明一个变量，比如int x, myclass my等等。这样就像变量x具有int类型一样，变量my具有myclass类型。理解了这个，就好解释this了，my里的this 就是指向my的指针。如果还有一个变量myclass mz，mz的this就是指向mz的指针。 这样就很容易理解this 的类型应该是myclass *,而对其的解引用*this就应该是一个myclass类型的变量。
 
 通常在class定义时要用到类型变量自身时，因为这时候还不知道变量名（为了通用也不可能固定实际的变量名），就用this这样的指针来使用变量自身。
 
 1. this指针的用处:
 一个对象的this指针并不是对象本身的一部分，不会影响sizeof(对象)的结果。
 this作用域是在类内部，当在类的非静态成员函数中访问类的非静态成员的时候，编译器会自动将对象本身的地址作为一个隐含参数传递给函数。也就是说，即使你没有写上this指针，编译器在编译的时候也是加上this的，它作为非静态成员函数的隐含形参，对各成员的访问均通过this进行。例如，调用date.SetMonth(9) <===> SetMonth(&date, 9)，this帮助完成了这一转换 .
 在成员函数内部，我们可以直接使用调用该函数的对象的成员，而无需通过成员访问运算符来做到这一点，因为this所指的正是这个对象。任何对类成员的直接访问都被看成this的隐式使用。
 this的目的总是指向这个对象，所以this是一个常量指针，我们不允许改变this中保存的地址
 2. this指针的使用:
 一种情况就是，在类的非静态成员函数中返回类对象本身的时候，直接使用 return *this；另外一种情况是当参数与成员变量名相同时，如this->n = n （不能写成n = n）。
 3. this指针程序示例:
 this指针是存在与类的成员函数中,指向被调用函数所在的类实例的地址。
 根据以下程序来说明this指针
 */

using namespace std;

class Point
{
    int x, y;
public:
    Point(int a, int b) { x=a; y=b;}
    void MovePoint( int a, int b){ x+=a; y+=b;}
    void print(){ cout<<"x="<<x<<"y="<<y<<endl;}
};

void test()
{
    Point point1( 10,10);
    point1.MovePoint(2,2);
    point1.print( );
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
