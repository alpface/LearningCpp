//
//  02 strcpy、strncpy与memcpy的区别与使用方法.h
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/14.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//


/*
 strcpy、strncpy与memcpy的区别与使用方法
 
 strcpy、strncpy、memcpy这三个C语言函数我们在主机代码编写中会很频繁的使用到，但是三个函数的区别、使用时该注意什么还是有必要说下的。
 
 本文参考《C 标准库》编写。
 
 一、函数说明
 
 1、memcpy函数
 
 void  *memcpy(void *s1,  const void *s2,  size_t  n);
 
 说明：
 
 函数memcpy从s2指向的对象中复制n个字符到s1指向的对象中。如果复制发生在两个重叠的对象中，则这种行为未定义。
 
 返回值：
 
 函数memcpy返回s1的值。
 
 2、strcpy函数
 
 char  *strcpy(char *s2, const char *s1);
 
 说明：
 
 函数strcpy把s1指向的串（包括空字符）复制到s2指向的数组中。如果复制发生在两个重叠的对象中，则这种行为未定义。
 
 返回值：
 
 函数strcpy返回s2的值。
 
 3、strncpy函数
 
 char  *strncpy(char *s2, const char *s1, size_t n);
 
 说明：
 
 函数strncpy从s1指向的数组中最多复制n个字符（不复制空字符后面的字符）到s2指向的数组中。如果复制发生在两个重叠的对象中，则这种行为未定义。
 
 如果s1指向的数组是一个比n短的字符串，则在s2定义的数组后面补空字符，直到写入了n个字符。
 
 返回值：
 
 函数strncpy返回s2的值。
 
 二、注意事项
 
 strcpy 是依据 “\0” 作为结束判断的，如果 s2 的空间不够，则会引起 buffer overflow。
 
 memcpy用来在内存中复制数据，由于字符串是以“\0”结尾的，所以对于在数据中包含“\0”的数据只能用memcpy，如:"hell\0oworld"。
 
 Strncpy和memcpy很相似，只不过它在一个终止的空字符处停止。当n>strlen(s1)时，给s2不够数的空间里填充“\0”；当n<=strlen(s1)时，s2是没有结束符“\0”的。
 
 这里隐藏了一个事实，就是s2指向的内存一定会被写n个字符。
 
 所以总的来说注意：
 
 1、s2指向的空间要足够拷贝；使用strcpy时，s2指向的空间要大于等于s1指向的空间；使用strncpy或memcpy时，s2指向的空间要大于或等于n。
 
 2、使用strncpy或memcpy时，n应该大于strlen(s1)，或者说最好n >= strlen(s1)+1；这个1 就是最后的“\0”。
 
 3、使用strncpy时，确保s2的最后一个字符是“\0”。
 */
