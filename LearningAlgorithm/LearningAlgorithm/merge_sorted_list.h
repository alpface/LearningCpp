//
//  merge_sorted_list.h
//  LearningAlgorithm
//
//  Created by swae on 2019/7/21.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//  归并算法，对两个有序的数组进行合并，合并后的数组依旧有序

#ifndef merge_sorted_list_h
#define merge_sorted_list_h

#include <stdio.h>

// 将有序数组arr1和arr2的值合并到一个数组result中，且依旧保持有序
void mergeList(int arr1[], int len1, int arr2[], int len2, int result[]);

#endif /* merge_sorted_list_h */
