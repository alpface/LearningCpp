//
//  02设计学生类.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// 设计一个学生类：属性有姓名和学号，可以给姓名和学号赋值，也可以显示姓名和学号

class Student {
    
public:
    string m_name; // 姓名
    int m_id;        // 学号
    
    void setName(string name)
    {
        m_name = name;
    }
    
    void setId(int id)
    {
        m_id = id;
    }
    
    void showInfo()
    {
        cout << "name = " << m_name << " id = " << m_id << endl;
    }
};

void test()
{
    // 实例化学生类
    Student s;
    s.setId(100);
    s.setName("xiaoyuan");
    s.showInfo();
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
