//
//  02 面向对象设计案例-点和圆的关系.cpp
//  03
//
//  Created by swae on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

/*
 设计Circle圆类和Point点类，并计算点和圆的关系
 例如圆心坐标为x0,y0,半径为r，点的坐标为x1,y1
 */

#include <iostream>
#include "Circle.hpp"

using namespace std;

void isInCircleByPoint(Circle &c, Point &p)
{
    // 获取园心和点的距离
    int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY());
    int rDistance = c.getR() *c.getR();
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

void test01()
{
    Point p1;
    p1.setX(10);
    p1.setY(11);
    
    Circle c1;
    Point center;
    center.setY(0);
    center.setX(10);
    c1.setR(10);
    c1.setCenter(center);
    
    // 根据成员函数判断p1这个点和c1这个圆的关系
    c1.isInCircleByPoint(p1);
    
    // 根据全局函数 判断圆和点的关系
    isInCircleByPoint(c1, p1);
}

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
