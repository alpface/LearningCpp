//
//  结构体的基本概念.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/9.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

#if 0
// Typedef 定义结构体时，struct 结构体名和 定义的名字，可以一致，但是我们开发中尽量不要这么写，为了防止有些系统编译不过
typedef struct _Person {
    char name[64];
    int age;
    
} Person;

#endif

// 注意: 定义结构体时，不要给成员变量直接赋值，结构体只是一个类型，编译器还未给其分配空间，只有其类型定义为变量时，才会为其分配内存空间，有了空间才能赋值

// 结构体的多种写法

// 在声明Person类型的结构体时，同时定义变量person
struct Person {
    char name[64];
    int age;
} person = {"xiaoyuan", 20};


// 直接定义结构体类型变量obama, 没有结构体类型
// 注意: 这种写法是最没人用的，因为它的定义是一次性的
struct {
    char name[64];
    int age;
} obama = {"obama", 50};

void test()
{
    strcpy(person.name, "Lily");
    person.age = 10;
    printf("Name: %s, age: %d\n", person.name, person.age);
    
    strcpy(obama.name, "Obama");
    obama.age = 100;
    printf("obama name: %s, age: %d\n", obama.name, obama.age);
}

void test1()
{
    // 在栈上分配结构体空间
    struct Person p = {"符楠楠", 28};
    printf("Name: %s, age: %d\n", p.name, p.age);
    
    // 在堆上分配结构体空间
    struct Person *pp = (Person *)malloc(sizeof(struct Person));
    strcpy(pp->name, "孙莎莎");
    pp->age = 27;
    printf("Name: %s, age: %d\n", pp->name, pp->age);
    free(pp);
    pp = NULL;
}


void printPerons(struct Person *persons, int len)
{
    for (int i = 0; i < len; ++i) {
        printf("name: %s -- age: %d\n", persons[i].name, persons[i].age);
    }
}

// 多个结构体变量
void test2()
{
    // 在栈上分配结构体数组空间
    struct Person pList[] = {
        {"小拉", 28},
        {"衣岑", 10},
        {"glily", 29},
        {"aaaa", 29},
        {"bbbb", 20},
    };
    int len = sizeof(pList) / sizeof(struct Person);
    printPerons(pList, len);
    
    // 在堆上分配结构体数组空间
    int heapPersonsLen = 5;
    struct Person *heapPersons = (Person *)malloc(sizeof(struct Person) * heapPersonsLen);
    for (int i = 0; i < heapPersonsLen; ++i) {
        sprintf(heapPersons[i].name, "name_%d", i);
        heapPersons[i].age = 20+i;
    }
    printPerons(heapPersons, heapPersonsLen);
    if (heapPersons != NULL) {
        free(heapPersons);
        heapPersons = NULL;
    }
}

int main(int argc, const char *arhv[])
{
//    test();
//    test1();
    test2();
    return EXIT_SUCCESS;
}
