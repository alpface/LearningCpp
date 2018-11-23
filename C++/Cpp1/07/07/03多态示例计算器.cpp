//
//  03多态示例计算器.cpp
//  07
//
//  Created by xiaoyuan on 2018/11/23.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 利用多态实现计算器的示例

// 纯虚函数就是没有函数体，同时在定义的时候，其函数名后面要加上“= 0”。

class AbstractCalculator {
    
public:

    // 虚函数
//    virtual int getResult()
//    {
//        return 0;
//    }
    
    // 纯虚函数
    // 如果类中有了纯虚函数，那么子类继承这个类后，必须实现纯虚函数
    // 如果类中有纯虚函数，那么这个类就无法实例化了
    // 如果类中有纯虚函数，那么这个类就是抽象类
    virtual int getResult() = 0;
    
    void setValue1(int v)
    {
        this->m_value1 = v;
    }
    void setValue2(int v)
    {
        this->m_value2 = v;
    }
    
    virtual int getValue1()
    {
        return this->m_value1;
    }
    virtual int getValue2()
    {
        return this->m_value2;
    }
private:
    int m_value1;
    int m_value2;
};

// AbstractCalculator中有纯虚函数，那么AbstractCalculator就是一个抽象类，而A类继承自AbstractCalculator，他就必须实现这些纯虚函数
class A: public AbstractCalculator {
    
public:
    // A类必须要实现父类的纯虚函数，不然A类也是抽象类，无法实例化
    int getResult()
    {
        return 0;
    }
};

// 加法运算类
class PlusCalculator: public AbstractCalculator {
    
public:
    virtual int getResult()
    {
        return this->getValue1() + this->getValue2();
    }
    ~PlusCalculator()
    {
        cout << "PlusCalculator 析构函数被调用" << endl;
    }
};

// 减法运算类
class SubCalculator:public AbstractCalculator {
    
public:
    virtual int getResult()
    {
        return this->getValue1() - this->getValue2();
    }
    ~SubCalculator()
    {
        cout << "SubCalculator 析构函数被调用" << endl;
    }
};

// 乘法运算类
class ChengCalculator:public AbstractCalculator {
    
public:
    virtual int getResult()
    {
        return this->getValue1() * this->getValue2();
    }
    ~ChengCalculator()
    {
        cout << "ChengCalculator 析构函数被调用" << endl;
    }
};


void test01()
{
    A a; // 当A类中没有实现父类的纯虚函数时，构造报错: Variable type 'A' is an abstract class
    
}

void test02()
{
    AbstractCalculator * abc ;
    // 加法
    abc =  new PlusCalculator;
    
    abc->setValue1(10);
    abc->setValue2(20);
    
    cout << abc->getResult() << endl;
    
//    delete abc; // Delete called on 'AbstractCalculator' that is abstract but has non-virtual destructor
    delete (PlusCalculator *)abc;
    
    abc = new SubCalculator;
    abc->setValue1(10);
    abc->setValue2(20);
    cout << abc->getResult() << endl;
    delete (SubCalculator *)abc;

    abc = new ChengCalculator;
    abc->setValue1(10);
    abc->setValue2(20);
    cout << abc->getResult() << endl;
    delete (ChengCalculator *)abc;
}

int main(int argc, const char*argv[])
{
//    test01();
    test02();
    return EXIT_SUCCESS;
}
