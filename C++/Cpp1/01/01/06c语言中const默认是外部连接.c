//
//  06c语言中const默认是外部连接.c
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    // extern 告诉编译器a变量在外部，从外部查找a变量 
    extern const int a;
    printf("%d\n", a);
    return 0;
}
