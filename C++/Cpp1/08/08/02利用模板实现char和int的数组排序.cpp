//
//  02利用模板实现char和int的数组排序.cpp
//  08
//
//  Created by swae on 2018/11/24.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

// 示例：对char和int数组进行排序，排队规则从大到小，算法：选择排序

#include <iostream>

using namespace std;

template <class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 选择排序
template <class T>
void mySort(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        int max = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[max] < arr[j]) {
                // 交换下标
                max = j;
            }
        }
        if (max != i) {
            // 交换数据
            mySwap(arr[max], arr[i]);
        }
    }
}

// 输出数组的元素
template <class T>
void printArray(T arr[], int len)
{
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test()
{
    // char类型的数组
    char charArr[] = "helloworld";
    mySort(charArr, sizeof(charArr) / sizeof(char));
    printArray(charArr, sizeof(charArr) / sizeof(char));
    
    // int 类型数组
    int intArr[] = {1, 2, 4, 20, 18, 7, 9, 3};
    mySort(intArr, sizeof(intArr) / sizeof(int));
    printArray(intArr, sizeof(intArr) / sizeof(int));
}

int main(int argc, const char *argv[])
{
    test();
    return EXIT_SUCCESS;
}
