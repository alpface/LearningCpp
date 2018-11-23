//
//  01静态联编和动态联编.cpp
//  07
//
//  Created by xiaoyuan on 2018/11/23.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class Animal {
public:
    void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat: public Animal {
    
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }
};

// 1.静态联编
// speak()不是虚函数
// 当调用doSpeak()时，不管传入的实例是Animal的还是Cat的，执行的都是Animal的speak()，这是因为speak()函数在编译阶段就与类进行绑定，这就叫早绑定，静态联编，在编译阶段就确定好了地址
// 如果想要调用Cat的speak()，则不能在编译阶段确定函数的地址，需要在运行时在确定函数的地址
// 2.动态联编
// 在Animal的speak()函数前面写virtual，将其声明为虚函数，就会将speak()的函数地址在运行时确定，如果传入的是Animal实例就会调用Animal的speak()，如果传入的是Cat就会调用Cat的speak();
void doSpeak(Animal &animal)
{
    animal.speak();
}

void test()
{
    // 父类的指针指向子类对象 多台
    Animal cat = Cat();
    doSpeak(cat);
}

int main(int argc, const char*argv[])
{
    test();
    return EXIT_SUCCESS;
}
