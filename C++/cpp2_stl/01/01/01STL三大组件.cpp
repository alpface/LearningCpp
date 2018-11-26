//
//  01STL三大组件.cpp
//  01
//
//  Created by xiaoyuan on 2018/11/26.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
 STL简介
 
 STL（Standard Template Library，标准模板库)是惠普实验室开发的一系列软件的统称。它是由Alexander Stepanov、Meng Lee和David R Musser在惠普实验室工作时所开发出来
 
 的。现在虽说它主要出现在C++中，但在被引入C++之前该技术就已经存在了很长的一段时间。
 STL的代码从广义上讲分为三类：algorithm（算法）、container（容器）和iterator（迭代器），几乎所有的代码都采用了模板类和模版函数的方式，这相比于传统的由函数和类

 组成的库来说提供了更好的代码重用机会。在C++标准中，STL被组织为下面的13个头文件：<algorithm>、<deque>、<functional>、<iterator>、<vector>、<list>、<map>、
 
 <memory>、<numeric>、<queue>、<set>、<stack>和<utility>。
 
 STL六大组件简介
 STL提供了六大组件，彼此之间可以组合套用，这六大组件分别是:容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器。
 容器：各种数据结构，如vector、list、deque、set、map等,用来存放数据，从实现角度来看，STL容器是一种class template。
 算法：各种常用的算法，如sort、find、copy、for_each。从实现的角度来看，STL算法是一种function tempalte.
 迭代器：扮演了容器与算法之间的胶合剂，共有五种类型，从实现角度来看，迭代器是一种将operator* , operator-> , operator++,operator--等指针相关操作予以重载的class template. 所有STL容器都附带有自己专属的迭代器，只有容器的设计者才知道如何遍历自己的元素。原生指针(native pointer)也是一种迭代器。
 仿函数：行为类似函数，可作为算法的某种策略。从实现角度来看，仿函数是一种重载了operator()的class 或者class template
 适配器：一种用来修饰容器或者仿函数或迭代器接口的东西。
 空间配置器：负责空间的配置与管理。从实现角度看，配置器是一个实现了动态空间配置、空间管理、空间释放的class tempalte.
 
 STL六大组件的交互关系，容器通过空间配置器取得数据存储空间，算法通过迭代器存储容器中的内容，仿函数可以协助算法完成不同的策略的变化，适配器可以修饰仿函数。
 
 */

// 普通的指针也算一种迭代器

/*
 一、什么是vector？
 向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。跟任意其它类型容器一样，它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放任意类型的动态数组。
 二、容器特性
 1.顺序序列
 顺序容器中的元素按照严格的线性顺序排序。可以通过元素在序列中的位置访问对应的元素。
 2.动态数组
 支持对序列中的任意元素进行快速直接访问，甚至可以通过指针算述进行该操作。操供了在序列末尾相对快速地添加/删除元素的操作。
 3.能够感知内存分配器的（Allocator-aware）
 容器使用一个内存分配器对象来动态地处理它的存储需求。
 */

void test01()
{
    int arr[5] = {1, 3, 8, 4, 2};
    int *p = arr;
    for (int i = 0; i < 5; ++i) {
        
        cout << *(p++) << endl;

    }
}

void myPrint(int a)
{
    cout << a << endl;
}

// vector容器 操作基本数据类型
void test02()
{
    // 初始化容器
    vector<int> v;
    // 添加数据
    v.push_back(10);
    v.push_back(1);
    v.push_back(20);
    v.push_back(3);
    
    // itBegin指向的是数组中的起始位置
    vector<int>::iterator itBegin = v.begin();
    // itEnd指向的是数组中的最后一个的元素的下一个地址
    vector<int>::iterator itEnd = v.end();
    
    // 遍历容器中的迭代器
    // 第一种遍历方式
    while (itBegin != itEnd) {
        cout << *itBegin << endl;
        itBegin++;
    }
    cout << "----------------" << endl;
    // 第二种遍历方式
    for (vector<int>::iterator it = v.begin() ; it != v.end(); ++it) {
        cout << *it << endl;
    }
    cout << "----------------" << endl;
    // 第三种遍历方式：使用算法
    for_each(v.begin(), v.end(), myPrint);
    cout << "----------------" << endl;
}

class Person {
    
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

// 存放自定义数据类型
void test03()
{
    Person p1("xxiaoyuan", 18);
    Person p2("ketao", 20);
    Person p3("haha", 18);
    Person p4("tom", 27);
    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    
    for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << (*it).m_name << " " << (*it).m_age << endl;
    }
}

// vector存放自定义数据类型的指针
void test04()
{
    Person p1("xxiaoyuan", 18);
    Person p2("ketao", 20);
    Person p3("haha", 18);
    Person p4("tom", 27);
    vector<Person*> v;
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << (*it)->m_name << " " << (*it)->m_age << endl;
    }
}

// vector嵌套vector容器
void test05()
{
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for (int i = 0; i < 5; ++i) {
        v1.push_back(i);
        v2.push_back(i + 100);
        v3.push_back(i + 200);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    
    // 遍历
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it) {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit) {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main(int argc, const char *argv[])
{
//    test01();
//    test02();
//    test03();
    test05();
    return EXIT_SUCCESS;
}
