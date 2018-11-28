//
//  04set容器.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/28.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

/*
 set/multiset容器
 3.7.1 set/multiset容器基本概念
 3.7.1.1 set容器基本概念
 Set的特性是。所有元素都会根据元素的键值自动被排序。Set的元素不像map那样可以同时拥有实值和键值，set的元素即是键值又是实值。Set不允许两个元素有相同的键值。
 我们可以通过set的迭代器改变set元素的值吗？不行，因为set元素值就是其键值，关系到set元素的排序规则。如果任意改变set元素值，会严重破坏set组织。换句话说，set的iterator是一种const_iterator.
 set拥有和list某些相同的性质，当对容器中的元素进行插入操作或者删除操作的时候，操作之前所有的迭代器，在操作完成之后依然有效，被删除的那个元素的迭代器必然是一个例外。
 
 3.7.1.2 multiset容器基本概念
 multiset特性及用法和set完全相同，唯一的差别在于它允许键值重复。set和multiset的底层实现是红黑树，红黑树为平衡二叉树的一种。
 树的简单知识：
 二叉树就是任何节点最多只允许有两个字节点。分别是左子结点和右子节点。
 
 二叉搜索树，是指二叉树中的节点按照一定的规则进行排序，使得对二叉树中元素访问更加高效。二叉搜索树的放置规则是：任何节点的元素值一定大于其左子树中的每一个节点的元素值，并且小于其右子树的值。因此从根节点一直向左走，一直到无路可走，即得到最小值，一直向右走，直至无路可走，可得到最大值。那么在二叉搜索树中找到最大元素和最小元素是非常简单的事情。
 
 上面我们介绍了二叉搜索树，那么当一个二叉搜索树的左子树和右子树不平衡的时候，那么搜索依据上图表示，搜索9所花费的时间要比搜索17所花费的时间要多，由于我们的输入或者经过我们插入或者删除操作，二叉树失去平衡，造成搜索效率降低。
 所以我们有了一个平衡二叉树的概念，所谓的平衡不是指的完全平衡。
 
 
 RB-tree(红黑树)为二叉树的一种。
 
 */

/*
 set常用API
 3.7.2.1 set构造函数
 set<T> st;//set默认构造函数：
 mulitset<T> mst; //multiset默认构造函数:
 set(const set &st);//拷贝构造函数
 3.7.2.2 set赋值操作
 set& operator=(const set &st);//重载等号操作符
 swap(st);//交换两个集合容器
 3.7.2.3 set大小操作
 size();//返回容器中元素的数目
 empty();//判断容器是否为空
 
 3.7.2.4 set插入和删除操作
 insert(elem);//在容器中插入元素。
 clear();//清除所有元素
 erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
 erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
 erase(elem);//删除容器中值为elem的元素。
 
 */

void printSet(set<int> &mySet)
{
    for (set<int>::iterator it = mySet.begin(); it != mySet.end(); it++) {
        cout << *it << " " ;
    }
    cout << endl;
}

void tets01()
{
    set<int> mySet;
    // 关联式容器，默认是从小到大的升序排序
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(18);
    mySet.insert(16);
    printSet(mySet);
    
    // 根据迭代器删除元素 删除begin的元素
    mySet.erase(mySet.begin());
    printSet(mySet);
    
    // 根据值删除元素
    mySet.erase(18);
    printSet(mySet);
}

/*
 3.7.2.5 set查找操作
 find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
 count(key);//查找键key的元素个数
 lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
 upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
 equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
 */

