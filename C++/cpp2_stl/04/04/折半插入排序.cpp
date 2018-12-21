//
//  折半插入排序.cpp
//  04
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

#include <iostream>
using namespace std;

void BInsertSort(int a[],int size)
{
    for(int i=1;i<size;i++)
    {
        int temp=a[i];               //暂存a[i]
        int low=0;
        int high=i-1;
        while(low<=high)
        {
            int middle=(low+high)/2;
            if(temp<=a[middle])
                high=middle-1;
            else
                low=middle+1;
        }
        
        for(int j=i-1;j>=high+1;--j)   //记录后移
            a[j+1]=a[j];
        a[high+1]=temp;                //插入，注意没有补齐的地方要注意，不然是野指针指向莫名的值。
    }
}

int main()
{
    int a[]={12,36,24,53,53,30,53,91};
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    BInsertSort(a,8);
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    return 0;
}

