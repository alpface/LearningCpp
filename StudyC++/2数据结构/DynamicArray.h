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
    
    typedef void ** DynamicArray;
    
    /// 初始化数组
    /// @param capacity 初始化数组的元素数量
    void *Init_DynamicArray(int capacity);
    
    /// 插入元素
    /// @param arr 插入的数组
    /// @param pos 插入数组的位置
    /// @param data 插入的数据的内存地址
    void Insert_DynamicArray(void *arr, int pos, void *data);
    
    /// 遍历数组
    /// @param arr 遍历的数组
    /// @param callback 遍历的回调
    void Foreach_DynamicArray(void *arr, void (*callback)(void *, int));
    
    /// 删除数组中某个位置的元素
    void RemoveByPos_DynamicArray(void *arr, int pos);
    
    /// 按值删除
    /// @param arr 操作的数组
    /// @param value 需要删除的数据内存地址指针变量
    /// @param compare 需要用户去确定当前元素是否与要删除的数据是否相同，compare如果返回1则相同，此元素会被删除
    void RemoveByValue_DynamicArray(void *arr, void *value, int (*compare)(void *, void *));
    
    /// 销毁数组
    void Destroy_DynamicArray(void *arr);
    
    /// 获取数组中元素的个数
    int GetCount_DynamicArray(void *arr);
    
    /// 获取数组的容量
    int GetCapacity_DynamicArray(void *arr);
    
#ifdef __cplusplus
}
#endif
