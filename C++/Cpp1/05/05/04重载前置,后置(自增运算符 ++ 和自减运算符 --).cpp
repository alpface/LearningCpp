//
//  04重载前置,后置(自增运算符 ++ 和自减运算符 --).cpp
//  05
//
//  Created by xiaoyuan on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class MyInteger {
    friend ostream & operator<<(ostream &cout, MyInteger &integer);
public:
    MyInteger()
    {
        this->m_mum = 0;
    }
    MyInteger(int n)
    {
        this->m_mum = n;
    }
    
    // 前自增++重载
    MyInteger & operator++()
    {
        ++(this->m_mum);
        return *this;
    }
    // 后自增++重载 后自增应该返回"const MyInteger".这可以防止形如"a++++"的用法
    const MyInteger operator++(int)
    {
        // 先保存目前数据
        MyInteger temp = *this;
        ++(*this);  // 会调用前自增++的函数MyInteger & operator++()
//        (this->m_mum);
        return MyInteger(temp);
    }
    
private:
    int m_mum;
};


// 重载左移运算符
ostream & operator<<(ostream &cout, MyInteger &integer)
{
    cout << integer.m_mum;
    return cout;
}

void test()
{
    MyInteger integer(10);
    
    // 前置++
    cout << "前置++" <<  ++integer << endl;
    cout << integer << endl;
    
    // 后置++
    integer++;
    cout << "后置++" << integer << endl;
    integer++;
    cout << integer << endl;
}

/*
 说明
 1. 类中的++操作符号重载之后必须保证其语意与全局++相同。
 
 2.为了区分前后，用++()表示前自增，用++(int)后自增。
 
 3.因为按照前自增的标准定义,应该支持"++++a"的语法,而且两次前自增都应该是对a对象的自身操作,如果返回A类型,那第二次前自增调用的是临时对象的前自增操作。
 4.后自增应该返回"const Complex".这可以防止形如"a++++"的用法。
 
 5.一般通过前自增操作来实现后自增操作符函数。
 */

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
