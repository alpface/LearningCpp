//
//  09类模板的分文件编写问题以及解决.cpp
//  08
//
//  Created by swae on 2018/11/25.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include "Person.hpp"

// 约定成俗 建议模板类不要分文件编写，比如Person.hpp中的Person，写到一个文件中，这个文件是hpp类型的

void test()
{
    Person<string, int> p("xiaoyuan", 18);
    p.showPerson();
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
