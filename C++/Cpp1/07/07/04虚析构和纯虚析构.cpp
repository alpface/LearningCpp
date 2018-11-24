//
//  04虚析构和纯虚析构.cpp
//  07
//
//  Created by swae on 2018/11/24.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
    
    // 普通析构函数
    // 问题: 当初始化Animal的子类时，使用Animal*指针指向创建的子类，这时候发生了多态，此时释放时是不会调用子类的析构函数，所以可能会导致释放不干净
//    ~Animal()
//    {
//        cout << "Animal析构函数调用" << endl;
//    }
    
    // 使用纯虚析构函数解决这个多态释放时，不调用子类析构函数的问题
    virtual ~Animal() = 0;
};

Animal::~Animal()
{
    // 纯虚析构函数的实现
    cout << "Animal的纯虚析构函数调用" << endl;
}

class Cat:public Animal {
    
public:
    Cat(const char *name)
    {
        this->m_name = new char[strlen(name) + 1];
        strcpy(this->m_name, name);
    }
    
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
    
    ~Cat()
    {
        cout << "Cat的析构函数调用" << endl;
        // 释放m_name
        if (m_name != NULL ) {
            delete [] m_name;
            this->m_name = NULL;
        }
    }
    char *m_name;
};

void test01()
{
//    Cat cat("小猫");
    Animal *cat = new Cat("小猫");
    cat->speak();
    delete cat;
    
}

int main(int argc, const char *argv[])
{
    test01();
    return EXIT_SUCCESS;
}
