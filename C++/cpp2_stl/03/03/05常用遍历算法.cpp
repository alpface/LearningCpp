//
//  05常用遍历算法.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/30.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

/*
 遍历算法: 遍历容器元素
 @param begin 开始迭代器
 @param end 结束迭代器
 @param _callback 函数回调 或者 函数对象
 @return 函数对象
 */

// 1.for_each的函数回调和函数对象
void myPrint(int v)
{
    cout <<  v << endl;
}

struct MyPrint {
    void operator()(int v)
    {
        cout <<  v << endl;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 函数回调
//    for_each(v.begin(), v.end(), myPrint);
    // 函数对象
    for_each(v.begin(), v.end(), MyPrint());
}

// 2.for_each的函数返回值
struct MyPrint2 {
    void operator()(int v)
    {
        cout << v << endl;
        this->m_count++;
    }
    int m_count;
};
void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    MyPrint2 p = for_each(v.begin(), v.end(), MyPrint2());
    cout << "打印次数:" << p.m_count << endl;
}

// 3.for_each 绑定参数输出
struct MyPrint3:public binary_function<int, int, void> {
    void operator()(int v, int start) const
    {
        cout << "v = " << v << " start = " << start << endl;
    }
};
void test03()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), bind2nd(MyPrint3(), 100));
}

/*
 transfrom 将指定容器区间的元素搬到另一容器中
 @note: transfrom 不会给目标容器分配内存，所以我们需要提前给目标容器分配好内存
 @param beg1 源容器开始迭代的迭代器
 @param end1 源容器结束迭代的迭代器
 @param beg2 目标容器开始迭代的迭代器
 @param _callback 函数的回调或函数对象
 @return 返回目标容器的迭代器
 */
class Transform
{
public:
    int operator()(int v) const
    {
        return v + 10;
    }
};

void test04()
{
    // 定义源容器
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 定义目标容器
    vector<int> vTarget;
    // 为目标容器分配内存
    vTarget.resize(v.size());
    transform(v.begin(), v.end(), vTarget.begin(), Transform());
    for_each(vTarget.begin(), vTarget.end(), [](int val){
        cout << val << endl;
    });
}

struct Transform2 {
    int operator()(int v1, int v2) const
    {
        return v1+v2;
    }
};

// transfrom 将两个容器的数据相加，搬到目标容器中
void test05()
{
    // 源容器
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(100+i);
        v2.push_back(200+i);
    }
    // 目标容器
    vector<int> v3;
    v3.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), Transform2());
    for_each(v3.begin(), v3.end(), [](int v){
        cout << v << endl;
    });
}

int main(int argc, const char*argv[])
{
//    test01();
//    test02();
//    test03();
//    test04();
    test05();
    return EXIT_SUCCESS;
}
