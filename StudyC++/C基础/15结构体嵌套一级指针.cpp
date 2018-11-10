//
//  结构体嵌套一级指针.cpp
//  StudyC++
//
//  Created by xiaoyuan on 2018/11/9.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

struct Person {
    char *name;
    int age;
};

// 分配内存
struct Person **allocSpace(int size)
{
    struct Person **temp = (Person **)malloc(sizeof(struct Person *) * size);
    for (int i = 0; i < size; ++i) {
        struct Person *p = (Person *)malloc(sizeof(struct Person));
        p->name = (char *)malloc(sizeof(char *) * 64);
        sprintf(p->name, "Name_%d", i);
        p->age = 100 + i;
        temp[i] = p;
    }
    return temp;
}

void printPerson(struct Person **person, int size)
{
    if (NULL == person) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (NULL == person[i]->name) {
            continue;
        }
        printf("Name: %s  age: %d\n", person[i]->name, person[i]->age);
    }
}

void freePerson(struct Person **person, int size)
{
    if (NULL == person) {
        return;
    }
    
    for (int i = 0; i < size; ++i) {
        if (NULL == person[i]->name) {
            continue;
        }
        free(person[i]->name);
        person[i]->name = NULL;
    }
    free(person);
    person = NULL;
}

void test()
{
    struct Person **p = NULL;
    p = allocSpace(3);
    printPerson(p, 3);
    freePerson(p, 3);
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
