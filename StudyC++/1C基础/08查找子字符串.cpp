//
//  查找子字符串.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/8.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>

// 查找子字符串第一次出现的位置
const char *searchString(const char *string, const char *subString)
{
    const char *myStr = string;
    const char *mySub = subString;
    // 匹配到最后一个结束循环
    while (*mySub != '\0') {
        // 逐个匹配，如果当前字符不是要匹配的第一个字符，就跳过本次循环
        if (*mySub != *myStr) {
            ++myStr;
            continue;
        }
        // 定义临时指针 变量
        const char *temp_myStr = myStr;
        const char *temp_mySub = mySub;
        while (*temp_mySub != '\0') {
            if (*temp_mySub != *temp_myStr) {
                ++myStr;
                break;
            }
            ++temp_myStr;
            ++temp_mySub;
            // 最后一个匹配完成， 说明匹配成功
            if (*temp_mySub == '\0') {
                return myStr;
            }
        }
    }
    return NULL;
}

void test1()
{
    const char *str = "1111abcfdefg";
    const char *sub = "de";
    const char *result = searchString(str, sub);
    printf("result = %s\n", result);
}

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}
