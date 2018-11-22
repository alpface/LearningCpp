//
//  04继承的引出.cpp
//  06
//
//  Created by swae on 2018/11/22.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

class BasePage {
    
public:
    void header()
    {
        cout << "公共头部" << endl;
    }
    void footer()
    {
        cout << "公共尾部" << endl;
    }
    void left()
    {
        cout << "左侧列表" << endl;
    }
};

// public 公有继承
class Game: public BasePage {
    
public:
    void content()
    {
        cout << "游戏内容模块" << endl;
    }
};

class News: public BasePage {
    
public:
    void content()
    {
        cout << "新闻内容模块" << endl;
    }
};

void test()
{
    Game g;
    g.content();
    g.header();
    g.left();
    g.footer();
    
    News n;
    n.content();
    n.header();
    n.left();
    n.footer();
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
