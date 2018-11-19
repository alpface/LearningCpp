//
//  01设计圆类求周长.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

const double pi = 3.1415926;

// 设计一个类 - 求圆

class Circle
{
public:
    double calculateZC()
    {
        return 2 * pi *m_r;
    }
    
    // 设置半径的成员方法
    void setR(int r)
    {
        m_r = r;
    }
    
    // 半径 成员属性
    int m_r;
};

void test()
{
    Circle c;
    c.setR(10);
    double zc = c.calculateZC();
    cout << "周长 = " << zc << endl;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
