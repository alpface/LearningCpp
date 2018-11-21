//
//  02单例模式2.cpp
//  04
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

// 打印机类，程序运行中只能存在一个实例

class Printer {
    
private:
    Printer()
    {
        this->m_count = 0;
    }
    Printer(const Printer &p)
    {
        
    }
    
public:
    static Printer * getInstance()
    {
        return singleInstance;
    }
    void printText(string text)
    {
        this->m_count++;
        cout << text << endl;
        cout << "打印机打印次数" << this->m_count << endl;
    }
private:
    static Printer *singleInstance;
    int m_count;
};

Printer * Printer::singleInstance = new Printer;

void test()
{
    Printer *p1 = Printer::getInstance();
    Printer *p2 = Printer::getInstance();
    p1->printText("啊哈哈");
    p2->printText("娃哈哈");
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
