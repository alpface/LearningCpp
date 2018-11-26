//
//  02string容器.cpp
//  01
//
//  Created by xiaoyuan on 2018/11/26.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

/*
 string容器
 string容器基本概念
 C风格字符串(以空字符结尾的字符数组)太过复杂难于掌握，不适合大程序的开发，所以C++标准库定义了一种string类，定义在头文件<string>。
 String和c风格字符串对比：
     Char*是一个指针，String是一个类
 string封装了char*，管理这个字符串，是一个char*型的容器。
     String封装了很多实用的成员方法
 查找find，拷贝copy，删除delete 替换replace，插入insert
     不用考虑内存释放和越界
 string管理char*所分配的内存。每一次string的复制，取值都由string类负责维护，不用担心复制越界和取值越界等。
 
 */

/*
 string 构造函数
 string();//创建一个空的字符串 例如: string str;
 string(const string& str);//使用一个string对象初始化另一个string对象
 string(const char* s);//使用字符串s初始化
 string(int n, char c);//使用n个字符c初始化
 
 string基本赋值操作
 string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
 string& operator=(const string &s);//把字符串s赋给当前的字符串
 string& operator=(char c);//字符赋值给当前的字符串
 string& assign(const char *s);//把字符串s赋给当前的字符串
 string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
 string& assign(const string &s);//把字符串s赋给当前字符串
 string& assign(int n, char c);//用n个字符c赋给当前字符串
 string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
 
 */

void test01()
{
    // 默认构造
    string str;
    // 拷贝构造
    string str1 = string(str);
    // 有参构造
    string str2 = string("hello world");
    string str3 = str2;
    
    string str4 = "abcd";
    // 使用n个字符初始化字符串：第一个参数为生成的数量，第二个参数为生成的字符
    string str5 = string(10, 'a');
    
    // 基本操作
    str = "hello";
    str1 = str5;
    cout << str << " " << str1 << " " << str2 << " " << str3 << " " << str4 << " " << str5 << endl;
    
    str3.assign("abcd", 3); // 取字符串的前n个字符，赋值给调用者
    cout << str3 << endl;
    
    string str6;
    str6.assign("abcdefg", 2, 3); // 从"abcdefg"的第二h个索引开始，取3个字符，赋值给str6
    cout << str6 << endl;
}

/*
 string存取字符操作
 char& operator[](int n);//通过[]方式取字符
 char& at(int n);//通过at方法获取字符
 */

void test02()
{
    string str = "hello world";
    for (int i = 0; i < str.size(); ++i) {
        cout << str[i] << endl;  // [] 取值
        cout << str.at(i) << endl;  // at()取值
    }
    
    // []取值和at取值的区别：[]取值越界会直接crash，at取值越界会抛出out_of_range异常
    cout << str[100] << endl;
    try {
         cout << str.at(100) << endl;
    } catch (out_of_range &exception) {
        cout << exception.what() << endl;
    }
   catch (...)
    {
        cout << "越界异常" << endl;
    }
}

/*
 string拼接操作
 string& operator+=(const string& str);//重载+=操作符
 string& operator+=(const char* str);//重载+=操作符
 string& operator+=(const char c);//重载+=操作符
 string& append(const char *s);//把字符串s连接到当前字符串结尾
 string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
 string& append(const string &s);//同operator+=()
 string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
 string& append(int n, char c);//在当前字符串结尾添加n个字符c
 */
void test03()
{
    
    // 字符串拼接
    string str1 = "北京";
    string str2 = "天安门";
    string str3 = str1 + str2;
    cout << str3 << endl;
    
    str3.append("😁哈哈");
    cout << str3 << endl;
}

/*
 string查找和替换
 int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
 int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
 int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
 int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
 int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
 int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
 int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
 int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
 string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
 string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
 
 */

void test04()
{
    // 字符串查找
    string str4 = "abcdeft";
    // 正序查找子串在字符串中出现的第一个位置
    size_t pos = str4.find("def");
    cout << pos << endl;
    
    // 倒序查找子符串在字符串中出现的第一个位置
    // find和rfind查找的结果是一样的，只是内部查找方法的实现不同
    pos = str4.rfind("def");
    cout << pos << endl;
    
    // 如果查找不到返回-1或一个最大值
    pos = str4.find("aaaaa");
    cout << pos << endl;
    
    // 替换字符串
    // 从第一个索引的字符串开始替换，替换3个为“aaaaa”
    str4.replace(1, 3, "aaaaa");
    cout << str4 << endl;
}

/*
 string比较操作
 compare函数在>时返回 1，<时返回 -1，==时返回 0。
 比较区分大小写，比较时参考字典顺序，排越前面的越小。
 大写的A比小写的a小。
int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较
 */

void test05()
{
    string str1 = "abcd";
    string str2 = "abc";
    int ret = str1.compare(str2);
    if (ret == 0) {
        cout << "str1 和 str2 相同" << endl;
    }
    else if (ret == 1)
    {
        cout << "str1 大于 str2" << endl;
    }
    else
    {
        cout  << "str1 小于 str2" << endl;
    }
}

int main(int argc, const char *argv[])
{
//    test01();
//    test02();
//    test03();
    test05();
    return EXIT_SUCCESS;
}
