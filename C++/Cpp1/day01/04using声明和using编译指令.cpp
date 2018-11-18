//
//  04using声明和using编译指令.cpp
//  day01
//
//  Created by swae on 2018/11/18.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>

using namespace std;

namespace KingGlory {
    int userId = 10;
}

void test1()
{
    int userId = 10;
     // using 声明 注意避免二次定义问题
    // 使用using KingGlory::userId;声明后，看到userId这个变量就使用KingGlory中的
    // 但是编译器又有就近原则，所以会出现二议性
//    using KingGlory::userId;
    // Error: Target of using declaration conflicts with declaration already in scope
    
}

namespace LOL {
    int userId = 1000;
}

void test2()
{
    // using 编译指令
    using namespace LOL; // 打开LOL
    using namespace KingGlory; // 打开KingGlory
    // 如果打开多个命名空间，且他们里面有相同的函数或变量，也会编译不过
//    cout << userId << endl;
}

int main(int argc, const char *argv[])
{
    test2();
    return EXIT_SUCCESS;
}
