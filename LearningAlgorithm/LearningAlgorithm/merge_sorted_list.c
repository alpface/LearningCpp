//
//  merge_sorted_list.c
//  LearningAlgorithm
//
//  Created by swae on 2019/7/21.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include "merge_sorted_list.h"


// 使用归并算法，将有序数组a和b的值合并到一个数组result中，且依旧保持有序
void mergeList(int arr1[], int len1, int arr2[], int len2, int result[]) {
    int *p1 = arr1; // 遍历数组a的指针
    int *p2 = arr2; // 遍历数组b的指针
    int i = 0; // 记录当前存储的位置
    
    while (i < (len1 + len2)) {
        
        // p1 指针已经超出arr1数组的长度，并且p2指针还未超出arr2数组的长度，则将arr2数组中剩余的所有元素添加到result中
        if (p1 >= arr1 + len1 && p2 < arr2 + len2) {
            result[i] = *p2;
            p2++;
        }
        // p2 指针已经超出arr2数组的长度，并且p1指针还未超出arr1数组的长度，则将arr1数组中剩余的所有元素添加到result中
        else if (p2 >= arr2 + len2 && p1 < arr1 + len1) {
            result[i] = *p1;
            p1++;
        }
        else {
            // p1和m2指向的内容进行比较，谁的值小就放到新的数组中，然后向前移动指向内容小的那个指针，依次进行比较
            if (*p1 < *p2) {
                result[i] = *p1;
                p1++;
            }
            else {
                result[i] = *p2;
                p2++;
            }
        }
        
        i++;
    }
}

