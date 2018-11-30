//
//  10常用集合算法.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/30.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 set_intersection算法 求两个set集合的交集
 注意:两个集合必须是有序序列
 @param beg1 容器1开始迭代器
 @param end1 容器1结束迭代器
 @param beg2 容器2开始迭代器
 @param end2 容器2结束迭代器
 @param dest  目标容器开始迭代器
 @return 目标容器的最后一个元素的迭代器地址
 */
//set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    
    vector<int> vTarget;
    vTarget.resize(min(v1.size(), v2.size()));
    
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
    cout << endl;
}
/*
 set_union算法 求两个set集合的并集
 注意:两个集合必须是有序序列
 @param beg1 容器1开始迭代器
 @param end1 容器1结束迭代器
 @param beg2 容器2开始迭代器
 @param end2 容器2结束迭代器
 @param dest  目标容器开始迭代器
 @return 目标容器的最后一个元素的迭代器地址
 */
//set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
void test02()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    
    vector<int> vTarget;
    vTarget.resize(v1.size() + v2.size());
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
    cout << endl;
}
/*
 set_difference算法 求两个set集合的差集
 注意:两个集合必须是有序序列
 @param beg1 容器1开始迭代器
 @param end1 容器1结束迭代器
 @param beg2 容器2开始迭代器
 @param end2 容器2结束迭代器
 @param dest  目标容器开始迭代器
 @return 目标容器的最后一个元素的迭代器地址
 */
//set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)
void test03()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    
    vector<int> vTarget;
    vTarget.resize(max(v1.size(), v2.size()));
    
    // v1差v2
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
    cout << endl;
    
    // v2差v1
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main(int argc, const char*argv[])
{
//    test01();
//    test02();
    test03();
    return EXIT_SUCCESS;
}
