//
//  10C++中explicit的用法.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/20.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

/*
 C++提供了关键字explicit，可以阻止不应该允许的经过转换构造函数进行的隐式转换的发生,声明为explicit的构造函数不能在隐式转换中使用。
 C++中， 一个参数的构造函数(或者除了第一个参数外其余参数都有默认值的多参构造函数)， 承担了两个角色。
 1.构造函数；2.默认且隐含的类型转换操作符。
 所以， 有时候在我们写下如 AAA = XXX， 这样的代码， 且恰好XXX的类型正好是AAA单参数构造器的参数类型， 这时候编译器就自动调用这个构造器， 创建一个AAA的对象。
 
 这样看起来好象很酷， 很方便。
 但在某些情况下， 却违背了程序员的本意。 这时候就要在这个构造器前面加上explicit修饰， 指定这个构造器只能被明确的调用/使用， 不能作为类型转换操作符被隐含的使用。

 */

//  解析：explicit构造函数是用来防止隐式转换的。请看下面的代码：

using namespace std;

class MyString {
    
public:
    // explicit 防止该构造函数被隐式调用
    explicit MyString(const char *str)
    {
        m_size = (int)strlen(str);
        m_str = (char *)malloc(m_size + 1);
    }
    MyString(int size)
    {
        m_size = size;
    }
private:
    char *m_str;
    int m_size;
};

void test()
{
//    MyString s = "abc"; // 隐式调用了MyString(const char *str)的构造函数 如果改构造函数使用explicit声明则不会调用此构造函数
    MyString s1 = 10;  // 隐式调用了MyString(int size)的构造函数 如果使用explicit则不会调用此构造函数
}

int main(int argc, const char *argv[])
{
    return EXIT_SUCCESS;
}
