//
//  06常用查找算法.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/30.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
 find算法 查找元素
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param value 查找的元素
 @return 返回查找元素的位置
 */
//find(iterator beg, iterator end, value)
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 找到vector中元素5所在的迭代器
    vector<int>::iterator pos = find(v.begin(), v.end(), 5);
    if (pos != v.end()) {
        cout << "找到了:" <<*pos << endl;
    }
    else {
        cout << "没找到" << endl;
    }
    cout << endl;
}
// 通过find查找自定义数据类型
class Person {
    
public:
    Person(string name, int age):m_name(name), m_age(age){}
    bool operator==(const Person &p1)
    {
        if (this->m_name == p1.m_name && this->m_age == p1.m_age) {
            return true;
        }
        return false;
    }
    string m_name;
    int m_age;
};
void test02()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 29);
    Person p3("ccc", 18);
    Person p4("ddd", 16);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    // 在vector查找person
    vector<Person>::iterator pos = find(v.begin(), v.end(), p3);
    if (pos != v.end()) {
        cout << "找到了，姓名：" <<  pos->m_name  << "年龄：" <<  pos->m_age << endl;
    }
}

/*
 find_if算法 条件查找
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param  callback 回调函数或者谓词(返回bool类型的函数对象)
 @return bool 查找返回true 否则false
 */
//find_if(iterator beg, iterator end, _callback);
class MyCompare:public binary_function<Person *, Person *, bool>
{
public:
    bool operator()(Person *p1, Person *p2) const
    {
        if (p1->m_name == p2->m_name && p1->m_age == p2->m_age) {
            return true;
        }
        return false;
    }
};
void test03()
{
    // 根据指针查找自定义类型
    vector<Person*> v;
    Person p1("aaa", 10);
    Person p2("bbb", 29);
    Person p3("ccc", 18);
    Person p4("ddd", 16);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    
    vector<Person *>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare(), &p3));
    if (pos != v.end()) {
        cout << "姓名:" << (*pos)->m_name << " 年龄:" << (*pos)->m_age << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
}

/*
 adjacent_find算法 查找相邻重复元素
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param  _callback 回调函数或者谓词(返回bool类型的函数对象)
 @return 返回相邻元素的第一个位置的迭代器
 */
//adjacent_find(iterator beg, iterator end, _callback);

void test04()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(10);
    v.push_back(13);
    v.push_back(13);
    v.push_back(13);
    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos != v.end()) {
        cout << *pos << endl;
    }
    else {
        cout << "没找到" << endl;
    }
}
/*
 binary_search算法 二分查找法
 注意: 在无序序列中不可用
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param value 查找的元素
 @return bool 查找返回true 否则false
 */
//bool binary_search(iterator beg, iterator end, value);
void test05()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    bool ret = binary_search(v.begin(), v.end(), 3);
    if (ret) {
        cout << "找到了3" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
}
/*
 count算法 统计元素出现次数
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param  value回调函数或者谓词(返回bool类型的函数对象)
 @return int返回元素个数
 */
//count(iterator beg, iterator end, value);
/*
 count算法 统计元素出现次数
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param  callback 回调函数或者谓词(返回bool类型的函数对象)
 @return int返回元素个数
 */
class GreaterThenFour
{
public:
    bool operator()(int val) const
    {
        return val >= 3;
    }
};

void test06()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    v.push_back(3);
    v.push_back(3);
    // 统计3在vector出现的次数
    int num = count(v.begin(), v.end(), 3);
    cout << "3出现的次数:" << num << endl;
    
    // 统计大于等于3的数的个数
    num = count_if(v.begin(), v.end(), GreaterThenFour());
    cout << "大于等于3的数的个数:" << num << endl;
}


int main(int argc, const char *argv[])
{
//    test01();
//    test02();
//    test03();
//    test04();
    test06();
    return EXIT_SUCCESS;
}
