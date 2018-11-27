//
//  04deque容器.cpp
//  01
//
//  Created by xiaoyuan on 2018/11/27.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
/*
 deque容器基本概念
 Vector容器是单向开口的连续内存空间，deque则是一种双向开口的连续线性空间。所谓的双向开口，意思是可以在头尾两端分别做元素的插入和删除操作，当然，vector容器也可以在头尾两端插入元素，但是在其头部操作效率奇差，无法被接受。
 Deque容器和vector容器最大的差异，一在于deque允许使用常数项时间对头端进行元素的插入和删除操作。二在于deque没有容量的概念，因为它是动态的以分段连续空间组合而成，随时可以增加一段新的空间并链接起来，换句话说，像vector那样，”旧空间不足而重新配置一块更大空间，然后复制元素，再释放旧空间”这样的事情在deque身上是不会发生的。也因此，deque没有必须要提供所谓的空间保留(reserve)功能.
 虽然deque容器也提供了Random Access Iterator,但是它的迭代器并不是普通的指针，其复杂度和vector不是一个量级，这当然影响各个运算的层面。因此，除非有必要，我们应该尽可能的使用vector，而不是deque。对deque进行的排序操作，为了最高效率，可将deque先完整的复制到一个vector中，对vector容器进行排序，再复制回deque.
 
 */

/*
 deque容器实现原理
 Deque容器是连续的空间，至少逻辑上看来如此，连续现行空间总是令我们联想到array和vector,array无法成长，vector虽可成长，却只能向尾端成长，而且其成长其实是一个假象，事实上(1) 申请更大空间 (2)原数据复制新空间 (3)释放原空间 三步骤，如果不是vector每次配置新的空间时都留有余裕，其成长假象所带来的代价是非常昂贵的。
 Deque是由一段一段的定量的连续空间构成。一旦有必要在deque前端或者尾端增加新的空间，便配置一段连续定量的空间，串接在deque的头端或者尾端。Deque最大的工作就是维护这些分段连续的内存空间的整体性的假象，并提供随机存取的接口，避开了重新配置空间，复制，释放的轮回，代价就是复杂的迭代器架构。
 既然deque是分段连续内存空间，那么就必须有中央控制，维持整体连续的假象，数据结构的设计及迭代器的前进后退操作颇为繁琐。Deque代码的实现远比vector或list都多得多。
 Deque采取一块所谓的map(注意，不是STL的map容器)作为主控，这里所谓的map是一小块连续的内存空间，其中每一个元素(此处成为一个结点)都是一个指针，指向另一段连续性内存空间，称作缓冲区。缓冲区才是deque的存储空间的主体。
 
 */

void printDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

/*
 deque常用API
 deque构造函数
 deque<T> deqT;//默认构造形式
 deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
 deque(n, elem);//构造函数将n个elem拷贝给本身。
 deque(const deque &deq);//拷贝构造函数。
 */

void test01()
{
    deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);
    printDeque(dq);
    
    deque<int> dq1(dq.begin(), dq.end());
    dq1.push_back(10000);
    printDeque(dq1);
    
    // 交换
    dq.swap(dq1);
    printDeque(dq);
    
    if (dq.empty()) {
        cout << "dq为空" << endl;
    }
    else {
        cout << "dq size:" << dq.size() << endl;
    }
}

/*
 deque赋值操作
 assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
 assign(n, elem);//将n个elem拷贝赋值给本身。
 deque& operator=(const deque &deq); //重载等号操作符
 swap(deq);// 将deq与本身的元素互换
 
 deque大小操作
 deque.size();//返回容器中元素的个数
 deque.empty();//判断容器是否为空
 deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
 deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
 
 deque双端插入和删除操作
 push_back(elem);//在容器尾部添加一个数据
 push_front(elem);//在容器头部插入一个数据
 pop_back();//删除容器最后一个数据
 pop_front();//删除容器第一个数据
 
 deque数据存取
 at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
 operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
 front();//返回第一个数据。
 back();//返回最后一个数据
 
 
 deque插入操作
 insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
 insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
 insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
 
 deque删除操作
 clear();//移除容器的所有数据
 erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
 erase(pos);//删除pos位置的数据，返回下一个数据的位置。
 
 */

void test02()
{
    deque<int> d;
    for (int i = 0 ;i < 10; ++i) {
        d.push_back(i);
    }
    
    // 尾删
    d.pop_back();
    // 头删
    d.pop_front();
    printDeque(d);
    
    cout << "front:" << d.front() << endl;
    cout << "back:" << d.back() << endl;
    
    // 插入数据
    deque<int> d1;
    d1.insert(d1.begin(), d.begin(), d.end());
    printDeque(d1);
}

bool myCompare(int v1, int v2)
{
    return v1 > v2;
}

// 排序sort
void test03()
{
    deque<int> d;
    d.push_back(111);
    d.push_back(45);
    d.push_back(29);
    d.push_back(89);
    printDeque(d);
    
    // 对dqueue进行排序
    // 默认是升序 从小到大
    sort(d.begin(), d.end());
    printDeque(d);
    
    // 根据用户的规则排序 myCompare
    sort(d.begin(), d.end(), myCompare);
    printDeque(d);
}

int main(int argc, const char*argv[])
{
//    test01();
//    test02();
    test03();
    return EXIT_SUCCESS;
}
