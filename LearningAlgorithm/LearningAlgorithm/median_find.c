//
//  median_find.c
//  LearningAlgorithm
//
//  Created by swae on 2019/7/23.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include "median_find.h"


int partSort(int arr[], int start, int end) {
    int low = start;
    int high = end;
    
    // 读取关键字
    int key = arr[end];
    while (low < high) {
        // 左边的值比key大的值
        while (low < high && arr[low] <= key) {
            ++low;
        }
        
        // 右边找比key小的值
        while (low < high && arr[high] >= key) {
            --high;
        }
        
        if (low < high) {
            // 找到之后交换左右的值
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
        
    }
    
    int temp = arr[high];
    arr[high] = arr[end];
    arr[end] = temp;
    
    return low;
}

// 查找无序数组的中位数
int findMedian(int arr[], int len) {
    int low = 0;
    int high = len - 1;
    
    int mid = (len - 1) / 2;
    int div = partSort(arr, low, high);
    
    while (div != mid) {
        if (mid < div) {
            // 左半区查找
            div = partSort(arr, low, div -1);
        }
        else {
            // 右半区查找
            div = partSort(arr, div + 1, high);
        }
    }
    
    // 找到中位数
    return arr[mid];
}
