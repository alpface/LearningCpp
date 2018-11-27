//
//  05评委打分.cpp
//  01
//
//  Created by xiaoyuan on 2018/11/27.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

/*
 有5名选手：A、B、C、D、E，10名评委分别对每一个选手进行打分，去除评委中的最高分和最低分，取平均分
 1.创建5个选手，放到vector中
 2.遍历vector容器，取出每一个选手，执行for循环，将10个评委的评分放到deque容器中
 3.sort算法对deque容器中的分数进行排序，pop_back()和pop_front()去除最高和最低的分数
 4.计算总分数：deque容器遍历，累加分数，计算平均分：总分数/deque的元素个数size()
 5.person.score = 平均分
 */

using namespace std;

class Person {
public:
    Person(int score, string name)
    {
        this->m_score = score;
        this->m_name = name;
    }
public:
    int m_score;
    string m_name;
};

// 创建5名选手
void createPersons(vector<Person> &v)
{
    string names = "ABCDE";
    for (int i = 0; i < names.size(); ++i) {
        string name = "选手";
        name+=names[i];
        Person p(0, name);
        v.push_back(p) ;
    }
}

// 打分
void setScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it) {
        
        // for循环模拟 对5个人进行打分
        deque<int> d;
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 + 60; // 60 ~ 100 分
            d.push_back(score);
        }
        
        // 对分数进行排序 升序
        sort(d.begin(), d.end());
        
        // 去除最高和最低分
        d.pop_back();
        d.pop_front();
        
        // 计算总分数
        int sum = 0;
        for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
            sum += *it;
        }
        
        // 计算平均分
        int avg = sum / d.size();
        it->m_score = avg;
    }
}

// 打印选手
void printPersons(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << "姓名:" << it->m_name << " 平均分:" << it->m_score << endl;
    }
}
//void test_rand(void)
//{
//    /*
//     随机数种子用法:它初始化随机种子，会提供一个种子，这个种子会对应一个随机数，如果使用相同的种子后面的rand()函数会出现一样的随机数，如: srand(1); 直接使用1来初始化种子。不过为了防止随机数每次重复，常常使用系统时间来初始化，即使用 time函数来获得系统时间，它的返回值为从 00:00:00 GMT, January 1, 1970 到现在所持续的秒数，然后将time_t型数据转化为(unsigned)型再传给srand函数，即: srand((unsigned) time(&t)); 还有一个经常用法，不需要定义time_t型t变量,即: srand((unsigned) time(NULL)); 直接传入一个空指针，因为你的程序中往往并不需要经过参数获得的数据。
//     */
//    unsigned long n;
//    srand((unsigned)time(NULL));
//    for(int i = 0; i < 100; i++)
//    {
//        n = rand();
//        printf("d\n", n);
//    }
//}

void test01()
{
//    test_rand();
    // 设置随机数种子
    srand((unsigned int)time(NULL));
    
    // 创建5名选手
    vector<Person> v;
    createPersons(v);
    
    setScore(v);
    
    printPersons(v);
}

int main(int argc, const char*argv[])
{
    test01();
    return EXIT_SUCCESS;
}
