//
//  03list容器.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/27.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

/*
 list容器
 list容器基本概念
 链表是一种物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。链表由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。
 相较于vector的连续线性空间，list就显得负责许多，它的好处是每次插入或者删除一个元素，就是配置或者释放一个元素的空间。因此，list对于空间的运用有绝对的精准，一点也不浪费。而且，对于任何位置的元素插入或元素的移除，list永远是常数时间。
 List和vector是两个最常被使用的容器。
 List容器是一个双向链表。
 
 1    采用动态存储分配，不会造成内存浪费和溢出
 2    链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
 3    链表灵活，但是空间和时间额外耗费较大
 
 list容器的迭代器
 List容器不能像vector一样以普通指针作为迭代器，因为其节点不能保证在同一块连续的内存空间上。List迭代器必须有能力指向list的节点，并有能力进行正确的递增、递减、取值、成员存取操作。所谓”list正确的递增，递减、取值、成员取用”是指，递增时指向下一个节点，递减时指向上一个节点，取值时取的是节点的数据值，成员取用时取的是节点的成员。
 由于list是一个双向链表，迭代器必须能够具备前移、后移的能力，所以list容器提供的是Bidirectional Iterators.
 List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效。这在vector是不成立的，因为vector的插入操作可能造成记忆体重新配置，导致原有的迭代器全部失效，甚至List元素的删除，也只有被删除的那个元素的迭代器失效，其他迭代器不受任何影响。
 
 list容器的数据结构
 list容器不仅是一个双向链表，而且还是一个循环的双向链表。
 
 */

// list是双向链表结构
//void test01()
//{
//    list<int> myList;
//    for (int i = 0; i < 10; i ++){
//        myList.push_back(i);
//    }
//
//    list<int>::_Nodeptr node =  myList._Myhead->_Next;
//
//    for (int i = 0; i < myList._Mysize * 2;i++){
//        cout << "Node:" << node->_Myval << endl;
//        node = node->_Next;
//        if (node == myList._Myhead){
//            node = node->_Next;
//        }
//    }
//
//    
//}


/*
 list常用API
 
 list构造函数
 list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
 list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
 list(n,elem);//构造函数将n个elem拷贝给本身。
 list(const list &lst);//拷贝构造函数。
 
 list数据元素插入和删除操作
 push_back(elem);//在容器尾部加入一个元素
 pop_back();//删除容器中最后一个元素
 push_front(elem);//在容器开头插入一个元素
 pop_front();//从容器开头移除第一个元素
 insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
 insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
 insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
 clear();//移除容器的所有数据
 erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
 erase(pos);//删除pos位置的数据，返回下一个数据的位置。
 remove(elem);//删除容器中所有与elem值匹配的元素。
 
 
*/

void printList(list<int> &myList)
{
    for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " " ;
    }
    cout << endl;
}

