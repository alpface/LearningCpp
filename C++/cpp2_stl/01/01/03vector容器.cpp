//
//  03vector容器.cpp
//  01
//
//  Created by xiaoyuan on 2018/11/27.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
 vector容器基本概念
 vector的数据安排以及操作方式，与array非常相似，两者的唯一差别在于空间的运用的灵活性。Array是静态空间，一旦配置了就不能改变，要换大一点或者小一点的空间，可以，一切琐碎得由自己来，首先配置一块新的空间，然后将旧空间的数据搬往新空间，再释放原来的空间。Vector是动态空间，随着元素的加入，它的内部机制会自动扩充空间以容纳新元素。因此vector的运用对于内存的合理利用与运用的灵活性有很大的帮助，我们再也不必害怕空间不足而一开始就要求一个大块头的array了。
 Vector的实现技术，关键在于其对大小的控制以及重新配置时的数据移动效率，一旦vector旧空间满了，如果客户每新增一个元素，vector内部只是扩充一个元素的空间，实为不智，因为所谓的扩充空间(不论多大)，一如刚所说，是”配置新空间-数据移动-释放旧空间”的大工程,时间成本很高，应该加入某种未雨绸缪的考虑，稍后我们便可以看到vector的空间配置策略。
 
 */

/*
 vector迭代器
 Vector维护一个线性空间，所以不论元素的型别如何，普通指针都可以作为vector的迭代器，因为vector迭代器所需要的操作行为，如operaroe*, operator->, operator++, operator--, operator+, operator-, operator+=, operator-=, 普通指针天生具备。Vector支持随机存取，而普通指针正有着这样的能力。所以vector提供的是随机访问迭代器
 */
/*
 vector的数据结构
 Vector所采用的数据结构非常简单，线性连续空间，它以两个迭代器_Myfirst和_Mylast分别指向配置得来的连续空间中目前已被使用的范围，并以迭代器_Myend指向整块连续内存空间的尾端。
 为了降低空间配置时的速度成本，vector实际配置的大小可能比客户端需求大一些，以备将来可能的扩充，这边是容量的概念。换句话说，一个vector的容量永远大于或等于其大小，一旦容量等于大小，便是满载，下次再有新增元素，整个vector容器就得另觅居所。
 
 注意：
 所谓动态增加大小，并不是在原空间之后续接新空间(因为无法保证原空间之后尚有可配置的空间)，而是一块更大的内存空间，然后将原数据拷贝新空间，并释放原空间。因此，对vector的任何操作，一旦引起空间的重新配置，指向原vector的所有迭代器就都失效了。这是程序员容易犯的一个错误，务必小心。
 
 */

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

/*
 vector api
 vector构造函数
 vector<T> v; //采用模板实现类实现，默认构造函数
 vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
 vector(n, elem);//构造函数将n个elem拷贝给本身。
 vector(const vector &vec);//拷贝构造函数。
 
 //例子 使用第二个构造函数 我们可以...
 int arr[] = {2,3,4,1,9};
 vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
 
 */

void test01()
{
    // 通过Array构造vector
    int arr[] = {2, 1, 10, 20};
    // 参数为数组的首地址和数组的最后一个元素地址，此构造会将首地址和最后一个地址z之间的元素拷贝给vector本身
    vector<int> v1(arr, arr+sizeof(arr)/sizeof(int));
    
    // 通过vector构造vector
    // 将v[begin(), end())区间中的元素拷贝给本身。
    vector<int> v2(v1.begin(), v1.end());
    printVector(v1);
    printVector(v2);
    
    // 创建10个100的vector
    vector<int> v3(10, 100);
    printVector(v3);
    
    // 拷贝构造函数
    vector<int> v4 = vector<int>(v3);
    printVector(v4);
}

/*
 vector常用赋值操作
 assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
 assign(n, elem);//将n个elem拷贝赋值给本身。
 vector& operator=(const vector  &vec);//重载等号操作符
 swap(vec);// 将vec与本身的元素互换。
  */

void test02()
{
    // 赋值操作
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(28);
    vector<int> v2;
    v2.assign(v1.begin(), v1.end());
    printVector(v2);
    v2.push_back(88);
    v2.push_back(89);
    cout << "原始的v2：";
    printVector(v2);
    // 交换数组元素
    v2.swap(v1);
    cout << "交换后的v2：";
    printVector(v2);
}

 /*
  vector大小操作
 size();//返回容器中元素的个数
 empty();//判断容器是否为空
 resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
 resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
 capacity();//容器的容量
 reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
  
  */

