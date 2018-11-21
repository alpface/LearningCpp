//
//  07全局函数做友元函数.cpp
//  04
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Building {
    // 声明全局函数goodGay()为Build的友元函数，那么就可以在goodGay()内访问Building的私有属性了
    friend void goodGay(Building &b);
public:
    Building()
    {
        this->m_roomName = "room";
        this->m_bedName = "bed";
        cout << "默认构造函数被调用" << endl;
    }
    
    ~Building()
    {
        cout << "析构函数被调用" << endl;
    }
    
    string m_roomName;
private:
    string m_bedName;
};

// 声明一个全局函数，并且在这个全局函数内可以访问Building这个类的私有属性
void goodGay(Building &b)
{
    // 正常情况下是在此函数内访问Building的私有属性的，但是如果将goodGay()函数设置为Building的友元函数则可以访问私有属性哦
    cout << "goodGay访问了:" << b.m_roomName << "和" << b.m_bedName << endl;
}

void test()
{
    Building *b = new Building;
    goodGay(*b);
    delete b;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
