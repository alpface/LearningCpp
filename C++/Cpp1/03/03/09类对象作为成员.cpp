//
//  09类对象作为成员.cpp
//  03
//
//  Created by xiaoyuan on 2018/11/20.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>


using namespace std;

class Phone {
    
public:
    Phone()
    {
        cout << "Phone的无参构造函数被调用" << endl;
    }
    Phone(string name)
    {
        m_name = name;
        cout << "Phone的带参数构造函数被调用" << endl;
    }
    string getName() const
    {
        return m_name;
    }
    ~Phone()
    {
        cout << "Phone被释放了" << endl;
    }
private:
    string m_name;
};

class Game {
    
public:
    Game()
    {
        cout << "Game的无参构造函数被调用" << endl;
    }
    Game(string name)
    {
        m_name = name;
        cout << "Game的带参数构造函数被调用" << endl;
    }
    string getName() const
    {
        return m_name;
    }
    ~Game()
    {
        cout << "Game被释放了" << endl;
    }
private:
    string m_name;
};

class Person {
    
public:
    Person()
    {
        cout << "Person的无参构造函数被调用" << endl;
    }
    Person(string name, string phone, string game): m_name(name), m_phone(phone), m_game(game)
    {
        cout << "Person的初始化方法列表被调用" << endl;
    }
    
    void playGame()
    {
        cout << m_name << "拿着" << m_phone.getName() << "手机" << "玩着" << m_game.getName() << "游戏" << endl;
    }
    string getName() const
    {
        return m_name;
    }
    ~Person()
    {
        cout << "Person被释放了" << endl;
    }
private:
    string m_name; // 姓名
    Phone m_phone; // 电话
    Game m_game;   // 游戏
};

/**
 类对象作为类成员的时候，构造对象先将类对象属性构造，再构造自己，析构时正好相反
 */

void test()
{
    Person p1("xiaoyuan", "iPhone", "绝地求生");
    p1.playGame();
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
