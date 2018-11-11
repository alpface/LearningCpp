//
//  18文件操作复习.cpp
//  StudyC++
//
//  Created by swae on 2018/11/11.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

void test()
{
    FILE *file = fopen("/Users/swae/Documents/Github/StudyC-/StudyC++/C基础/18text.txt", "r");
    if (NULL == file) {
        printf("打开文件失败\n");
        return;
    }
    
    
    // feof(file) 函数
    /*
     feof()函数是判断文件是否读取到文件结尾，而文件结尾是以EOF为标志的
     EOF
     EOF是一个计算机术语，为End Of File的缩写，在操作系统中表示资料源无更多的资料可读取。资料源通常称为档案或串流。通常在文本的最后存在此字符表示资料结束。
     这个定义的意思是，文档的结尾都有一个隐藏字符”EOF”，当程序读取它的时候，就会知道文件已经到达结尾。通常使用while循环加EOF判断作为读取结束的标志。
     EOF 的值通常为 -1，但它依系统有所不同。
     */
    /*
     feof()
     
     feof()的原理：
     feof()函数，并不是通过读取到文件的EOF来评判，这个文件是否为空。
     对feof()来说,它的工作原理是，站在光标所在位置，向后看看还有没有字符。如果有，返回0；如果没有，返回非0。它并不会读取相关信息，只是查看光标后是否还有内容。
     直接使用时的错误分析：
     对于一个空文件来说，当程序打开它的时候，它的光标会停在文件的开头，但是由于文件里什么内容都没有存（但是EOF是存在的），即整个文件就存贮了一个EOF。当程序打开文件，并直接调用feof()时，这个函数就会站在光标的位置向后张望，结果就看见了EOF，然后就当然返回0了。
     */
#if 0
    
    // 这种打印方式会导致文件默认出现奇怪的字符，那就是EOF
    // aaaaaaaaaaaaaa\377Program ended with exit code: 0
    char ch;
    while (!feof(file)) {
        // 读取字符
        ch = fgetc(file);
        printf("%c", ch);
    }
#else
#if 0
    // 正确方式1
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
#else
    // 正确方式2
    char ch;
    while (!feof(file)) {
        ch = fgetc(file);
        if (ch == EOF) {
            break;
        }
        printf("%c", ch);
    }
    
#endif
    
#endif
    fclose(file);
    file = NULL;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
