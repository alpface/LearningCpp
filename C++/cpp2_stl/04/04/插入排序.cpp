//
//  插入排序.cpp
//  04
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

//将一个记录插入到已经排好序的有序表中，从而得到一个新的 、记录数增1的有序表
#include <iostream>
using namespace std;

void insertSort(int a[],int size)
{
    for(int i=1;i<size;i++)
        for(int j=i;(j>0)&&(a[j]<a[j-1]);j--)
        {
            int temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
}

int main()
{
    int a[]={12,36,24,85,47,30,53,91};
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    insertSort(a,8);
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    return 0;
}
