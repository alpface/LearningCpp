//
//  19配置文件解析封装.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/12.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "ConfigFile.h"

void test()
{
    char **fileData = NULL;
    int lines = 0;
    const char *filePath = "/Users/xiaoyuan/Destop/work/GitHub/StudyC++/StudyC++/C基础/19config.ini";
    struct ConfigInfo *infos = NULL;
    loadFile_configFile(filePath, &fileData, &lines);
    parseFile_configFile(fileData, lines, &infos);
    char *value = getInfo_configFile("username", infos, lines);
    printf("%s\n", value);
    destoryInfo_configFile(infos);
    return;
}



int main(int argc, const char *argv[])
{
    test();
    return 0;
}

