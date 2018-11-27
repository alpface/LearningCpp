//
//  01stack栈容器.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/27.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

/*
 stack容器
 stack容器基本概念
 stack是一种先进后出(First In Last Out,FILO)的数据结构，它只有一个出口，形式如图所示。stack容器允许新增元素，移除元素，取得栈顶元素，但是除了最顶端外，没有任何其他方法可以存取stack的其他元素。换言之，stack不允许有遍历行为。
 有元素推入栈的操作称为:push,将元素推出stack的操作称为pop.
 
 stack没有迭代器
 Stack所有元素的进出都必须符合”先进后出”的条件，只有stack顶端的元素，才有机会被外界取用。Stack不提供遍历功能，也不提供迭代器。
 
 */

/*
 stack常用API
 stack构造函数
 stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式：
 stack(const stack &stk);//拷贝构造函数
 
 stack赋值操作
 stack& operator=(const stack &stk);//重载等号操作符
 
 stack数据存取操作
 push(elem);//向栈顶添加元素
 pop();//从栈顶移除第一个元素
 top();//返回栈顶元素
 
 stack大小操作
 empty();//判断堆栈是否为空
 size();//返回堆栈的大小
 
 */

void test01()
{
    stack<int> s;
    s.push(1);
    s.push(10);
    s.push(19);
    s.push(28);
    cout << "栈中元素个数:" << s.size() << endl;
    while (s.size() != 0) {
        cout << "栈顶元素:" << s.top() << " ";
        // 弹出栈顶元素
        s.pop();
    }
    cout << endl;
    
    cout << "栈中元素个数:" << s.size() << endl;
}

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
