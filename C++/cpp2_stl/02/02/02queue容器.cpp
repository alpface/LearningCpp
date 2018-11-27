//
//  02queue容器.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/27.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

/*
 queue容器基本概念
 Queue是一种先进先出(First In First Out,FIFO)的数据结构，它有两个出口，queue容器允许从一端新增元素，从另一端移除元素。
 3.5.2 queue没有迭代器
 Queue所有元素的进出都必须符合”先进先出”的条件，只有queue的顶端元素，才有机会被外界取用。Queue不提供遍历功能，也不提供迭代器。
 
 */

/*
 queue常用API
 queue构造函数
 queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
 queue(const queue &que);//拷贝构造函数
 
 queue存取、插入和删除操作
 push(elem);//往队尾添加元素
 pop();//从队头移除第一个元素
 back();//返回最后一个元素
 front();//返回第一个元素
 
 queue赋值操作
 queue& operator=(const queue &que);//重载等号操作
 
 queue大小操作
 empty();//判断队列是否为空
 size();//返回队列的大小
 
 */

void test01()
{
    // 构造queue
    queue<int> q;
    // 向队尾添加元素
    q.push(10);
    q.push(11);
    q.push(20);
    q.push(28);
    
    cout << q.size() << endl;
    
    while (!q.empty()) {
        
        cout << "队头的元素:" << q.front() << endl;
        cout << "队尾的元素:" << q.back() << endl;
        // 从队头弹出元素
        q.pop();
    }
    
    cout << q.size() << endl;
}

int main(int argc, const char*argv[])
{
    test01();
    return EXIT_SUCCESS;
}
