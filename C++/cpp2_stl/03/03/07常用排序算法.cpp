//
//  07常用排序算法.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/30.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 merge算法 容器元素合并，并存储到另一容器中
 @param beg1 容器1开始迭代器
 @param end1 容器1结束迭代器
 @param beg2 容器2开始迭代器
 @param end2 容器2结束迭代器
 @param dest  目标容器开始迭代器
 */
//merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest)

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i+100);
        v2.push_back(i+200);
    }
    
    vector<int> vTarget;
    vTarget.resize(v1.size()+v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), [](int val){
        cout << val << " ";
    });
    cout << endl;
}

/*
 sort算法 容器元素排序
 注意:两个容器必须是有序的
 @param beg 容器1开始迭代器
 @param end 容器1结束迭代器
 @param _callback 回调函数或者谓词(返回bool类型的函数对象)
 */
//sort(iterator beg, iterator end, _callback)
void test02()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(18);
    v.push_back(17);
    v.push_back(189);
    v.push_back(26);
    
    // 默认升序
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int v){
        cout << v << " ";
    });
    cout << endl;
    
    // 降序
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), [](int v){
        cout << v << " ";
    });
    cout << endl;
}
/*
 sort算法 对指定范围内的元素随机调整次序
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 */
//random_shuffle(iterator beg, iterator end)
void test03()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int val){
        cout << val << " ";
    });
    cout << endl;
}
/*
 reverse算法 反转指定范围的元素
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 */
//reverse(iterator beg, iterator end)
void test04()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int val){
       cout << val << " ";
    });
    cout << endl;
}

int main(int argc, const char*argv[])
{
//    test01();
//    test02();
//    test03();
    test04();
    return EXIT_SUCCESS;
}
