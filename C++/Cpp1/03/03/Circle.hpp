//
//  Circle.hpp
//  03
//
//  Created by swae on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "Point.hpp"

class Circle {
    
public:
    
    // 设置半径
    void setR(int r);
    // 获取半径
    int getR();
    // 设置圆心
    void setCenter(Point center);
    // 获取圆心
    Point getCenter();
    
    // 定义成员函数，判断点是否在园的范围内
    void isInCircleByPoint(Point &p);
    
private:
    int m_r; // 半径
    Point m_center; // 圆心
};

#endif /* Circle_hpp */
