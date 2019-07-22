//
//  hash_find.c
//  LearningAlgorithm
//
//  Created by swae on 2019/7/22.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include "hash_find.h"

// 查找一个字符串中首次只出现一次的字符
char findFirstChar(char *src) {
    
    // 定义一个数组hashArray，用来存储各个字母出现次数，
    // 关于数组长度：因为ASCII表的为0-255，因此数组的长度为256（arrayHash[256]）
    int hashArray[256];
    // 对数组的每一个元素进行初始化为0
    memset(hashArray, 0, sizeof(int)*256);
    
    // 定义指针ptr指向源字符串的起始位置
    char *ptr = src;
    
    while (*ptr != '\0') {
        // 将源字符串中出现在hashArray中的字符次数加1
        hashArray[*ptr]++;
        // 移动指针
        ptr++;
    }
    
    char result = '\0';
    
    // 重新将ptr移动到源字符串的首地址
    ptr = src;
    // 遍历每个字符串出现的次数
    while (*ptr != '\0') {
        // 遇到第一个出现次数为1的字符，退出循环
        if (hashArray[*ptr] == 1) {
            result = *ptr;
            break;
        }
        ptr++;
    }
    return  result;
}
