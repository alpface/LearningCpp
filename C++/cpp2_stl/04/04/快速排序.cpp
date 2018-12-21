//
//  快速排序.cpp
//  04
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

//快排:分难合易
//基本思想：先用partition()函数找到中位数，再分别对小于和大于中位数的那部分进行快速排序  

#include <iostream>
using namespace std;

int partition(int a[],int low,int high)
{
    int key=a[low]; //用子表的第一个记录作杻轴记录
    while(low < high)   //从表的两端交替地向中间扫描
    {
        while(low < high && a[high] >= key)
            --high;
        {                  //将比杻轴记录小的记录交换到低端
            int temp=a[low];
            a[low]=a[high];
            a[high]=temp;
        }
        
        while(low < high && a[low] <= key)
            ++low;
        {                 //将比杻轴记录大的记录交换到低端
            int temp=a[low];
            a[low]=a[high];
            a[high]=temp;
        }
    }
    return low;   //返回杻轴所在的位置
}

void qsort(int a[],int b,int e)
{
    if(b < e)
    {
        int m=partition(a,b,e);
        qsort(a,b,m-1);
        qsort(a,m+1,e);
    }
}

int main()
{
    int a[]={2,3,7,8,3,5};
    qsort(a,0,5);
    for(int i=0;i<6;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    return 0;
}
