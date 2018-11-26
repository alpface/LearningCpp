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

/*
 string子串
 string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
 */

void test06()
{
    // 获取某个范围的子串
    string str = "abcdefg";
    string subStr = str.substr(1, 3);
    cout << subStr << endl;
    
    // 截取邮箱中的用户名
    string mailStr = "sey@live.cn";
    size_t pos = mailStr.find("@");
    string mailSubStr = mailStr.substr(0, pos);
    cout << mailSubStr << endl;
}

/*
 string插入和删除操作
 string& insert(int pos, const char* s); //插入字符串
 string& insert(int pos, const string& str); //插入字符串
 string& insert(int pos, int n, char c);//在指定位置插入n个字符c
 string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
 */
void test07()
{
    // 插入字符
    string str1 = "hello world";
    str1.insert(3, " 11 ");
    cout << str1 << endl;
    
    // 删除字符串
    str1.erase(3, 4);
    cout << str1 << endl;
}

/*
 string和c-style字符串转换
 //string 转 char*
 string str = "itcast";
 const char* cstr = str.c_str();
 //char* 转 string
 char* s = "itcast";
 string str(s);

 */
void func(string s)
{
    cout << s << endl;
}
void func1(char *p)
{
    cout << p << endl;
}
void test08()
{
    string s = "abc";
    const char * p = s.c_str();
    
    func(p); // 隐士类型转换const char * 隐士转换为string
    
    string s1 = string(p);
//    func1(s1); // string不能 隐士转换为const char *
    /*
     在c++中存在一个从const char*到string的隐式类型转换，却不存在从一个string对象到C_string的自动类型转换。对于string类型的字符串，可以通过c_str()函数返回string对象对应的C_string.
     通常，程序员在整个程序中应坚持使用string类对象，直到必须将内容转化为char*时才将其转换为C_string.
     
     */
}

void test09()
{
    /*
    为了修改string字符串的内容，下标操作符[]和at都会返回字符的引用。但当字符串的内存被重新分配之后，可能发生错误.
    */
    string s = "abcdefg";
    char& a = s[2];
    char& b = s[3];
    
    a = '1';
    b = '2';
    
    cout << s << endl;
    cout << (int*)s.c_str() << endl;
    
    s = "pppppppppppppppppppppppp";
    
//    a = '1';
//    b = '2';
    
    cout << s << endl;
    cout << (int*)s.c_str() << endl;
    
    // 两次打印(int*)s.c_str() 地址不同
}

// 写一个函数，将sring的所有小写字母都转换为大写
void test10()
{
    string str = "AbcedF";
    for (int i = 0; i < str.size(); ++i) {
        // 转大写
        str[i] = toupper(str[i]);
        // 转小写
//        str[i] = tolower(str[i]);
    }
    cout << str << endl;
}
int main(int argc, const char *argv[])
{
//    test01();
//    test02();
//    test03();
//    test05();
//    test06();
//    test07();
//    test08();
//    test09();
    test10();
    return EXIT_SUCCESS;
}
