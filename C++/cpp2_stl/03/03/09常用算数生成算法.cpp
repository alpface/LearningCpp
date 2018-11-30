//
//  09常用算数生成算法.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/30.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>
using namespace std;

/*
 accumulate算法 计算容器元素累计总和
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param value累加值
 */
//accumulate(iterator beg, iterator end, value)
void test01()
{
    // 计算1~100之间所有数字的总和
    vector<int> v;
    for (int i = 0; i <= 100; ++i) {
        v.push_back(i);
    }
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;
}
/*
 fill算法 向容器中添加元素
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param value t填充元素
 */
//fill(iterator beg, iterator end, value)
void test02()
{
    vector<int> v;
    v.resize(10);
    fill(v.begin(), v.end(), 1000);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main(int argc, const char*argv[])
{
//    test01();
    test02();
    return EXIT_SUCCESS;
}
