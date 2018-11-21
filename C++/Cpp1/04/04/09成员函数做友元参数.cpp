//
//  09成员函数做友元参数.cpp
//  04
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// 只让Vist 可以访问 Building的成员，而Building不可以访问Vist的成员

class Building;
class GoodGay {
    
public:
    GoodGay();
    ~GoodGay();
    void vist();
    void vist1();
private:
    Building *building;
};

class Building {
    // 让GoodGay这个类的成员函数vist()作为Building的友元函数
    friend void GoodGay::vist();
public:
    Building();
    ~Building();
    string m_roomName;
private:
    string m_bedName;
};

GoodGay::GoodGay()
{
    building = new Building();
    cout << "GoodGay构造函数被调用" << endl;
}
GoodGay::~GoodGay()
{
    cout << "GoodGay的析构函数被调用" << endl;
    // GoodGay释放时，释放building属性
    if (NULL != this->building) {
        delete this->building;
    }
}
void GoodGay::vist()
{
    cout << "正在访问 " << this->building->m_roomName << endl;
    cout << "正在访问 " << this->building->m_bedName << endl;
}

void GoodGay::vist1()
{
    cout << "正在访问 " << this->building->m_roomName << endl;
//    cout << "正在访问 " << this->building->m_bedName; //vist1 不是Building的友元函数，所以无法在内部访问Building的私有属性
}

Building::Building()
{
    this->m_roomName = "房间";
    this->m_bedName = "双人床";
    cout << "Building构造函数被调用" << endl;
}

Building::~Building()
{
    cout << "Building的析构函数被调用" << endl;
}

void test()
{
    GoodGay *g = new GoodGay();
    g->vist();
    g->vist1();
    delete g;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
