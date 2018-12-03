//
//  04适配器.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/30.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
/*
 函数适配器
 先弄清几个概念，什么叫一元函数，二元函数
 
 1. 一元函数一个参数
 2. 二元函数 两个参数
 3. 一元谓词 一个参数，返回类型为bool型
 4. 二元谓词 两个参数，返回类型为bool型
 
 函数适配器是用来让一个函数对象表现出另外一种类型的函数对象的特征。因为，许多情况下，我们所持有的函数对象或普通函数的参数个数或是返回值类型并不是我们想要的，这时候就需要函数适配器来为我们的函数进行适配
 
 
 
 C++中有三类适配器，分别是容器适配器，迭代器适配器和函数适配器，这里主要介绍函数适配器。
 函数适配器用于特化和扩展一元二元函数对象，函数适配器主要有以下两类：
 1 绑定器
 
 该类适配器用于将二元函数适配成一元函数
 
 将二元函数的一个参数绑定到一个特定的值上，将二元函数对象转换成一元函数对象。
 绑定器适配器有两种：bind1st bind2nd。每个绑定器接受一个函数对象和一个值
 bind1st将给定值绑定到二元函数对象的第一个实参
 bind2nd将给定值绑定到二元函数对象的第二个实参
 */

class MyPrint:public binary_function<int, int, void>
{
public:
    void operator()(int v, int start) const
    {
        cout << "v = " << v << " start = " << start << endl;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    
    cout << "请输入起始值:";
    int num;
    cin >> num;
    
    // bind2nd将给定值绑定到二元函数对象的第二个实参
//    for_each(v.begin(), v.end(), bind2nd(MyPrint(), num));
    // bind1st将给定值绑定到二元函数对象的第一个实参
    for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
}


/*
 取反器 将函数对象的结果真值求反
 取反器有两种:not1和not2
 not1是对一元函数对象求反的取反器，传递给函数对象的只有一个参数，则要使用这个not1
 not2是对二元函数对象求反的取反器
 例子
 int* where=find_if(&array[0],&array[100],not1(bind2nd(breater<int>(),200)))
 */
// 取反适配
// 一元取反 not1
// 继承自unary_function<class _Arg, class _Result>
// const 修饰()操作符
class GreaterThenFive:public unary_function<int, bool>
{
public:
    bool operator()(int num) const
    {
        return num > 5;
    }
};


void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    
    // 查找大于5的数字
    vector<int>::iterator pos1 = find_if(v.begin(), v.end(), GreaterThenFive());
    if (pos1 != v.end()) {
        cout << "找到大于5的数字:" << *pos1 << endl;
    }
    else {
        cout << "未找到" << endl;
    }
    
    
    // 查找小于5的数字
//    vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind1st(greater<int>(), 5)));
    vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(GreaterThenFive()));
    if (pos != v.end()) {
        cout << "找到小于5的数字:" << *pos << endl;
    }
    else {
        cout << "未找到" << endl;
    }
}

// 函数指针适配器
void myPrint(int a, int b)
{
    cout << a + b << endl;
}
void test03()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 将函数指针适配为函数对象
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint), 100));
}

// 成员函数适配器
class Person {
    
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    void showPerson()
    {
        cout << "name:" << this->m_name << " age:" << this->m_age << endl;
    }
    void plusAge()
    {
        this->m_age += 100;
    }
    string m_name;
    int m_age;
};
void test04()
{
    vector<Person> v;
    Person p("xiaoyuan", 19);
    Person p1("ketao", 20);
    Person p2("haha", 30);
    v.push_back(p);
    v.push_back(p1);
    v.push_back(p2);
    
    // 成员函数适配器 mem_fun_ref
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::plusAge));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

int main(int argc, const char *argv[])
{
//    test01();
//    test02();
//    test03();
    test04();
    return EXIT_SUCCESS;
}
