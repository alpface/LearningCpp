//
//  链表逆序.cpp
//  04
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//  链表的逆序分为两种：递归逆序和非递归逆序

#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

// 生成链表
Node *make_linkList(void)
{
    Node *head = new Node();
    Node *cur = head;
    for (int i = 0; i < 10; ++i) {
        cur->value = rand() % 10;
        cur->next = new Node();
        cur = cur->next;
    }
    return head;
}

// 非递归逆序链表
/*
 定义的这个三个指针，目的就是防止断链之后无法继续遍历链表以后的结点，实现全部的反转。当 pnow 的 next 指向 pnow 的前驱pre（初始化是 null）的时候，已经实现了 pnow 和前驱pre的方向反转，但是 pnow 此时就和后继pnext断链了，那么使用 pre 后移的方式，指向 pnow，同时 pnow 也后移，指向 pnext，而 pnext 继续指向更新之后的 pnow 的 next 结点即可。从而实现了状态的保存，继续遍历全部结点，实现链表反转。
 
 注意关于链表问题的常见注意点的思考：
 1、如果输入的头结点是 NULL，或者整个链表只有一个结点的时候
 2、链表断裂的考虑
 */
Node *reverseLinkList(Node *head)
{
    // 1定义三个指针，保存原来的链表的状态
    // 当前节点的指针
    Node *pCur = head;
    // 当前节点的前驱指针，初始化为NULL
    Node *pPre = NULL;
    // 当前节点的后继指针，初始化也是NULL
    Node *pNext = NULL;
    // 定义尾指针
    Node *pTail = NULL;
    
    // 2遍历链表
    while (pCur != NULL) {
        // 如果当前节点不是NULL，那么初始化pNext指针指向当前的下一个节点
        pNext = pCur->next;
        // 如果找到了尾节点，就初始化tail指针
        if (NULL == pNext) {
            pTail = pCur;
        }
        
        // 进行链表的反转，当前节点的next指针指向前一个节点，实现链表方向的反转，此时发生断链
        pCur->next = pPre;
        // 勿忘断链的情形，需要使用pPre指针保存状态，pPre等价于是后移一个节点
        pPre = pCur;
        // pCur 后移一个节点
        pCur = pNext;
    }
    return pTail;
}

// 递归逆序链表法
// 递归的方法其实是非常巧的，它利用递归走到链表的末端，然后再更新每一个node的next 值 ，实现链表的反转。而newhead 的值没有发生改变，为该链表的最后一个结点，所以，反转后，我们可以得到新链表的head。
Node *recursiveReverseLinkList(Node *head)
{
    // 如果链表为空或者链表中只有一个元素，就返回head本身
    if (NULL == head || head->next == NULL)
    {
        return head;
    }
    // 先反转后面的链表，走到链表的末尾节点
    Node *newHead = recursiveReverseLinkList(head->next);
    // 再将当前节点设置为后面节点的后续节点
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void printLink(Node *head)
{
    Node *cur = head;
    while (cur) {
        cout << cur->value << " ";
        cur = cur->next;
    }
    cout << endl;
}


void test()
{
    // 非递归逆序
    Node *head = make_linkList();
    cout << "生成有10的元素的随机数链表:" << endl;
    printLink(head);
    head = reverseLinkList(head);
    cout << "对链表逆序后:" << endl;
    printLink(head);
}

void test1()
{
    // 递归逆序
    Node *head = make_linkList();
    cout << "生成有10的元素的随机数链表:" << endl;
    printLink(head);
    head = recursiveReverseLinkList(head);
    cout << "对链表逆序后:" << endl;
    printLink(head);
}

int main(int argc, const char *argv[])
{
//    test();
    test1();
    return EXIT_SUCCESS;
}
