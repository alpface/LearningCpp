//
//  12类模板的应用-数组类封装.cpp
//  08
//
//  Created by swae on 2018/11/25.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "MyArray.hpp"

// 数组中添加基本数据类型
void printIntArray(MyArray<int> arr)
{
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << endl;
    }
}

void test()
{
    MyArray<int> intArr(10);
    intArr.push_back(10);
    intArr.push_back(20);
    intArr.push_back(30);
    printIntArray(intArr);
    cout << "------------" << endl;
    
    MyArray<int> intArr1 = intArr;
    printIntArray(intArr1);
    
    cout << "------------" << endl;
}

// 2 数组中添加自定义类型

template <class T1, class T2>
class Person {
    
public:
    Person(){};
    Person(T1 name, T2 age);
    void showPerson();
    T1 m_name;
    T2 m_age;
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
}
template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
    
    cout << "姓名:" << this->m_name << " 年龄:" << this->m_age << endl;
}

void printPersonArray(MyArray<Person<string, int>> arr)
{
    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i].showPerson();
    }
}

void test02()
{
    
    // 注意: 如果向数组中添加自定义类型，这个自定义类型必须有默认构造函数，不然编译不过
    Person<string, int> p1("xiaoyuan", 18);
    Person<string, int> p2("ketao", 18);
    Person<string, int> p3("hello", 10);
    Person<string, int> p4("word", 19);
    MyArray<Person<string, int>> arr(10);
    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    printPersonArray(arr);
}

int main(int argc, const char*argv[])
{
//    test();
    test02();
    return EXIT_SUCCESS;
}
