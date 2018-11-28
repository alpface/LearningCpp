//
//  02谓词.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/28.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 谓词是指普通函数或重载的operator()返回值是bool类型的函数对象(仿函数)。如果operator接受一个参数，那么叫做一元谓词,如果接受两个参数，那么叫做二元谓词，谓词可作为一个判断式。
 */

class GreaterThenFive {
    
public:
    bool operator()(int num)
    {
        return num > 5;
    }
};

// 一元谓词
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // GreaterThenFive()中的规则：找到大于5的迭代器
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterThenFive());
    if (it != v.end()) {
        cout << "*it = " << *it << endl;
    }
    else {
        cout << "没有找到" << endl;
    }
    
}

bool MyCompare(int v1, int v2)
{
    return v1 > v2;
}

// 二元谓词
void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(90);
    v.push_back(60);
    
    // 排序：默认是从小到大 升序
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // 自定义排序规则：MyCompare()中定义了从大到小，降序
    sort(v.begin(), v.end(), MyCompare);
//    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << endl;
    
    // lambda 表达式 [](int val){cout << val << endl;}
    for_each(v.begin(), v.end(), [](int val){
        cout << val << endl;
    });
}

int main(int argc, const char*argv[])
{
//    test01();
    test02();
    return EXIT_SUCCESS;
}
