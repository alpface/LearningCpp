//
//  Const的使用.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/8.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

struct Person {
    char name[64];
    int ID;
    double score;
    int age;
};

// 规避指针地址传递的副作用
void printPerson(const struct Person *p)
{

    // 参数为const则无法通过指针地址修改值
//    for (int i = 0; i < 5; ++i) {
//        sprintf(&p->name[i], "%d", i);
//    }
    printf("name = %s, ID = %d, sroce = %f, age = %d", p->name, p->ID, p->score, p->age);
}

void test()
{
    struct Person p = {"trump", 1000, 66.7, 55};
    
    printPerson(&p);
}


int main(int argc, const char *argv[])
{
    test();
    return 0;
}