void test02()
{
    // 构造一个list 10个元素为10的list
    list<int> myList(10, 10);
    // 将myList的起始和结尾区间拷贝给myList1
    list<int> myList1(myList.begin(), myList.end());
    printList(myList);
    printList(myList1);
    
    // 尾部插入数据
    myList1.push_back(888);
    printList(myList1);
    
    // 逆序迭代器
    for (list<int>::reverse_iterator it = myList1.rbegin(); it != myList1.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // list迭代器不支持随机数访问
//    list<int>::iterator itBegin = myList1.begin();
//    itBegin += 1;
    
    // 尾部插入
    myList1.push_back(99);
    // 头部插入
    myList1.push_front(1);
    printList(myList1);
    
    // 插入数据
    // 在myList1的begin位置插入666
    myList1.insert(myList1.begin(), 666);
    printList(myList1);
    
    // 删除容器中所有是10的元素
    myList1.remove(10);
    printList(myList1);
}

/*
 
 list大小操作
 size();//返回容器中元素的个数
 empty();//判断容器是否为空
 resize(num);//重新指定容器的长度为num，
 若容器变长，则以默认值填充新位置。
 如果容器变短，则末尾超出容器长度的元素被删除。
 resize(num, elem);//重新指定容器的长度为num，
 若容器变长，则以elem值填充新位置。
 如果容器变短，则末尾超出容器长度的元素被删除。
 
 list赋值操作
 assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
 assign(n, elem);//将n个elem拷贝赋值给本身。
 list& operator=(const list &lst);//重载等号操作符
 swap(lst);//将lst与本身的元素互换。
 
 
 list数据的存取
 front();//返回第一个元素。
 back();//返回最后一个元素。

 */

void test03()
{
    list<int> myList;
    myList.push_front(3);
    myList.push_front(2);
    myList.push_front(1);
    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(6);
    printList(myList);
    cout << "myList size = " << myList.size() << endl;
    
    if (myList.empty()) {
        cout << "myList 中没有元素" << endl;
    }
    else
    {
        cout << "myList中有元素" << endl;
    }
    
    // 重置list容量的大小
    myList.resize(10);
    printList(myList);
    
    myList.resize(3);
    printList(myList);
    
    // 赋值操作
    list<int> myList1;
    myList1.assign(myList.begin(), myList.end());
    
    cout << "front:" << myList1.front() << endl;
    cout << "front:" << myList1.back() << endl;
}

/*
 list反转排序
 reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
 sort(); //list排序
 
 */

bool myCompare(int v1, int v2)
{
    return v1 > v2;
}

void test04()
{
    // 构造list
    list<int> myList;
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(80);
    myList.push_back(10);
    myList.push_back(40);
    
    printList(myList);
    
    // 数组反转
    myList.reverse();
    printList(myList);
    
    // 注意：所有不支持随机数访问的迭代器，都不可以使用系统提供的算法
    // 如果不支持系统内部提供的算法，那么这个类的内部会提供，可以使用对象调用
    // 数组排序
    myList.sort(); // 默认升序
    printList(myList);
    
    myList.sort(myCompare); // 使用自己的规则排序
    printList(myList);
}

// 自定义类型排序
class Person {
    
public:
    Person(){};
    Person(string name, int age, double height):m_name(name), m_age(age), m_height(height){}
    // 重载==运算符，让list的remove可以删除自定义类型
    bool operator==(const Person &p) const// 注意重载此函数需要加上const，将其定义为常函数，不然在mac上无法编译通过
    {
        if (this->m_name.compare(p.m_name) == 0 && this->m_age == p.m_age && this->m_height == p.m_height) {
            return true;
        }
        return false;
    }
    
    int m_age;
    double m_height;
    string m_name;
};

bool myPersonCompare(Person &p1, Person &p2)
{
    if (p1.m_age == p2.m_age) {
        return p1.m_height > p2.m_height;
    }
    return p1.m_age > p2.m_age;
}

void test05()
{
    list<Person> myList;
    Person p1("洪克涛", 20, 178);
    Person p2("xiaoyuan", 18, 158);
    Person p3("巴巴", 20, 168);
    Person p4("啦啦", 19, 198);
    Person p5("啦啦", 19, 188);
    myList.push_back(p1);
    myList.push_back(p2);
    myList.push_back(p3);
    myList.push_back(p4);
    myList.push_back(p5);
    
    // 对于自定义数据类型，必须制定排序规则
    myList.sort(myPersonCompare);
    for (list<Person>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << "姓名:" << it->m_name << " 年龄:" << it->m_age << " 高度:" << it->m_height << endl;
    }
    cout << "--------" << endl;
    // 删除巴巴
    myList.remove(p3); // remove自定义类型必须要重载自定义类型的==操作符，不然无法编译过
    for (list<Person>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << "姓名:" << it->m_name << " 年龄:" << it->m_age << " 高度:" << it->m_height << endl;
    }
}

int main(int argc, const char*argv[])
{
//    test02();
//    test03();
//    test04();
    test05();
    return EXIT_SUCCESS;
}
