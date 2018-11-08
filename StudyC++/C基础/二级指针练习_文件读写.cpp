//
//  二级指针练习_文件读写.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/8.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

// 根据test.text 中每行文本的长度开辟内存空间


/// 获取文件行数
int numberOfLinesInFile(FILE *file)
{
    if (file == NULL) {
        return -1;
    }
    // 创建缓存区, 用于保存，读取到当前行的内容
    char buff[1024] = {0};
    int numberOfLines = 0;
    while (fgets(buff, 1024, file) != NULL) {
        ++numberOfLines;
    }
    
    // 恢复文件指针，将文件指针指向文件起始位置，不然文件指针将指向文件末尾
    fseek(file, 0, SEEK_SET);
    
    return numberOfLines;
}

// 读取文件数据
void readFileData(FILE *file, int lines, char **contents)
{
    if (NULL == file) {
        return;
    }
    if (lines <= 0) {
        return;
    }
    if (NULL == contents) {
        return;
    }
    char buff[1204] = { 0 };
    int index = 0;
    while (fgets(buff, 1024, file)) {
        printf("%s", buff);
        size_t currentLen = strlen(buff) + 1;
        char *lineContent = (char *)malloc(sizeof(char)*currentLen);
        strcpy(lineContent, buff);
        contents[index++] = lineContent;
        memset(buff, 0, 1024);
    }
    
    fseek(file, 0, SEEK_SET);
}

void showFileContent(char **contents, int lines)
{
    for (int i = 0; i < lines; ++i) {
        printf("%d行: %s", i, contents[i]);
    }
}

void freeSpace(char **contents, int lines)
{
    for (int i = 0; i < lines; ++i) {
        if (NULL != contents[i]) {
            free(contents[i]);
            contents[i] = NULL;
        }
    }
    free(contents);
    contents = NULL;
}

void test()
{
    FILE *file = fopen("/Users/xiaoyuan/Destop/work/GitHub/StudyC++/StudyC++/test.txt", "r");
    int lines = numberOfLinesInFile(file);
    printf("lines = %d\n", lines);

    char **contents = (char **)malloc(sizeof(char **)*lines);
    // 读取文件内容
    readFileData(file, lines, contents);
    // 关闭文件
    fclose(file);
    file = NULL;
    // 打印文件内容
    showFileContent(contents, lines);
    // 释放文件
    freeSpace(contents, lines);
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
