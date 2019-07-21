//
//  char_reverse.c
//  LearningAlgorithm
//
//  Created by swae on 2019/7/21.
//  Copyright © 2019 xiaoyuan. All rights reserved.
//

#include "char_reverse.h"


void char_reverse(char *str) {
    
    // 指向第一个字符
    char *begin = str;
    // 指向最后一个字符
    char *end = str + (strlen(str) - 1);
    
    while (begin < end) {
        
        // 交换beigin和end指针，并移动这两个指针
        char temp = *begin;
        *(begin++) = *end;
        *(end--) = temp;
    }
}
