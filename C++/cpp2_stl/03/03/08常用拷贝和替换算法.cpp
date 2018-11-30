//
//  08常用拷贝和替换算法.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/30.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

/*
 copy算法 将容器内指定范围的元素拷贝到另一容器中
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param dest 目标起始迭代器
 */
//copy(iterator beg, iterator end, iterator dest)
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    vector<int> vTarget;
    vTarget.resize(v.size());
    copy(v.begin(), v.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), [](int v){
        cout << v << " ";
    });
    cout << endl;
    
    copy(vTarget.begin(), vTarget.end(), ostream_iterator<int>(cout , " "));
}
/*
 replace算法 将容器内指定范围的旧元素修改为新元素
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param oldvalue 旧元素
 @param oldvalue 新元素
 */
//replace(iterator beg, iterator end, oldvalue, newvalue)
class GreatherThenFive {
    
public:
    bool operator()(int v) const
    {
        return v >= 5;
    }
};
void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 把容器中的2替换为1000；
    replace(v.begin(), v.end(), 2, 1000);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
}

/*
 replace_if算法 将容器内指定范围满足条件的元素替换为新元素
 @param beg 容器开始迭代器
 @param end 容器结束迭代器
 @param callback函数回调或者谓词(返回Bool类型的函数对象)
 @param oldvalue 新元素
 */
//replace_if(iterator beg, iterator end, _callback, newvalue)
void test03()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 把容器中大于等于5的数字替换为3000；
    replace_if(v.begin(), v.end(), GreatherThenFive(), 3000);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}
/*
 swap算法 互换两个容器的元素
 @param c1容器1
 @param c2容器2
 */
//swap(container c1, container c2)
void test04()
{
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(38);
    v2.push_back(19);
    v2.push_back(12);
    
    cout << "交换前的数据:"<< endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    swap(v1, v2);
    
    cout << "交换后的数据:"<< endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
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
