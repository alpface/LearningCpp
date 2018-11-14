//
//  27递归函数实现字符串反转.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/14.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

int number = 0;

// 逆序打印
void reversPrint(const char *p)
{
    ++number;
    
    // 退出递归
    if (*p == '\0') {
        return;
    }
    // 函数入栈，只有在函数结束后才会被释放，但是此时又调用自己，函数并未结束，只有在退出递归时，函数才会结束，此时后入栈的会先被释放
    reversPrint(p+1);
    printf("%c\n", *p);
}

// 链表逆序打印
void reversPrintList(struct LinkData *pCurrent)
{
    if (NULL == pCurrent) {
        return;
    }
    reversPrintList(pCurrent->next);
    printf("%d\n", pCurrent->data);
}

void test1()
{
    const char *str = "abcdefg";
    reversPrint(str);
}

void test2()
{
    struct LinkData *header = Init_LinkList();
    reversPrintList(header);
    ForEach_LinkList(header);
}

int main(int argc, const char *argv[])
{
//    test1();
    test2();
    
    return EXIT_SUCCESS;
}

