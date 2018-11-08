//
//  格式化字符串.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/7.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

static void test()
{
    // 1 格式化字符串
    char buffer[1024] = { 0 };
    sprintf(buffer, "Hello %s", "XijinPing");
    printf("%s\n", buffer);
    
    // 2 拼接字符串
    const char *s1 = "Hello";
    const char *s2 = "World";
    memset(buffer, 0, 1024);
    sprintf(buffer, "%s %s", s1, s2);
    printf("%s\n", buffer);
    
    // 3 数字转成字符串
    int number = 666;
    memset(buffer, 0, 1024);
    sprintf(buffer, "双击%d\n", number);
    printf("%s\n", buffer);
    
    // 4
    char **p = (char **)malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; ++i) {
        p[i] = (char *)malloc(64);
        memset(p[i], 0, 64);
        sprintf(p[i], "name_%d", i);
    }
    // 打印字符串
    for (int i = 0; i < 5; ++i) {
        printf("%s\n", p[i]);
    }
    // 释放字符串
    for (int i = 0; i < 5; ++i) {
        if (NULL != p[i]) {
            free(p[i]);
            p[i] = NULL;
        }
    }
    if (NULL != p) {
        p = NULL;
    }
}

int main(int argc, const char *argv[])
{
    test();
}
