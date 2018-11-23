//
//  11菱形继承的概念以及问题.cpp
//  06
//
//  Created by xiaoyuan on 2018/11/23.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

/*
 虚继承和虚函数是完全无相关的两个概念。
 
 虚继承是解决C++多重继承问题的一种手段，从不同途径继承来的同一基类，会在子类中存在多份拷贝。这将存在两个问题：其一，浪费存储空间；第二，存在二义性问题，通常可以将派生类对象的地址赋值给基类对象，实现的具体方式是，将基类指针指向继承类（继承类有基类的拷贝）中的基类对象的地址，但是多重继承可能存在一个基类的多份拷贝，这就出现了二义性。
 
 
 
 虚继承可以解决多种继承前面提到的两个问题：
 
 虚继承底层实现原理与编译器相关，一般通过虚基类指针和虚基类表实现，每个虚继承的子类都有一个虚基类指针（占用一个指针的存储空间，4字节）和虚基类表（不占用类对象的存储空间）（需要强调的是，虚基类依旧会在子类里面存在拷贝，只是仅仅最多存在一份而已，并不是不在子类里面了）；当虚继承的子类被当做父类继承时，虚基类指针也会被继承。
 
 
 
 实际上，vbptr指的是虚基类表指针（virtual base table pointer），该指针指向了一个虚基类表（virtual table），虚表中记录了虚基类与本类的偏移地址；通过偏移地址，这样就找到了虚基类成员，而虚继承也不用像普通多继承那样维持着公共基类（虚基类）的两份同样的拷贝，节省了存储空间。
 
 
 
 在这里我们可以对比虚函数的实现原理：他们有相似之处，都利用了虚指针（均占用类的存储空间）和虚表（均不占用类的存储空间）。
 
 虚基类依旧存在继承类中，只占用存储空间；虚函数不占用存储空间。
 
 虚基类表存储的是虚基类相对直接继承类的偏移；而虚函数表存储的是虚函数地址。
 

 */

using namespace std;

class Animal {
    
public:
    int m_age;
};

// 菱形继承的解决方案是利用虚继承，使用共享的数据

class Sheep: virtual public Animal {
    
public:
//    Sheep()
//    {
//        m_age = 40;
//    }
};

class Tou: virtual public Animal{
    
public:
//    Tou()
//    {
//        m_age = 80;
//    }
};

class SheelTou: public Tou,  public Sheep {
    
public:

};

void test01()
{
    SheelTou st1;
    // 由于SheepTou继承了两个父类，而这两个父类都继承自同一类型Animal，所以他们都有m_age属性，这时SheepTou在使用m_age时，就存在二义性了，编译器不知道该使用哪个父类的
    // 解决方案：让这两个父类都使用virtual虚继承，m_age就是共享的数据了，就可以直接调用m_age了，此时m_age就只有一份了，父类和子类的结果一样了
    // 使用虚继承后，多继承中析构函数的调用顺序：按照继承的列表先后调用父类的构造函数，所以如果两个父类都在构造函数中设置了m_age，那么m_age的值就为最后初始化的那个父类初始化的
    cout <<  st1.m_age << endl;
    
}

// 虚继承的工作原理：通过地址找到偏移量
void test02()
{
    SheelTou st;
    st.m_age = 10000;
    
    // 找到Sheep的偏移量
//    cout << *(int*)((int*)*(int *)&st + 1) << endl;
    // 找到tou的偏移量
//    cout << *((int *)((int *)*((int *)&st + 1) + 1)) << endl;
    
    // 输出m_age
//    cout << ((Animal*)((char *)&st + *(int*)((int*)*(int *)&st + 1)))->m_age << endl;
}

int main(int argc, const char *argv[])
{
//    test01();
    test02();
    return EXIT_SUCCESS;
}
