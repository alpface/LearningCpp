//
//  07栈的应用-就近匹配.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/16.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqStack.h"

/*
 栈的应用案例 之 就近匹配

 叙述： 几乎所有的编译器都具有检测括号匹配的能力
 
 如何实现编译器中的符号检测？
 
 #include  <stdio.h> int main () {int a[4][4]; int (*p)[4]; p=a[4]; return 0;}
 
 算法思路：
 
 从第一个字符开始扫描；
 当遇到普通字符时忽略；
 当遇见左括号时压入栈中，
 当遇见右符号时，从栈中弹出栈顶符号，并进行匹配。
 匹配成功：继续读入下一个字符；匹配失败：立即停止，并报错。
 结束：
 成功：所有字符扫描完毕，且栈为空；
 失败：匹配失败或所有自负扫描完毕且栈非空。
 */

// 判断字符是否为右括号
int isLeft(char ch)
{
    return ch == '(';
}

// 判断字符是否为右括号
int isRight(char ch)
{
    return ch == ')';
}

/// 打印错误信息，并指向错误的那个字符
/// @param str 原字符串的内存首地址
/// @param errMsg 错误信息
/// @param pos 报错的字符串内存首地址
void printError(const char *str, const char *errMsg, char *pos)
{
    printf("错误信息:%s\n", errMsg);
    printf("%s\n", str);
    // 计算从错误位置到开始位置的偏移量：其实就是找到错误的字符之前的字符个数
    // str 字符串的首地址，pos为字符串中错误的位置，pos肯定比str大的
    long count = pos - str;
    for (int i = 0; i < count; ++i) {
        // 打印空格的目的是让↑在控制台指向上面的字符串错误的位置
        printf(" ");
    }
    printf("↑\n");
}

void test()
{
    const char *str = "8+9(dsh)[00(jj)(哈哈啊))";
    char *p = (char *)str;
    
    // 初始化栈
    SeqStack stack = Init_SeqStack();
    
    while (*p != '\0') {
        // 判断当前字符是否为左括号，如果为左括号就压入栈
        if (isLeft(*p)) {
            Push_SeqStack(stack, p);
        }
        
        // 判断当前字符是否为右括号
        if (isRight(*p)) {
            if (Size_SeqStack(stack) > 0) {
                // 弹出栈顶
                Pop_SeqStack(stack);
            }
            else {
                printError(str, "右括号没有匹配左括号", p);
            }
        }
        p++;
    }
    
    while (Size_SeqStack(stack) > 0) {
        printError(str, "没有匹配到右括号", (char *)Top_SeqStack(stack));
        Pop_SeqStack(stack);
    }
    
    Destory_SeqStack(stack);
    stack = NULL;
}


int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
