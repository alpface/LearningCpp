//
//  选择排序.cpp
//  04
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

//每一趟在n-i+1(i=1,2,...,n-1)个记录中选取关键字最小的记录作为有序序列中第i个记录
#include <iostream>
using namespace std;

void selectSort(int a[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int lowIndex =i;
        for(int j=size-1;j>i;j--)
            if(a[j]<a[lowIndex])
                lowIndex=j;
        int temp=a[i];
        a[i]=a[lowIndex];
        a[lowIndex]=temp;
    }
}

int main()
{
    int a[]={12,36,24,85,47,30,53,91};
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    selectSort(a,8);
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    return 0;
}

