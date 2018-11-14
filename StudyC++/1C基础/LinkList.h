//
//  LinkList.h
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/13.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif
    
    // 定义节点数据类型
    struct LinkData {
        int data;
        struct LinkData *next;
    };
    
    // 初始化链表
    struct LinkData *Init_LinkList(void);
    
    // 在链表中值为oldValue的第一个节点位置插入一个新的数据newValue，如果oldValue不存在链表中，则将newValue插入到链表的尾部
    void InsertByValue_LinkList(struct LinkData *header, int oldValue, int newValue);
    
    // 删除值为value的节点
    void RemoveValue_LinkList(struct LinkData *header, int value);
    
    // 遍历节点
    void ForEach_LinkList(struct LinkData *header);
    
    // 销毁
    void Distory_LinkList(struct LinkData **header);
    
    // 清空
    void Clean_LinkList(struct LinkData *header);
    
    // 逆序链表中的元素
    void Reverse_LinkList(struct LinkData *header);
    
#ifdef __cplusplus
}
#endif
