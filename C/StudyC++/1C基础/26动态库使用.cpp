//
//  26动态库使用.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/14.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "MyDylib.h"


int main(int argc, const char *argv[])
{
    int res = myDylibAdd(10, 30);
    printf("%d\n", res);
    
    return EXIT_SUCCESS;
}
