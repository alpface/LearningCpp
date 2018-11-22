//
//  03字符串类的封装.cpp
//  06
//
//  Created by xiaoyuan on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include "MyString.hpp"


void test()
{
    // 创建字符串
    MyString str = MyString("hello world");
    cout << str << endl;
    
    // 输入字符串
    cout << "请输入文本:";
    cin >> str;
    cout << "输入的内容为:" << str << endl;
    
    // 字符串判断
    MyString str1 = MyString("xiaoyuan");
    MyString str2 = "xiaoyuan";
    if (str1 == str2) {
        cout << "str1和str2相同" << endl;
    }
    else {
        cout << "str1和str2不相同" << endl;
    }
    
    // 字符串相加
    MyString str3(" 哈哈哈");
    MyString str4 = str1 + str3;
    cout << str4 << endl;
    
    // 字符串取值
    char subStr = str4[2];
    cout << subStr << endl;
    
}

int main(int argc, const char*atgv[])
{
    test();
    return EXIT_SUCCESS;
}
