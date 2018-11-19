//
//  ConfigFile.h
//  StudyC++
//
//  Created by swae on 2018/11/11.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//  配置文件操作接口封装 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 防止头文件重复包含
#pragma once

struct ConfigInfo {
    char key[64];
    char value[128];
};

// extern "C"目的是为了在c++中能够调用c写的函数
// 注意: 只需要在c的头文件中写，c++的头文件不需要写
#ifdef __cplusplus
    extern "C"{
#endif
        
        // 获取文件有效的行数
        int getLines_configFile(FILE *file);
        // 加载配置文件
        void loadFile_configFile(const char *filePath, char ***fileData, int *lines);
        // 解析配置文件
        void parseFile_configFile(char **fileData, int lines, struct ConfigInfo **infos);
        // 获取指定配置信息
        char *getInfo_configFile(const char *key, struct ConfigInfo *infos, int lines);
        // 释放配置文件信息
        void destoryInfo_configFile(struct ConfigInfo *info);
        // 判断当前行是否有效
        int isVilid_configFile(const char *buf);

#ifdef __cplusplus
    }
#endif
