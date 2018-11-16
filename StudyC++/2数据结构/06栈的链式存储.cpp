//
//  06栈的链式存储.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/16.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "LinkStack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    // 用户入栈的数据，Person 结构体中的struct StackNode node是预留给我们使用的，所以我们把Person数据强制转为StackNode类型，就可以取到我们的节点数据了
    struct StackNode node;
    char name[64];
    int age;
};

void test()
{
    // 初始化栈
    LinkStack stack = Init_LinkStack();
    
    struct Person p1 = {NULL, "aaaa", 10};
    struct Person p2 = {NULL, "bbbb", 20};
    struct Person p3 = {NULL, "cccc", 30};
    struct Person p4 = {NULL, "dddd", 40};
    struct Person p5 = {NULL, "eeee", 50};
    struct Person p6 = {NULL, "ffff", 60};
    
    // 数据入栈
    Push_LinkStack(stack, &p1);
    Push_LinkStack(stack, &p2);
    Push_LinkStack(stack, &p3);
    Push_LinkStack(stack, &p4);
    Push_LinkStack(stack, &p5);
    Push_LinkStack(stack, &p6);
    
    // 查找栈中元素
    while (Size_LinkStack(stack) != 0) {
        // 获取栈顶元素
        void *topData = Top_LinkStack(stack);
        struct Person *p = (struct Person *)topData;
        printf("栈顶元素:[Name:%s -- age:%d]\n", p->name, p->age);
        // 出栈
        Pop_LinkStack(stack);
        printf("出栈\n");
    }
    
    printf("栈中元素个数:%d\n", Size_LinkStack(stack));
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