void test03()
{
    // 构造vector
    int arr[] = {1, 3, 2, 10, 28, 39, 30};
    vector<int> v1(arr, arr+sizeof(arr)/sizeof(int));
    cout << "数组元素个数:" << v1.size() << endl;
    if (v1.empty()) {
        cout << "数组为空" << endl;
    }
    else {
        cout << "数组不为空" << endl;
    }
    printVector(v1);
    // 重新指定数组容器的长度为3，重新指定的容量比原数组小，后面多出的就被移除了
    v1.resize(3);
    printVector(v1);
    // 重新指定容器的长度为100，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
    v1.resize(100, 88);
    printVector(v1);
    cout << "数组的容量:" << v1.capacity() << endl;
}

// 巧用swap收缩空间
void test04()
{
    vector<int> v;
    for (int i = 0; i < 10000; ++i) {
        v.push_back(i);
    }
    cout << "capacity:" << v.capacity() << endl;
    cout << "size:" << v.size() << endl;
    
    v.resize(3);
    cout << "capacity:" << v.capacity() << endl;
    cout << "size:" << v.size() << endl;
    
    // 使用匿名对象swap自己后，数组的容量被收缩
    vector<int>(v).swap(v);
    cout << "capacity:" << v.capacity() << endl;
    cout << "size:" << v.size() << endl;
}

// reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
void test05()
{
    vector<int> v;
    
    // 当我们知道数组的大小时，使用reserve预留足够大的空间时，会减少vector的多次开辟空间
    /*
     比如本例子：
     我们要添加100000个元素到vector中，这是我们事先知道的，
     如果我们未使用reserve预留这些个空间，vector的容量会在每次使用满的时候，重新开辟更大的空间
     如果我们使用reserve预留这些个空间，则vector会一次性开辟这么大的空间，减少开辟空间的次数
     */
    v.reserve(100000); // 预留出100000个空间
    
    int *p = NULL; // 记录vector容器元素的首地址
    int num = 0; // 记录这个vector开辟了多少次内存空间
    
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i);
        if (p != &v[0]) { // 当vctor元素首地址发生改变时，重新记录元素首地址，次数说明vector的内存空间更换更大的了
            p = &v[0];
            num++;
            cout << "capacity:" << v.capacity() << endl;
        }
    }
    cout << "开辟内存的次数:" << num << endl;
}
  
  /*
 vector数据存取操作
 at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
 operator[];//返回索引idx所指的数据，越界时，运行直接报错
 front();//返回容器中第一个数据元素
 back();//返回容器中最后一个数据元素
 
 3.2.4.5 vector插入和删除操作
 insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
 push_back(ele); //尾部插入元素ele
 pop_back();//删除最后一个元素
 erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
 erase(const_iterator pos);//删除迭代器指向的元素
 clear();//删除容器中所有元素
 
 */

void test06()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(199);
    cout << "v的front:" << v.front() << endl;
    cout << "v的back:" << v.back() << endl;
    
    // 在vector的开始位置插入88
    v.insert(v.begin(), 88);
    printVector(v);
    // 在vector的第二个位置插入188
    v.insert(v.begin()+2, 188);
    printVector(v);
    // 在vector的结尾插入20个100
    v.insert(v.end(), 20, 100);
    printVector(v);
    
    // 尾部删除
    v.pop_back();
    printVector(v);
    
    // 删除第一个元素
    v.erase(v.begin());
    printVector(v);
    
    // 删除起始和结束这个范围内的所有元素，就是清空全部
    v.erase(v.begin(), v.end());
    printVector(v);
    
    // 清空全部
    v.clear();
    printVector(v);
}

// 逆序迭代器reverse_iterator
void test07()
{
    // 创建vector
    vector<int> v;
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
    
    // 逆序迭代
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // 随机访问迭代器
    vector<int>::iterator itBegin = v.begin();
    itBegin+=3;
    cout << *itBegin << endl;
    // 如果itBegin+=3不报错，那么他是随机访问迭代器
    
    // list就不是随机访问迭代器
    list<int> l;
    for (int i = 0; i < 100; ++i) {
        l.push_back(i);
    }
    list<int>::iterator lItBegin = l.begin();
//    lItBegin += 5;  // No viable overloaded '+='
    cout << *lItBegin << endl;
}

int main(int argc, const char**argv)
{
//    test01();
//    test02();
//    test03();
//    test04();
//    test05();
//    test06();
    test07();
    return EXIT_SUCCESS;
}
