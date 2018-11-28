//
//  06map容器.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/28.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <map>

/*
 map/multimap容器
 3.8.1 map/multimap基本概念
 Map的特性是，所有元素都会根据元素的键值自动排序。Map所有的元素都是pair,同时拥有实值和键值，pair的第一元素被视为键值，第二元素被视为实值，map不允许两个元素有相同的键值。
 我们可以通过map的迭代器改变map的键值吗？答案是不行，因为map的键值关系到map元素的排列规则，任意改变map键值将会严重破坏map组织。如果想要修改元素的实值，那么是可以的。
 Map和list拥有相同的某些性质，当对它的容器元素进行新增操作或者删除操作时，操作之前的所有迭代器，在操作完成之后依然有效，当然被删除的那个元素的迭代器必然是个例外。
 Multimap和map的操作类似，唯一区别multimap键值可重复。
 Map和multimap都是以红黑树为底层实现机制。
 
 */

using namespace std;

/*
 map/multimap常用API
 3.8.2.1 map构造函数
 map<T1, T2> mapTT;//map默认构造函数:
 map(const map &mp);//拷贝构造函数
 
 
 3.8.2.2 map赋值操作
 map& operator=(const map &mp);//重载等号操作符
 swap(mp);//交换两个集合容器
 
 3.8.2.3 map大小操作
 size();//返回容器中元素的数目
 empty();//判断容器是否为空
 3.8.2.4 map插入数据元素操作
 map.insert(...); //往容器插入元素，返回pair<iterator,bool>
 map<int, string> mapStu;
 // 第一种 通过pair的方式插入对象
 mapStu.insert(pair<int, string>(3, "小张"));
 // 第二种 通过pair的方式插入对象
 mapStu.inset(make_pair(-1, "校长"));
 // 第三种 通过value_type的方式插入对象
 mapStu.insert(map<int, string>::value_type(1, "小李"));
 // 第四种 通过数组的方式插入值
 mapStu[3] = "小刘";
 mapStu[5] = "小王";
 
 */

void printMap(map<int, int> &m1)
{
    for (map<int, int>::iterator it = m1.begin(); it != m1.end(); ++it) {
        cout << "key:" << it->first << " value:" << it->second << endl;
    }
}

void test01()
{
    // map的四种插入数据方式
    map<int, int> m1;
    // 第一种
    m1.insert(pair<int, int>(10, 20));
    // 第二种
    m1.insert(make_pair(20, 30));
    // 第三种
    m1.insert(map<int, int>::value_type(1, 2200));
    // 第四种，不推荐使用
    m1[18] = 99;
    
    printMap(m1);
    // map默认的排序方式是按照key的大小升序排序
    
    // 当使用m1[]取一个不存在的key时，map会把这个不存在的key插入到map中，并把value设置0，比如
    cout << m1[22] << endl;
    // m1[22] 22是不存在的key，此时map中会多出key:22 value:0
    printMap(m1);
}

/*
 
 3.8.2.5 map删除操作
 clear();//删除所有元素
 erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
 erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
 erase(keyElem);//删除容器中key为keyElem的对组。
 3.8.2.6 map查找操作
 find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
 count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
 lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
 upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
 c
 
 */

void test02()
{
    // map的查找
    map<int, int> m1;
    m1.insert(make_pair(10, 20));
    m1.insert(make_pair(20, 100));
    m1.insert(make_pair(30, 87));
    m1.insert(make_pair(9, 19));
    printMap(m1);
    
    // find()
    // 在map中查找key为20，返回值迭代器，如果没找到，这个迭代器将指向map的end
    map<int, int>::iterator ret1 = m1.find(20);
    if (ret1 != m1.end()) {
        cout << "找到了, key:" << ret1->first << " value:" << ret1->second << endl;
    }
    else{
        cout << "没找到" << endl;
    }
    
    // lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    map<int, int>::iterator lower1 = m1.lower_bound(10);
    if (lower1 != m1.end()) {
        cout << "找到了lower_bound, key:" << lower1->first << " value:" << lower1->second << endl;
    }
    else {
        cout << "没找到" << endl;
    }
    // upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    map<int , int>::iterator upper1 = m1.upper_bound(30);
    if (upper1 != m1.end()) {
        cout << "找到了upper_bound, key:" << upper1->first << " value:" << upper1->second << endl;
    }
    else {
        cout << "没找到" << endl;
    }
    // equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    pair<map<int, int>::iterator, map<int, int>::iterator> equal_range = m1.equal_range(9);
    if (equal_range.first != m1.end()) {
        cout << "找到了equal_range.first，key:" << equal_range.first->first << " value:" << equal_range.first->second << endl;
    }
    else{
        cout << "没找到" << endl;
    }
    if (equal_range.second != m1.end()) {
        cout << "找到了equal_range.second，key:" << equal_range.second->first << " value:" << equal_range.second->second << endl;
    }
}

/*
 指定排序规则
 */

class MyMapCompare {
    
public:
    bool operator()(int v1, int v2) const // 注意重载此函数需要加上const，将其定义为常函数，不然在mac上无法编译通过
    {
        return v1 > v2;
    }
};

void test03()
{
    map<int, int, MyMapCompare> m1;
    m1.insert(make_pair(10, 20));
    m1.insert(make_pair(8, 19));
    m1.insert(make_pair(7, 18));
    m1.insert(make_pair(19, 19));
    m1.insert(make_pair(6, 19));
    
    for (map<int, int, MyMapCompare>::iterator it = m1.begin(); it != m1.end(); ++it) {
        cout << "key:" << it->first << " value:" << it->second << endl;
    }
}


int main(int argc, const char**argv)
{
//    test01();
//    test02();
    test03();
    return EXIT_SUCCESS;
}
