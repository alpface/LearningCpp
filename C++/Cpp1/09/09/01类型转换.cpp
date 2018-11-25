//
//  01类型转换.cpp
//  09
//
//  Created by swae on 2018/11/25.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 1.静态类型转换
// static_cast<目标类型>(要转换的数据);
// static_cast与强制类型转换的区别: static_cast在编译时会进行类型检查，而强制转换不会。
void test01()
{
    // 基础类型之间使用static_cast转换
    char a = 'a';
    double d = static_cast<double>(a);
    cout << d << endl;
}

class Base {
    
public:
    int m_a;
};
class Child:public Base {
    
public:
    
};
class Other{};
void test02()
{
    // 父子之间static_cast转换
    Child *c = NULL;
    // 向上类型转换，安全的
    Base *b = static_cast<Base*>(c);
    
    Base *b1 = NULL;
    // 向上类型转换不安全的
    Child *c1 = static_cast<Child*>(b1);
    
    // 无继承关系的类型不可以使用static_cast转换
    // Static_cast from 'Child *' to 'Other *', which are not related by inheritance, is not allowed
//    Other *o = static_cast<Other *>(c1);
}

// 2.动态转换 dynamic_cast
void test03()
{
    char a = 'a';
    // dynamic_cast非常严格，失去精度或者不安全的都不可以转换
//    double d = dynamic_cast<double>(a);
}

class Base2 {
    
public:
    virtual void func(){};
};
class Child2:public Base2 {
    
public:
    virtual void func(){};
};
class Other2 {    };

void test04()
{
    Base2 *b = NULL;
    Child2 *c = NULL;
    // 向上转换 安全的 可以使用dynamic_cast转换
    Base2 *b2 = dynamic_cast<Base2 *>(c);
    
    // 向下转换 不安全的
    Child2 *c2 = dynamic_cast<Child2 *>(b);
    
    // 如果发生了多态，那么可以让基类转为派生类，向下转换
    Base2 *b3 = new Child2;
    Child2 *c3 = dynamic_cast<Child2 *>(b3);
}

// 3.常量转换const_cast
void test05()
{
    // 1.常量指针
    const int *p = NULL;
    // 取出常量
    int *newP = const_cast<int *>(p);
    
    int *p2 = NULL;
    const int *newP2 = const_cast<const int *>(p2);
    
    // 2.不能对非指针或非引用进行转换
//    const int a = 10;
//    int b = const_cast<int>(a);
    
    // 3.引用
    int num = 10;
    int &numRef = num;
    const int &numRef2 = const_cast<const int &>(numRef);
    const int &numRef3 = static_cast<const int &>(numRef);
    return;
}

// 4.重新解释转换
void test06()
{
    int a = 10;
    int *p = reinterpret_cast<int *>(a);
    
    Base *base = NULL;
    Other *other = reinterpret_cast<Other *>(base);
    
    // 最不安全，不建议使用
    return;
}

int main(int argc, const char *argv[])
{
//    test01();
//    test04();
//    test05();
    test06();
    
    int a = 0x11223344;
    char *c = (char *)&a;
    printf("%s\n",*c);
    
    return EXIT_SUCCESS;
}
