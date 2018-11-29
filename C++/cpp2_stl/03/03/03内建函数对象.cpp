//
//  03内建函数对象.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/29.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <functional>
#include <vector>
using namespace std;
/*
 内建函数对象
 STL内建了一些函数对象。分为:算数类函数对象,关系运算类函数对象，逻辑运算类仿函数。这些仿函数所产生的对象，用法和一般函数完全相同，当然我们还可以产生无名的临时对象来履行函数功能。使用内建函数对象，需要引入头文件 #include<functional>。
 
 */

/*
 template<class T> T plus<T>//加法仿函数
 template<class T> T minus<T>//减法仿函数
 template<class T> T multiplies<T>//乘法仿函数
 template<class T> T divides<T>//除法仿函数
 template<class T> T modulus<T>//取模仿函数
 template<class T> T negate<T>//取反仿函数
 
     6个关系运算类函数对象,每一种都是二元运算。
 template<class T> bool equal_to<T>//等于
 template<class T> bool not_equal_to<T>//不等于
 template<class T> bool greater<T>//大于
 template<class T> bool greater_equal<T>//大于等于
 template<class T> bool less<T>//小于
 template<class T> bool less_equal<T>//小于等于
 
     逻辑运算类运算函数,not为一元运算，其余为二元运算。
 template<class T> bool logical_and<T>//逻辑与
 template<class T> bool logical_or<T>//逻辑或
 template<class T> bool logical_not<T>//逻辑非
 
 */

// 取反仿函数
void test01()
{
    negate<int> n;
    cout << n(60) << endl;
}

// 加法运算仿函数
void test02()
{
    plus<int> p;
    cout << p(10, 20) << endl;
}

// 大于仿函数
void test03()
{
//    greater<int> g;
//    cout << g(20, 10) << endl;
    
    vector<int> v;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; ++i) {
        v.push_back(rand() % 100);
    }
    cout << "排序前" << endl;
    for_each(v.begin(), v.end(),[](int val){
        cout << val << endl;
    });
    
    cout << "排序后" << endl;
    // greater<int>() 指定sort排序按照降序规则
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), [](int val){
         cout << val << endl;
    });
}

int main(int argc, const char *argv[])
{
//    test01();
//    test02();
    test03();
    return EXIT_SUCCESS;
}
