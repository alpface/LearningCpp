//
//  17结构体偏移量.cpp
//  StudyC++
//
//  Created by swae on 2018/11/11.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

struct A {
    char c;
    int b;
};

void test()
{
    struct A a = {'a', 10};
    
    // 要求取出成员b的值
    
    // 第一种方式：通过成员距离结构体的偏移量取地址
    // offsetof(struct A, b) 获取b成员变量距离结构体首地址的偏移量
    // (char *)&a + offsetof(struct A, b)) 这是b的内存首地址
    // (int *)((char *)&a + offsetof(struct A, b))) 由于b是int类型，所以要强转为int *类型，此时通过此地址可以取出b的所有字节
    printf("a.b:%d\n", *(int *)((char *)&a + offsetof(struct A, b)));
    
    // 第二种方式：通过指针步长取成员的地址
    // 首先取出结构体的首地址 &a
    // 要取出的b成员属性为int类型，所以我们将&a强转为int *类型(int *)&a
    // 由于int是4个字节，要取出所以int类型的字节，只需要首地址+1即可
    printf("a.b:%d\n", *((int *)&a + 1));
    
    // 以上两种方式取值相当于，下面两种
    printf("%d\n", *(&a.b));
    printf("%d\n", a.b);
}

struct C {
    int a;
    double b;
};

struct B {
    char a;
    int b;
    struct C c;
};

void test1()
{
    // 创建结构体
    struct B b = {'a', 100, 200, 3.1415926};
    
    // 通过结构体的偏移量间接取出struct C 中b的值
    
    // 取出c在结构体B中的偏移量
    int off1 = offsetof(struct B, c);
    // 取出b在结构体C中的偏移量
    int off2 = offsetof(struct C, b);
    
    // 打印b.c.b的值 printf("%f\n", b.c.b);
    // &(b.c.b) 和 ((char *)&b + off1) + off2 指向的同一块内存空间，都是b.c.b的首地址
    printf("%f\n", *(double *)((char *)&b + off1 + off2));
    
    // 其他方式：取出结构体B中c属性的地址，将其强转为(struct C *)指针类型，再通过→取值
    printf("%f\n", ((struct C *)((char *)&b + off1))->b);
}

int main(int argc, const char * argv[])
{
//    test();
    test1();
    return EXIT_SUCCESS;
}