void test02()
{
    // 构建set 对于set来说没有value，key就是value
    set<int> mySet;
    mySet.insert(5);
    mySet.insert(1);
    mySet.insert(3);
    mySet.insert(7);
    mySet.insert(9);
    
    // 在set中查找值2，返回值为迭代器
    // 查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    set<int>::iterator pos = mySet.find(2);
    if (pos != mySet.end()) {
        cout << "找到了:" << *pos << endl;
    }
    else
    {
        cout << "没有找到2" << endl;
    }
    
    // 查找key的元素个数，对于set来说不是0就是1
    size_t count = mySet.count(3);
    cout << "元素个数:" << count << endl;
    
    // lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    set<int>::iterator iteratorLower = mySet.lower_bound(3);
    if (iteratorLower != mySet.end()) {
        cout << "mySet.lower_bound(3) ：" << *iteratorLower << endl;
    }
    else {
        cout << "没找到" << endl;
    }
    set<int>::iterator iteratorUpper = mySet.upper_bound(3);
    if (iteratorUpper != mySet.end()) {
        cout << "mySet.upper_bound(3) ：" << *iteratorUpper << endl;
    }
    else {
        cout << "没找到" << endl;
    }
    
    // equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    pair<set<int>::iterator, set<int>::iterator> ret = mySet.equal_range(3);
    // 获取pair的第一个键
    // *(ret.first) 就是 mySet.lower_bound(3)
    if (ret.first != mySet.end()) {
        cout << "*(ret.first) : " << *(ret.first) << endl;
    }
    else {
        cout << "没找到" << endl;
    }
    // 获取pair的第二个键
    // *(ret.second) 就是 mySet.upper_bound(3)
    if (ret.second != mySet.end()) {
        cout << "*(ret.second) : " << *(ret.second) << endl;
    }
    else {
        cout << "没找到" << endl;
    }
}

void test03()
{
    // set容器不允许插入重复的键值
    set<int> mySet;
    // insert的返回值是pair<iterator,bool> 根据第二个bool类型的结果判断是否插入成功
    pair<set<int>::iterator, bool> ret = mySet.insert(10);
    if (ret.second == true) {
        cout << "插入成功，插入的值为:" << *(ret.first) << endl;
    }
    else{
        cout << "插入失败" << endl;
    }
    
    pair<set<int>::iterator , bool> ret1 = mySet.insert(10);
    if (ret1.second == true) {
        cout << "插入成功，插入的值为:" << *(ret1.first) << endl;
    }
    else{
        cout << "插入失败" << endl;
    }
    
    // multiset 允许插入重复值
    multiset<int> mul;
    // multiset的insert的返回值是一个迭代器，就是插入这个值的迭代器
    multiset<int>::iterator it = mul.insert(10);
    if (it != mul.end()) {
        cout << "插入成功，插入的值为:" << *(it) << endl;
    }
    else {
        cout << "插入失败" << endl;
    }
}

/*
 指定set的排序规则
 */
class MySetCompare {
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
void test04()
{
    // set默认的排序规则时升序，从小到大，set的结构一旦被定义就不能被修改
    // 如果要指定set的排序规则，需要在初始化时指定 一个防函数，根据这个防函数的规则进行排序
    set<int, MySetCompare> myset;
    myset.insert(10);
    myset.insert(19);
    myset.insert(18);
    myset.insert(1);
    
    for (set<int, MySetCompare>::iterator it = myset.begin(); it != myset.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

/*
 set 插入自定义数据类型，并指定排序规则
 */

class Person {
    
public:
    Person(string name, int age):m_name(name), m_age(age){}
    
    string m_name;
    int m_age;
};

class MySetComparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.m_age > p2.m_age;
    }
};

void test05()
{
    //  set 插入自定义数据类型，并指定排序规则
    // 重载MySetComparePerson的()操作符，根据年龄大小降序排序
    set<Person, MySetComparePerson> myset;
    Person p1("xiaoyuan", 19);
    Person p2("ketao", 18);
    Person p3("hehe", 2);
    myset.insert(p1);
    myset.insert(p2);
    myset.insert(p3);
    
    for (set<Person, MySetComparePerson>::iterator it = myset.begin(); it != myset.end(); ++it) {
        cout << "姓名: " << it->m_name << " 年龄:" << it->m_age << endl;
    }
}

int main(int argc, const char*argv[])
{
//    tets01();
//    test02();
//    test03();
//    test04();
    test05();
    return EXIT_SUCCESS;
}
