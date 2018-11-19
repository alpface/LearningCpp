//
//  LinkList.h
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/15.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#pragma once

#ifdef __cplusplus
extern "C"{
#endif
    
    typedef void * LinkList;
    typedef void(*Foreach)(int, void *);
    typedef int(*Compare)(void *, void *);
    
    // 初始化链表
    LinkList Init_CLinkList(void);
    
    // 按pos位置插入某个节点
    void Insert_CLinkList(LinkList list, int pos, void *data);
    
    // 根据位置查找元素
    void *GetValueByPos_CLinkList(LinkList list, int pos);
    
    // 遍历链表
    void Foreach_CLinkList(LinkList list, Foreach foreach);
    
    // 按位置删除节点
    void RemoveByPos_ClinkList(LinkList list, int pos);
    
    // 按值删除某个节点
    void RemoveValue_ClinkList(LinkList list, void *data, Compare compare);
    
    // 清空链表中所有元素
    void Clear_ClinkList(LinkList list);
    
    // 销毁链表
    void Destory_ClinkList(LinkList list);
    
    
#ifdef __cplusplus
}
#endif

