//
//  26静态库使用.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/14.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "MyLib.h"

void test()
{
    // 编译myLibAdd()函数时，实际链接的是libMyLib.a中的MyLib.c中的myLibAdd()函数。
    // 原因：我将MyLib.c添加到MyLib这个静态库的target中，而为添加到studyC++这个target中，所以MyLib.c不会在本项目中
    int c = myLibAdd(1, 2);
    printf("%d\n", c);
}

int main(int argc, const char *argv[])
{
    test();
    
    return EXIT_SUCCESS;
}
