//
//  08友元类.cpp
//  04
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

/*
 =======================什么是友元类=======================
 
 当一个类B成为了另外一个类A的“朋友”时，那么类A的私有和保护的数据成员就可以被类B访问。我们就把类B叫做类A的友元。
 
 =======================友元类能做什么=======================
 
 友元类可以通过自己的方法来访问把它当做朋友的那个类的所有成员。但是我们应该注意的是，我们把类B设置成了类A的友元类，但是这并不会是类A成为类B的友元。说白了就是：甲愿意把甲的秘密告诉乙，但是乙不见得愿意把乙自己的秘密告诉甲。
 
 =======================友元类的声明方法和其用法=======================
 
 声明友元类的方法其实很简单，只要我们在类A的成员列表中写下如下语句：
 
 friend class B;
 　　这样一来，类B就被声明成了类A的友元。注意，类B虽然是类A的友元，但是两者之间不存在继承关系。这也就是说，友元类和原来那个类之间并没有什么继承关系，也不存在包含或者是被包含的关系
 

 */

/*
=======================友元类的一个具体例子=======================

在这里，我们引用一个我从网上收集到的例子来说明友元类的作用：假设我们要设计一个模拟电视机和遥控器的程序。大家都之道，遥控机类和电视机类是不相包含的，而且，遥控器可以操作电视机，但是电视机无法操作遥控器，这就比较符合友元的特性了。即我们把遥控器类说明成电视机类的友元。下面是这个例子的具体代码：
*/

using namespace std;
class TV
{
    
public:
    // 把Tele作为友元类，在Tele中就可以访问TV的所有private和protected的成员了
    friend class Tele;
    TV():on_off(off),volume(20),channel(3),mode(tv){}
private:
    enum
    {
        on,
        off
    };
    enum
    {
        tv,
        av
    };
    enum
    {
        minve,
        maxve=100
    };
    enum
    {
        mincl,
        maxcl=60
    };
    bool on_off;
    int  volume;
    int channel;
    int mode;
};
class Tele
{
public:
    void OnOFF(TV&t)
    {
        t.on_off=(t.on_off==t.on)?t.off:t.on;
    }
    void SetMode(TV&t)
    {
        t.mode=(t.mode==t.tv)?t.av:t.tv;
    }
    bool VolumeUp(TV&t);
    bool VolumeDown(TV&t);
    bool ChannelUp(TV&t);
    bool ChannelDown(TV&t);
    void show(TV&t)const;
};
bool Tele::VolumeUp(TV&t)
{
    if (t.volume<t.maxve)
    {
        t.volume++;
        return true;
    }
    else
    {
        return false;
    }
}
bool Tele::VolumeDown(TV&t)
{
    if (t.volume>t.minve)
    {
        t.volume--;
        return true;
    }
    else
    {
        return false;
    }
}
bool Tele::ChannelUp(TV&t)
{
    if (t.channel<t.maxcl)
    {
        t.channel++;
        return true;
    }
    else
    {
        return false;
    }
}
bool Tele::ChannelDown(TV&t)
{
    if (t.channel>t.mincl)
    {
        t.channel--;
        return true;
    }
    else
    {
        return false;
    }
}
void Tele::show(TV&t)const
{
    if (t.on_off==t.on)
    {
        cout<<"电视现在"<<(t.on_off==t.on?"开启":"关闭")<<endl;
        cout<<"音量大小为："<<t.volume<<endl;
        cout<<"信号接收模式为："<<(t.mode==t.av?"AV":"TV")<<endl;
        cout<<"频道为："<<t.channel<<endl;
        
    }
    else
    {
        cout<<"电视现在"<<(t.on_off==t.on?"开启":"关闭")<<endl;
    }
    
}

void test()
{
    Tele t1;
    TV t2;
    t1.show(t2);
    t1.OnOFF(t2);
    t1.show(t2);
    cout<<"调大声音"<<endl;
    t1.VolumeUp(t2);
    cout<<"频道+1"<<endl;
    t1.ChannelUp(t2);
    cout<<"转换模式"<<endl;
    t1.SetMode(t2);
    t1.show(t2);
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
