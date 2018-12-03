//
//  11案例-STL综合案例.cpp
//  03
//
//  Created by xiaoyuan on 2018/12/3.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <numeric>
using namespace std;

/*
 01. 产生选手（ABCDEFGHIJKLMNOPQRSTUVWX） 姓名、得分、选手编号
 02. 选手抽签、选手比赛、查看比赛结果
 03. 选手抽签、选手比赛、查看选手结果
 04. 选手抽签、选手比赛、查看选手结果
 */

// 选手类
class Speaker {
    
public:
    string m_name;   // 姓名
    int m_score[3];  // 得分数组
};

// 创建选手们
void createSpeakers(vector<int> &v, map<int, Speaker> &m)
{
    string names = "ABCDEFGHIJKLMNOPQRSTUVWX";
    for (int i = 0; i < names.size(); ++i) {
        string name = "Speaker";
        name += names[i];
        Speaker sp;
        sp.m_name = name;
        for (int j = 0; j < 3; ++j) {
            sp.m_score[j] = 0;
        }
        int id = i+100; // 编号 100 ~ 123
        v.push_back(id);
        m.insert(make_pair(id, sp));
    }
}

// 抽签
void speechDraw(vector<int> &v)
{
    random_shuffle(v.begin(), v.end());
}

/// 比赛
/// @param index 第几轮
/// @param v1 比赛选手编号
/// @param m key是比赛选手编号和value其对应的选手
/// @param v2 晋级选手编号容器
void speechContest(int index, vector<int> &v1, map<int, Speaker> &m, vector<int> &v2)
{
    // 定义临时容器
    multimap<int, int, greater<int>> groupMap; // key是分数，value是编号
    int num = 0;
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
        num++;
        deque<int> dq;
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 + 60; // 60~100
            dq.push_back(score);
        }
        // 排序
        sort(dq.begin(), dq.end());
        // 去除最高分和最低分
        dq.pop_back();
        dq.pop_front();
        // 累加总分数
        int sum = accumulate(dq.begin(), dq.end(), 0);
        // 计算平均分
        int avg = sum / dq.size();
        // 将平均分放到容器中
        m[*it].m_score[index-1] = avg;
        
        // 每6个人取前三名晋级
        groupMap.insert(make_pair(avg, *it));
        if (num % 6 == 0) {
//            cout << "小组比赛成绩如下：" << endl;
//            for (multimap<int,  int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(); ++mit) {
//                cout << "编号：" << mit->second << " 姓名：" << m[mit->second].m_name << " 得分：" << m[mit->second].m_score[index-1] << endl;
//            }
            // 取出前三名
            int count = 0;
            for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(), count < 3; mit++, count++) {
                // 晋级容器，添加数据
                v2.push_back(mit->second);
            }
            // 清空临时容器
            groupMap.clear();
        }
       
    }
}

// 显示分数
void showScore(int index, vector<int> &v, map<int, Speaker> &m)
{
    cout << "第" << index << "轮比赛成绩如下："<< endl;
    for (map<int,Speaker>::iterator mit = m.begin(); mit != m.end(); ++mit) {
        cout << "选手编号：" << mit->first << " 姓名：" << mit->second.m_name << " 选手分数：" << mit->second.m_score[index-1] << endl;
    }
    cout << "晋级选手编号:" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
}

void test()
{
    // 随机数种子
    srand((unsigned int)time(NULL));
    
    vector<int> v1; // 存放选手们的编号
    map<int, Speaker> m; // 存放选手编号和对应的具体选手对象
    // 创建选手们
    createSpeakers(v1, m);
    // 抽签
    speechDraw(v1);
    // 进入下一轮比赛的人员编号
    vector<int> v2;
    
    // 第一轮比赛
    speechContest(1, v1, m, v2);
    // 查看比分
    showScore(1, v1, m);
    
    // 第二轮比赛
    speechDraw(v1);
    // 参加下一轮比赛的人员编号
    vector<int> v3;
    speechContest(2, v2, m, v3);
    showScore(2, v2, m);
    
    // 第三轮比赛
    speechDraw(v1);
    vector<int> v4;
    speechContest(3, v3, m, v4);
    showScore(3, v3, m);
}

int main(int argc, const char*argv[])
{
    test();
    return EXIT_SUCCESS;
}
