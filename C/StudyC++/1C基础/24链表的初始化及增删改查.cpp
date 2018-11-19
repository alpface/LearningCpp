//
//  24链表的初始化及增删改查.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/13.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "LinkList.h"

int main(int argc, const char *argv[])
{
    // 初始化链表
    LinkData *headerNode = Init_LinkList();
    // 遍历链表中所有子节点数据
    ForEach_LinkList(headerNode);
    printf("________________\n");
    // 在oldValue所在节点的后面插入一个数字
    int newValue, oldValue;
    printf("请输入需要插入的数字：");
    scanf("%d", &newValue);
    printf("请输入需要插入在哪个数字的后面，如果没有这个数字则插入在链表的末尾：");
    scanf("%d", &oldValue);
    InsertByValue_LinkList(headerNode, oldValue, newValue);
    ForEach_LinkList(headerNode);
    printf("请输入需要移除的数字：");
    int removeNum;
    scanf("%d", &removeNum);
    RemoveValue_LinkList(headerNode, removeNum);
    ForEach_LinkList(headerNode);
    printf("逆序链表：\n");
    // 逆序链表
    Reverse_LinkList(headerNode);
    ForEach_LinkList(headerNode);
    printf("清空链表：\n");
    // 清空链表
    Clean_LinkList(headerNode);
    ForEach_LinkList(headerNode);
    // 释放链表
    Distory_LinkList(&headerNode);
    
    return EXIT_SUCCESS;
}
