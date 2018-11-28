//
//  05pair对组.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/28.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 pair的应用
 
 pair是将2个数据组合成一个数据，当需要这样的需求时就可以使用pair，如stl中的map就是将key和value放在一起来保存。另一个应用是，当一个函数需要返回2个数据的时候，可以选择pair。 pair的实现是一个结构体，主要的两个成员变量是first second 因为是使用struct不是class，所以可以直接使用pair的成员变量。
 
 2 make_pair函数
 
 template pair make_pair(T1 a, T2 b) { return pair(a, b); }
 
 很明显，我们可以使用pair的构造函数也可以使用make_pair来生成我们需要的pair。 一般make_pair都使用在需要pair做参数的位置，可以直接调用make_pair生成pair对象很方便，代码也很清晰。 另一个使用的方面就是pair可以接受隐式的类型转换，这样可以获得更高的灵活度。灵活度也带来了一些问题如：
 
 std::pair<int, float>(1, 1.1);
 
 std::make_pair(1, 1.1);
 
 是不同的，第一个就是float，而第2个会自己匹配成double。
 
 类模板：template <class T1, class T2> struct pair
 
 参数：T1是第一个值的数据类型，T2是第二个值的数据类型。
 
 功能：pair将一对值组合成一个值，这一对值可以具有不同的数据类型（T1和T2），两个值可以分别用pair的两个公有函数first和second访问。
 
 具体用法：
 
 1.定义（构造）：
 
 1     pair<int, double> p1;  //使用默认构造函数
 2     pair<int, double> p2(1, 2.4);  //用给定值初始化
 3     pair<int, double> p3(p2);  //拷贝构造函数
 2.访问两个元素（通过first和second）：
 
 1     pair<int, double> p1;  //使用默认构造函数
 2     p1.first = 1;
 3     p1.second = 2.5;
 4     cout << p1.first << ' ' << p1.second << endl;
 输出结果：1 2.5
 
 3.赋值operator = ：
 
 
 
 （1）利用make_pair：
 
 
 
 1     pair<int, double> p1;
 2     p1 = make_pair(1, 1.2);
 （2）变量间赋值：
 
 
 
 pair<int, double> p1(1, 1.2);
 pair<int, double> p2 = p1;
 Pair类型概述
 pair是一种模板类型，其中包含两个数据值，两个数据的类型可以不同，基本的定义如下：
 
 pair<int, string> a;
 表示a中有两个类型，第一个元素是int型的，第二个元素是string类型的，如果创建pair的时候没有对其进行初始化，则调用默认构造函数对其初始化。
 
 pair<string, string> a("James", "Joy");
 也可以像上面一样在定义的时候直接对其初始化。
 
 由于pair类型的使用比较繁琐，因为如果要定义多个形同的pair类型的时候，可以时候typedef简化声明：
 typedef pair<string, string> author;
 author pro("May", "Lily");
 author joye("James", "Joyce");
 
 
 Pair对象的操作
 
 对于pair类，由于它只有两个元素，分别名为first和second，因此直接使用普通的点操作符即可访问其成员
 pair<string, string> a("Lily", "Poly");
 string name;
 name = pair.second;
 生成新的pair对象
 可以使用make_pair对已存在的两个数据构造一个新的pair类型：
 int a = 8;
 string m = "James";
 pair<int, string> newone;
 newone = make_pair(a, m);
 */

void test01()
{
    // 使用构造函数 构建pair对组
    pair<string, int> p1(string("xiaoyuan"), 20);
    cout << p1.first << endl;
    cout << p1.second << endl;
    
    // 使用make_pair()函数构建对组
    pair<string, string> p2 = make_pair("ketao", "hello world");
    cout << p2.first << endl;
    cout << p2.second << endl;
}

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
