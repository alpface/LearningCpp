//
//  DynamicArray.c
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/14.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "DynamicArray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// 初始化数组
/// @param capacity 初始化数组的元素数量
struct DynamicArray *Init_DynamicArray(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }
    
    struct DynamicArray *array = (struct DynamicArray *)malloc(sizeof(struct DynamicArray));
    if (NULL == array) {
        return NULL;
    }
    array->addr = malloc(sizeof(void *) * capacity);
    array->size = 0;
    array->capacity = capacity;
    return array;
}

/// 插入元素
/// @param arr 插入的数组
/// @param pos 插入数组的位置
/// @param data 插入的数据的内存地址
void Insert_DynamicArray(struct DynamicArray *arr, int pos, void *data) {
    if (NULL == arr) {
        return;
    }
    if (NULL == data) {
        return;
    }
    if (pos < 0 || pos > arr->size) {
        // 需要插入的位置小于0或者超出当前数组的size，就 插入到数组末尾
        pos = arr->size;
    }
    
    // 判断数组的内存空间是否够用
    if (arr->size > arr->capacity) {
        // 当前数组实际的元素数量大于数组的容量了
        // 1. 申请一块更大的内存空间
        int newCapacity = arr->capacity * 2;
        void **newSpace = malloc(sizeof(void *) * newCapacity);
        
        // 2. 将原来空间的数据拷贝到新的空间中
        memcpy(newSpace, arr->addr, sizeof(void *)*arr->capacity);
        
        // 3.释放原来的内存
        free(arr->addr);
        
        // 更新addr指向
        arr->addr = newSpace;
        arr->capacity = newCapacity;
    }
    
    // 让addr中pos及其后面的所有元素后移一位，让pos位置空出一块空间空间，方面后面讲data插入到pos的位置中
    for (int i = arr->size - 1; i >= pos; --i) {
        arr->addr[i+1] = arr->addr[i];
    }
    
    // 将新元素插入到pos位置
    arr->addr[pos] = data;
    // 更新数组的实际size
    arr->size++;
}

/// 遍历数组
/// @param arr 遍历的数组
/// @param callback 遍历的回调
void Foreach_DynamicArray(struct DynamicArray *arr, void (*callback)(void *, int)) {
    if (NULL == arr) {
        return;
    }
    if (NULL == callback) {
        return;
    }
    
    for (int i = 0; i < arr->size; ++i) {
        callback(arr->addr[i], i);
    }
}

/// 删除数组中某个位置的元素
void RemoveByPos_DynamicArray(struct DynamicArray *arr, int pos) {
    if (NULL == arr) {
        return;
    }
    if (pos < 0 || pos > arr->size - 1) {
        return;
    }
    
    // 让pos后面的所有元素向前移动
    for (int i = pos; i < arr->size - 1; ++i) {
        arr->addr[i] = arr->addr[i+1];
    }
    arr->size--;
}

/// 按值删除
void RemoveByValue_DynamicArray(struct DynamicArray *arr, void *value, int (*compare)(void *, void *)) {
    if (NULL == arr) {
        return;
    }
    if (NULL == value) {
        return;
    }
    if (NULL == compare) {
        return;
    }
    
    for (int i = 0; i < arr->size; ++i) {
        
        if (compare(arr->addr[i], value)) {
            RemoveByPos_DynamicArray(arr, i);
            break;
        }
    }
}

/// 销毁数组
void Destroy_DynamicArray(struct DynamicArray *arr) {
    if (NULL == arr) {
        return;
    }
    if (arr->addr != NULL) {
        free(arr->addr);
        arr->addr = NULL;
    }
    free(arr);
    arr = NULL;
}
