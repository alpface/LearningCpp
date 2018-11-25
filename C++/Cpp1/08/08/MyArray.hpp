//
//  MyArray.hpp
//  08
//
//  Created by swae on 2018/11/25.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#pragma once

#ifndef MyArray_hpp
#define MyArray_hpp

#include <iostream>
#include <string>

using namespace std;

template <class PointerType>
class MyArray {
    
public:
    // 构造函数
    explicit MyArray(int capacity) // explicit 防止隐士类型转换，比如 MyArray a = 10
    {
        this->m_capacity = capacity;
        this->pAddress = new PointerType[capacity];
        this->m_size = 0;
    }
    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        this->m_size = arr.m_size;
        this->m_capacity = arr.m_capacity;
        this->pAddress = new PointerType[this->m_capacity];
        for (int i = 0; i < this->m_size; ++i) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    // 析构函数
    ~MyArray()
    {
        if (this->pAddress != NULL) {
            delete [] this->pAddress;
            this->pAddress = NULL;
        }
    }
    // 重载=赋值运算符
    MyArray &operator=(MyArray &arr)
    {
        if (this->pAddress != NULL) {
            delete [] this->pAddress;
            this->pAddress = NULL;
        }
        this->m_size = arr.m_size;
        this->m_capacity = arr.m_capacity;
        this->pAddress = new PointerType[this->m_capacity];
        for (int i = 0; i < this->m_size; ++i) {
            this->pAddress[i] = arr[i];
        }
    }
    
    // 重载[]取值运算符
    PointerType &operator[](int index)
    {
        return this->pAddress[index];
    }
    // 尾插法
    void push_back(PointerType value)
    {
        this->pAddress[this->m_size] = value;
        this->m_size++;
    }
    // 获取数组元素个数
    int getSize()
    {
        return this->m_size;
    }
    // 获取数组容量
    int getCapacity()
    {
        return this->m_capacity;
    }
private:
    PointerType *pAddress; // 指向堆区空间
    int m_size;            // 数组元素个数
    int m_capacity;        // 数组容量
};

#endif /* MyArray_hpp */
