//
//  MyArray.cpp
//  05
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "MyArray.hpp"

using namespace std;

MyArray::MyArray()
{
    this->m_size = 0;
    // 指定存储100个元素的容量
    this->m_capacity = 100;
    // 为数组分配内存空间
    this->pAddress = new int[this->m_capacity];
}

MyArray::MyArray(int capacity)
{
    this->m_capacity = capacity;
    this->m_size = 0;
    this->pAddress = new int[this->m_capacity];
}

MyArray::MyArray(const MyArray &array)
{
    cout << "MyArray 拷贝构造函数被调用" << endl;
    this->m_size = array.m_size;
    this->m_capacity = array.m_capacity;
    this->pAddress = new int[array.m_capacity];
    for (int i = 0; i < array.m_size; ++i) {
        this->pAddress[i] = array.pAddress[i];
    }
}

MyArray::~MyArray()
{
    if (this->pAddress != NULL) {
        delete[] this->pAddress;
        this->pAddress = NULL;
        cout << "~MyArray析构函数被调用" << endl;
    }
}

void MyArray::push_Back(int value)
{
    // 不需要判断数据是否越界或者value是否存在，当发生错误，让系统抛出异常，用户处理即可
    this->pAddress[this->m_size] = value;
    this->m_size++;
}

int MyArray::getData(int index)
{
    int data = this->pAddress[index];
    return data;
}

void MyArray::setData(int index, int value)
{
    this->pAddress[index] = value;
    if (index >= this->m_size) {
        this->m_size++;
    }
}

int MyArray::getSize() 
{
    return this->m_size;
}
int MyArray::getCapacity()
{
    return this->m_capacity;
}

int& MyArray::operator[](int index) // 重载[]运算符
{
    return this->pAddress[index];
}
