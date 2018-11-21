//
//  03c++ 类成员变量，成员函数的存储方式，以及this指针在c++中的作用.cpp
//  04
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//  c/c++ 类成员变量，成员函数的存储方式，以及this指针在c++中的作用

#include <iostream>

/*
 c++不会为每一个对象的成员变量和成员函数开辟内存空间，
 而是只为每一个对象的成员变量开辟空间。成员函数的只开辟一个共用的空间，所有对象的都可以访问这个公共的空间。
 */

/*
 但是就产生了一个问题，当某一个对象去调用某个成员函数的时候，这个成员函数怎么才能知道是哪个对象调用的它呢？
 
 c++在某一个对象调用某个成员函数的时候，把这个对象的地址，隐式地作为这个函数的参数，传给了成员函数，所有可以在没成员函数里显示的使用this指针。
 
 可以用下面的程序验证上面的理论。
 打印类占用内存的大小和对象占用内存的大小，就可以看出来，只有成员变量占用的内存空间（注意，内存对齐）。
 */

using namespace std;

class CGood{
    
    int amount;   // 非静态成员属性，属于对象本身  占用4个字节
    double value; // 非静态成员属性，属于对象本身 占用8个字节
    static float price; // 静态成员属性，不属于对象本身，共享数据
    char *getName();   // 成员方法不属于对象本身
    
    // CGood 的 内存大小只会计算存储在对象本身的成员：
    // int amount;   占用4个字节  double value; 占用8个字节 因为内存对齐，所以 CGood的大小为16
};

int main(int main, const char *argv[]){
    cout << sizeof(CGood) <<endl;
    CGood c1;
    cout << sizeof(c1) <<endl;
}
