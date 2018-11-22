//
//  MyString.cpp
//  06
//
//  Created by xiaoyuan on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "MyString.hpp"

// 左移运算符<<重载
ostream& operator<<(ostream &cout, MyString &str)
{
    cout << str.pString << " [字符串长度为:" << str.m_len << "]" << endl;
    return cout;
}
// 右移运算符>>重载
istream& operator>>(istream &cin, MyString &str)
{
    // 先判断原始的字符串是否有内容，如果有内容就清空
    if (str.pString != NULL) {
        delete [] str.pString;
        str.pString = NULL;
        str.m_len = 0;
    }
    
    // 让用户输入内容
    char buff[1024];
    cin >> buff;
    
    // 重新分配pString内存，并拷贝用户输入的字符串给pString的内存
    str.m_len = (int)strlen(buff);
    str.pString = new char[str.m_len+1];
    strcpy(str.pString, buff);
    
    return cin;
}

// 有参构造函数，根据char类型的字符串初始化MyString实例
MyString::MyString(const char *cstr)
{
    this->m_len = (int)strlen(cstr);
    this->pString = new char[this->m_len+1];
    strcpy(this->pString, cstr);
}

// 拷贝构造函数
MyString::MyString(const MyString &str)
{
    this->m_len = (int)strlen(str.pString);
    this->pString = new char[this->m_len+1];
    strcpy(this->pString, str.pString);
}

// 析构函数
MyString::~MyString()
{
    if (this->pString != NULL) {
        delete [] this->pString;
        this->pString = NULL;
    }
}


// 重载=赋值运算符
MyString &MyString::operator=(const MyString &str) {
    if (this->pString != NULL) {
        // 清空
        delete [] this->pString;
        this->pString = NULL;
        this->m_len = 0;
    }
    this->m_len = (int)strlen(str.pString);
    this->pString = new char[this->m_len+1];
    strcpy(this->pString, str.pString);
    return *this;
}
MyString& MyString::operator=(const char *cstr)
{
    if (this->pString != NULL) {
        delete [] this->pString;
        this->pString = NULL;
        this->m_len = 0;
    }
    this->m_len = (int)strlen(cstr);
    this->pString = new char[this->m_len+1];
    strcpy(this->pString, cstr);
    return *this;
}
// 重载[]运算符
char& MyString::operator[](int index)
{
    return this->pString[index];
}
// 重载+运算符
MyString MyString::operator+(const MyString &str)
{
    int newlen = this->m_len + str.m_len;
    char *newCstr = new char[newlen+1];
    memset(newCstr, 0, newlen+1);
    strcat(newCstr, this->pString);
    strcat(newCstr, str.pString);
    MyString newStr(newCstr);
    delete [] newCstr;
    newCstr = NULL;
    return newStr;
}
MyString MyString::operator+(const char *cstr)
{
    int newlen = this->m_len + (int)strlen(cstr);
    char *newCstr = new char[newlen+1];
    memset(newCstr, 0, newlen+1);
    strcat(newCstr, this->pString);
    strcat(newCstr, cstr);
    MyString newStr(newCstr);
    return newCstr;
}
// 重载==运算符
bool MyString::operator==(const MyString &str)
{
    if (strcmp(this->pString, str.pString) == 0 && this->m_len == strlen(str.pString)) {
        return true;
    }
    return false;
}
bool MyString::operator==(const char *cstr)
{
    if (strcmp(this->pString, cstr) == 0 && this->m_len == strlen(cstr)) {
        return true;
    }
    return false;
}
