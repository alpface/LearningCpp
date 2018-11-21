//
//  MyArray.hpp
//  05
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#ifndef MyArray_hpp
#define MyArray_hpp

#include <iostream>

class MyArray { // 构建一个数组，只能存放int类型的元素
public:
    MyArray();  // 默认构造函数 分配容量为100个元素的数组的内存空间
    MyArray(int capacity); // 根据指定的capacity容量为数组分配内存空间
    ~MyArray(); // 析构函数
    MyArray(const MyArray &array); // 拷贝构造函数
    
    void push_Back(int value);  // 插入value到数组的尾部
    int getData(int index); // 根据index获取元素
    void setData(int index, int value); // 添加数据到指定的位置
    int getSize(); // 获取数组的元素个数
    int getCapacity(); // 获取数组的容量
    int& operator[](int index); // 重载[]运算符
private:
    int *pAddress; // 指向数组数真正存储数据内存首地址 存储数组的数据域
    int m_size;    // 数组元素的个数
    int m_capacity; // 数组的容量
};

#endif /* MyArray_hpp */
