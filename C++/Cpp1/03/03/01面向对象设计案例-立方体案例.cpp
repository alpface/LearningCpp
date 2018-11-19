//
//  01面向对象设计案例-立方体案例.cpp
//  03
//
//  Created by swae on 2018/11/19.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 需求：设计立方体(Cube)类
 求出立方体的面积(2*a*b+2*a*c+2*b*c)和体积(a*b*c)
 分别用全局函数和成员函数判断两个立方体是否相等
 */

class Cube {
  
public:
    // 设置长
    void setL(int l)
    {
        m_l = l;
    }
    
    /*
     函数后面加const 修饰函数内部的类成员属性不可以修改:
     在类成员函数的声明和定义中，
     const的函数不能对其数据成员进行修改操作。
     const的对象，不能引用非const的成员函数
     */
    // 获取长
    int getL() const
    {
        return m_l;
    }
    
    // 设置宽
    void setW(int w)
    {
        m_w = w;
    }
    
    // 获取宽
    int getW() const
    {
        return m_w;
    }
    
    // 设置高
    void setH(int h)
    {
        m_h = h;
    }
    // 获取高
    int getH() const
    {
        return m_h;
    }
    
    // 求立方体的面积
    void getCubeS()
    {
        int cubeS = 2 * getH() * getL()+ 2 * getH() * getL() + 2 * getW()*getL();
        cout << "立方体的面积 = " << cubeS << endl;
    }
    
    // 求立方体的体积
    void getCubeV()
    {
        int cubeV = getW() * getL() * getH();
        cout << "立方体的体积 = " << cubeV << endl;
    }
    
    // 通过成员函数判断两个cube是否相等
    bool compareByCube(Cube &cube)
    {
        bool ret = cube.getW() == getW() && cube.getL() == getL() && cube.getH() == getH();
        return ret;
    }
    
private:
    int m_l; // 长
    int m_w; // 宽
    int m_h; // 高
};

// 通过全局函数判断两个cube是否相等
bool compareCube(Cube &c1, Cube &c2)
{
    return c1.getW() == c2.getW() && c2.getL() == c1.getL() && c1.getH() == c2.getH();
}

void test()
{
    Cube c1;
    c1.setH(10);
    c1.setL(20);
    c1.setW(30);
    
    c1.getCubeS();
    c1.getCubeV();
    
    Cube c2;
    c2.setH(10);
    c2.setL(20);
    c2.setW(30);
    
    // 通过成员函数判断c1和c2是否相等
    bool isEqual = c1.compareByCube(c2);
    if (isEqual) {
        cout << "c1 和 c2 相等" << endl;
    }
    else {
        cout << "c1 和 c2 不相等" << endl;
    }
    
    // 通过全局函数判断两个是否相等
    isEqual = compareCube(c1, c2);
    if (isEqual) {
        cout << "c1 和 c2 相等" << endl;
    }
    else {
        cout << "c1 和 c2 不相等" << endl;
    }
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
