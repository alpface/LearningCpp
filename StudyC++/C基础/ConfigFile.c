//
//  ConfigFile.c
//  StudyC++
//
//  Created by swae on 2018/11/11.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "ConfigFile.h"
// 获取文件有效的行数
int getLines_configFile(FILE *file) {
    char buff[1024] = {0};
    int lines = 0;
    while (fgets(buff, 1024, file)) {
        if (!isVilid_configFile(buff)) {
            continue;
        }
        lines++;
        memset(buff, 0, 1024);
    }
    // 把文件指针重置到文件开头
    fseek(file, 0, SEEK_SET);
    return lines;
}
// 加载配置文件
void loadFile_configFile(const char *filePath, char ***fileData, int *lines) {
    FILE *file = fopen(filePath, "r");
    
    if (NULL == file) {
        return;
    }
    
    // 按行读取配置文件，每一行必须是key:value形式，才是有效的，否则会被忽略掉
    // 获取行数
    int numberOflines = getLines_configFile(file);
    
    // 分配读取文件后保存的内存
    char **tempData = (char **)malloc(sizeof(char *) * numberOflines);
    
    char lineBuf[1024] = { 0 };
    int index = 0;
    while (fgets(lineBuf, 1024, file) != NULL) {
        
        // 判断当前行是否为有效的数据
        if (!isVilid_configFile(lineBuf)) {
            continue;
        }
        char *buff = malloc(strlen(lineBuf) + 1); // +1 是\0
        strcpy(buff, lineBuf);
        tempData[index] = buff;
        // 清空临时变量lineBuf
        memset(lineBuf, 0, 1024);
        index++;
    }
    
    if (fileData) {
        *fileData = tempData;
    }
    if (lines) {
        *lines = numberOflines;
    }
    // 关闭文件
    fclose(file);
    if (file != NULL) {
        file = NULL;
    }
}
// 解析配置文件
void parseFile_configFile(char **fileData, int lines, struct ConfigInfo **infos) {
    if (infos == NULL) {
        return;
    }
    struct ConfigInfo *infosPointer = malloc(sizeof(struct ConfigInfo *) * lines);
    // 一次性初始化*infos所指向的所有内存
    memset(infosPointer, 0, sizeof(struct ConfigInfo) * lines);
    for (int i = 0; i < lines; ++i) {
        char *lineBuff = fileData[i];
        // 找到:的位置，把前面的切出来赋值给key，把后面的切出来赋值给value
        // 找到:
        char *pos = strchr(lineBuff, ':');
        struct ConfigInfo info = infosPointer[i];
        // 将:前面的字符串拷贝给info的key
        strncpy(info.key, lineBuff, pos - lineBuff);
        // 将:后面的字符串拷贝给info的value
        strncpy(info.value, pos+1, strlen(pos + 1)-1);
        printf("%s:%s\n", info.key, info.value);
        infosPointer[i] = info;
    }
    *infos = infosPointer;
    
    // 释放文件信息
    for (int i = 0; i < lines; ++i) {
        if (fileData[i] != NULL) {
            free(fileData[i]);
            fileData[i] = NULL;
        }
    }
}
// 获取指定配置信息
char *getInfo_configFile(const char *key, struct ConfigInfo *infos, int lines) {
    for (int i = 0; i < lines; ++i) {
        struct ConfigInfo info = infos[i];
        /**
         int strcmp(const char *str1, const char *str2)
         参数
         str1 -- 要进行比较的第一个字符串。
         str2 -- 要进行比较的第二个字符串。
         返回值
         如果返回值 < 0，则表示 str1 小于 str2。
         如果返回值 > 0，则表示 str2 小于 str1。
         如果返回值 = 0，则表示 str1 等于 str2。
         */
        if (strcmp(key, info.key) == 0) {
            return info.value;
        }
    }
    return NULL;
}
// 释放配置文件信息
void destoryInfo_configFile(struct ConfigInfo *info) {
    if (NULL == info) {
        free(info);
        info = NULL;
    }
}
// 判断当前行是否有效
int isVilid_configFile(const char *buf) {
    /*
     strchr() C 库函数 char *strchr(const char *str, int c) 在参数 str 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置。
     该函数返回在字符串 str 中第一次出现字符 的位置，如果未找到该字符则返回 NULL。
     */
    if (buf[0] == '#' || // 开头为#开头的是注释
        buf[0] == '\n' || // 开头为换行的是空行
        strchr(buf, ':') == NULL) // 不包含:的是不是key:value
    {
        return 0;
    }
    
    return 1;
}

void test()
{
    char **fileData = NULL;
    int lines = 0;
    char *filePath = "/Users/xiaoyuan/Destop/work/GitHub/StudyC++/StudyC++/C基础/19config.ini";
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
