//
//  DynamicArray.h
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/14.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#pragma once

#ifdef __cplusplus
extern "C"{
#endif
    
    /// 定义数据结构
    struct DynamicArray{
        // 数据存储元素空间的首地址
        void **addr;
        // 数据存储的内存空间最大能容纳多少元素
        int capacity;
        // 当前存储的内存中有多少元素
        int size;
    };
    
    /// 初始化数组
    /// @param capacity 初始化数组的元素数量
    struct DynamicArray *Init_DynamicArray(int capacity);
    
    /// 插入元素
    /// @param arr 插入的数组
    /// @param pos 插入数组的位置
    /// @param data 插入的数据的内存地址
    void Insert_DynamicArray(struct DynamicArray *arr, int pos, void *data);
    
    /// 遍历数组
    /// @param arr 遍历的数组
    /// @param callback 遍历的回调
    void Foreach_DynamicArray(struct DynamicArray *arr, void (*callback)(void *, int));
    
    /// 删除数组中某个位置的元素
    void RemoveByPos_DynamicArray(struct DynamicArray *arr, int pos);
    
    /// 按值删除
    void RemoveByValue_DynamicArray(struct DynamicArray *arr, void *value, int (*compare)(void *, void *));
    
    /// 销毁数组
    void Destroy_DynamicArray(struct DynamicArray *arr);
    
#ifdef __cplusplus
}
#endif
