//
//  07案例-员工分组.cpp
//  02
//
//  Created by xiaoyuan on 2018/11/28.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
 //multimap 案例
 //公司今天招聘了 5 个员工，5 名员工进入公司之后，需要指派员工在那个部门工作
 //人员信息有: 姓名 年龄 电话 工资等组成
 //通过 Multimap 进行信息的插入 保存 显示
 //分部门显示员工信息 显示全部员工信息
 
 */

// 定义三个部门
enum {RENLI, YANFA,MEIGONG};

// 员工类
class Worker {
    
public:
    Worker(string name, int money):m_name(name), m_money(money){}
    string m_name;
    int m_money;
};

// 创建5名员工
void createWorkers(vector<Worker> &v)
{
    string names = "ABCDE";
    for (int i = 0; i < names.size(); ++i) {
        string name = "worker";
        name=+names[i];
        int money = rand() % 10000 + 10000; // 10000 ~ 19999之间
        Worker w(name, money);
        v.push_back(w);
    }
}

// 分配部门
// 将vector中的员工，放到multimap中
void setGroup(vector<Worker> &w, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = w.begin(); it != w.end(); it++) {
        // 随机生成3个部门的编号
        int num = rand() % 3; //0 ~ 3
        // 将员工分配到multimap中
        m.insert(make_pair(num, *it));
    }
}

void showGroup(multimap<int, Worker> &m)
{
    cout << "人力部门的员工如下:" << endl;
    multimap<int, Worker>::iterator itpos = m.find(RENLI);
    size_t num = m.count(RENLI);
    int index = 0;
    for (; itpos != m.end(),index < num; itpos++, index++) {
        cout << "姓名:" << itpos->second.m_name << " 工资:" << itpos->second.m_money << endl;
    }
    
    cout << "_______________________" << endl;
    
    cout << "研发部门的员工如下:" << endl;
    itpos = m.find(YANFA);
    index = 0;
    num = m.count(YANFA);
    for (; itpos != m.end(), index < num; itpos++, index++) {
        cout << "姓名:" << itpos->second.m_name << " 工资:" << itpos->second.m_money << endl;
    }
    
    cout << "_______________________" << endl;
    
    cout << "美工部门的员工如下:" << endl;
    itpos = m.find(MEIGONG);
    index = 0;
    num = m.count(MEIGONG);
    for (; itpos != m.end(), index < num; itpos++, index++) {
        cout << "姓名:" << itpos->second.m_name << " 工资:" << itpos->second.m_money << endl;
    }
}

int main(int argc, const char *argv[])
{
    // 设置随机数种子
    srand((unsigned int)time(NULL));
    
    // 声明存放员工的容器
    vector<Worker> w;
    // 创建5名员工
    createWorkers(w);
    // 声明存放部门的容器
    multimap<int, Worker> mul;
    // 为这5名员工分配部门
    setGroup(w, mul);
    // 查看部门
    showGroup(mul);
    return EXIT_SUCCESS;
}
