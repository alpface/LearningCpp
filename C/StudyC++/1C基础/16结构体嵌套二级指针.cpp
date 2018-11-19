//
//  结构体嵌套二级指针.cpp
//  StudyC++
//
//  Created by swae on 2018/11/10.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

struct Theater {
    char *name;       // 老师的名字
    char **studtents; // 老师所属的学生
};

/// 分配老师们的内存空间
/// @param temp 老师们的内存空间首地址指针
/// @param theaterCount 老师们的数量
/// @return 返回分配内存的状态码 0为分配成功
int allocSpace(struct Theater ***temp, int theaterCount)
{
    if (NULL == temp) {
        return -1;
    }
    struct Theater **list = (Theater **)malloc(sizeof(struct Theater *) * 3);
    for (int i = 0; i < theaterCount; ++i) {
        struct Theater *theater = (Theater *)malloc(sizeof(Theater));
        theater->name = (char *)malloc(sizeof(char) * 64);
        memset(theater->name, 0, 64);
        sprintf(theater->name, "Theater_%d", i+1);
        int studendCount = 6;
        char **students = (char **)malloc(sizeof(char *) * studendCount);
        for (int j = 0; j < studendCount; j++) {
            char *student = (char *)malloc(sizeof(char) * 64);
            memset(student, 0, 64);
            sprintf(student, "Student_%d", j+1);
            students[j] = student;
            
        }
        theater->studtents = students;
        list[i] = theater;
    }
    *temp = list;
    return EXIT_SUCCESS;
}

void printTheaters(struct Theater **theaters, int count)
{
    if (NULL == theaters) {
        return;
    }
    for (int i = 0; i < count; ++i) {
        printf(">>>theater.name:%s\n", theaters[i]->name);
        for (int j = 0; j < 6; ++j) {
            printf("|student%d:%s |", j, theaters[i]->studtents[j]);
            if (j == 6) {
                printf("<<<\n");
            }
        }
    }
}

void freeSpace(struct Theater **temp, int count)
{
    if (NULL == temp) {
        return;
    }
    for (int i = 0; i < count; ++i) {
        if (NULL == temp[i]) {
            continue;
        }
        if (NULL != temp[i]->name) {
            free(temp[i]->name);
            temp[i]->name = NULL;
        }
        if (NULL != temp[i]->studtents) {
            for (int j = 0; j < 6; ++j) {
                if (NULL != temp[i]->studtents[j]) {
                    free(temp[i]->studtents[j]);
                    temp[i]->studtents[j] = NULL;
                }
            }
            free(temp[i]->studtents);
            temp[i]->studtents = NULL;
        }
    }
    free(temp);
    temp = NULL;
}

void test()
{
    struct Theater **theaters = NULL;
    int res = allocSpace(&theaters, 3);
    if (res < 0) {
        printf("分配内存出错!");
        return;
    }
    printTheaters(theaters, 3);
    freeSpace(theaters, 3);
    theaters = NULL;
    
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
