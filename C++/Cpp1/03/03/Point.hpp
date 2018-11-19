//
//  Point.hpp
//  03
//
//  Created by swae on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>

class Point {
    
public:
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    
private:
    int m_x;
    int m_y;
};

#endif /* Point_hpp */
