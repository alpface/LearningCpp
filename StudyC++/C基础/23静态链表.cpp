//
//  23静态链表.cpp
//  StudyC++
//
//  Created by swae on 2018/11/12.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 实现一个简单静态链表示例

// 链表节点结构体
struct LinkNode {
    int data;
    struct LinkNode *next;
};

void test()
{
    // 定义多个节点，让他们行程链表的结构
    struct LinkNode node1 = {10, NULL };
    struct LinkNode node2 = {20, NULL };
    struct LinkNode node3 = {30, NULL };
    struct LinkNode node4 = {40, NULL };
    struct LinkNode node5 = {50, NULL };
    struct LinkNode node6 = {60, NULL };
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    
    // 通过链表的第一个元素找到链表有所有的元素
    
    // 定义临时辅助指针变量
    struct LinkNode *tempNode = &node1;
    while (tempNode != NULL) {
        printf("%d\n", tempNode->data);
        // 让指针移动到下一个元素的首地址
        tempNode = tempNode->next;
    }
    
    
}

int main(int argc, const char *argv[])
{
    test();
    return 0;
}
