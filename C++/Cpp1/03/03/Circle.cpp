//
//  Circle.cpp
//  03
//
//  Created by swae on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "Circle.hpp"
#include <iostream>

using namespace std;

// 设置半径
void Circle::setR(int r)
{
    m_r = r;
}
// 获取半径
int Circle::getR()
{
    return m_r;
}
// 设置圆心
void Circle:: setCenter(Point center)
{
    m_center = center;
}
// 获取圆心
Point Circle:: getCenter()
{
    return m_center;
}

// 定义成员函数，判断点是否在园的范围内
void Circle:: isInCircleByPoint(Point &p)
{
    // 获取园心和点的距离
    int distance = (m_center.getX() - p.getX()) * (m_center.getX() - p.getX()) + (m_center.getY() - p.getY());
    int rDistance = m_r *m_r;
    if (distance == rDistance) {
        cout << "点再圆上" << endl;
    }
    else if (rDistance > distance) {
        cout << "点在圆内" << endl;
    }
    else {
        cout << "点在圆外" << endl;
    }
    
}
