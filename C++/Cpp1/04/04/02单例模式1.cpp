//
//  02单例模式1.cpp
//  04
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

// 创建主席类
// 需求 只存在一个实例 单例模式
class ChairMan {
    
private:
    // 构造函数私有化，防止被直接初始化
    ChairMan()
    {
        cout << "默认构造函数被调用" << endl;
        m_name = "习大大";
    }
    // 拷贝构造函数私有化 防止被拷贝
    ChairMan(const ChairMan &main)
    {
        cout << "拷贝构造函数被调用" << endl;
    }
public:
    // 提供获取实例的方法
    static ChairMan *getInstance()
    {
        return singleInstan;
    }
    string getName() const
    {
        return m_name;
    }
private:
    static ChairMan *singleInstan;
    string m_name;
};

ChairMan * ChairMan::singleInstan = new ChairMan;

void test()
{
    ChairMan *main1 = ChairMan::getInstance();
    ChairMan *main2 = ChairMan::getInstance();
    cout << "main1.name = " << main1->getName() << endl;
    cout << "main2.name = " << main2->getName() << endl;
    cout << "main1 = " << &main1 << endl;
    cout << "main2 = " << &main2 << endl;
    //    ChairMan *main3 = new ChairMan; // Error: Calling a private constructor of class 'ChairMan'
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
