//
//  01强化对象-数组封装.cpp
//  05
//
//  Created by xiaoyuan on 2018/11/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
#include "MyArray.hpp"

using namespace std;

void test()
{
    MyArray *arr1 = new MyArray(80);
    for (int i = 0; i < 30; ++i) {
        arr1->push_Back(i);
    }
    
    for (int i = 0; i < arr1->getSize(); ++i) {
        cout << (*arr1)[i] << endl;
    }
    
    arr1->push_Back(22);
    
    cout << "--------------" << endl;
    // 拷贝
    MyArray *arr2 = new MyArray(*arr1);
    for (int i = 0; i < arr1->getSize(); ++i) {
        cout << (*arr2)[i] << endl;
    }
    
    delete arr1;
    delete arr2;
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
