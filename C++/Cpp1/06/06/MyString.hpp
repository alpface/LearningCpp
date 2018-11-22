//
//  MyString.hpp
//  06
//
//  Created by xiaoyuan on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#pragma once

#ifndef MyString_hpp
#define MyString_hpp

#include <iostream>

using namespace std;

class MyString {
    // 友元函数 左移运算符重载 控制台输出MyString对象
    friend ostream& operator<<(ostream &cout, MyString &str);
    // 右移运算符>>重载 用户可以在控制台输入字符串，然后生一个MyString对象
    friend istream& operator>>(istream &cin, MyString &str);
public:
    // 有参构造函数，根据char类型的字符串初始化MyString实例
    MyString(const char *cstr);
    // 拷贝构造函数
    MyString(const MyString &str);
    ~MyString();
    
    // 重载=赋值运算符 字符串赋值
    MyString &operator=(const MyString &str);
    MyString &operator=(const char *cstr);
    // 重载[]运算符 字符串取值
    char &operator[](int index);
    // 重载+运算符 字符串拼接
    MyString operator+(const MyString &str);
    MyString operator+(const char *cstr);
    // 重载==运算符 字符串判断
    bool operator==(const MyString &str);
    bool operator==(const char *cstr);
    
private:
    // 指向字符串的首地址
    char *pString;
    int m_len;
};

#endif /* MyString_hpp */
