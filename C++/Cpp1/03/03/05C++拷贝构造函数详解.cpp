//
//  05C++拷贝构造函数详解.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/20.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;
class CExample
{
private:
    int a;
public:
    //构造函数
    CExample(int b)
    {
        a=b;
        printf("constructor is called\n");
    }
    //拷贝构造函数
    CExample(const CExample & c)
    {
        a=c.a;
        printf("copy constructor is called\n");
    }
    //析构函数
    ~CExample()
    {
        cout<<"destructor is called\n";
    }
    void Show()
    {
        cout<<"a = "<<a<<endl;
    }
};

void test01()
{
    CExample a(100);
    CExample b = a;
    b.Show();
}

// 当函数的参数为类的对象时
/**
 调用func1()时，会产生以下几个重要步骤：
 (1).a对象传入形参时，会先会产生一个临时变量，就叫 c 吧。
 (2).然后调用拷贝构造函数把a的值给c。 整个这两个步骤有点像：CExample c(a);
 (3).等func1()执行完后, 析构掉 c 对象。
 */
void func1(CExample c)
{
    cout << "func1" << endl;
}

void test02()
{
    CExample a(200);
    CExample b = a;
    b.Show();
    func1(a);
}

// 函数的返回值是类的对象
/**
 当func2()函数执行到return时，会产生以下几个重要步骤：
 (1). 先会产生一个临时变量，就叫XXXX吧。
 (2). 然后调用拷贝构造函数把temp的值给p。整个这两个步骤有点像：CExample p(temp);
 (3). 在函数执行到最后先析构temp局部变量。
 (4). 等func2()执行完后再析构掉XXXX对象。
 */
CExample func2()
{
    CExample p(100);
    return p;
}

void test03()
{
    CExample a(200);
    CExample b = a;
    b.Show();
    CExample c = func2();
}

int main(int argc, const char *argv[])
{
//    test01();
//    test02();
    test03();
    return EXIT_SUCCESS;
}
