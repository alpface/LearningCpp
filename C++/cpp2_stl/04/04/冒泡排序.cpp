//
//  冒泡排序.cpp
//  04
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

//在冒泡排序的过程中，关键字较小的记录好比水中的气泡逐趟向上漂浮，而关键字较大的记录好比石块往下沉，每一趟有一块“最大”的石头沉到水底。
#include <iostream>
using namespace std;

void busort(int a[],int size)
{
    for(int i=0;i<size-1;i++)
        for(int j=size-1;j>i;j--)
            if(a[j]<a[j-1])
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
    
    busort(a,8);
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    return 0;
}

