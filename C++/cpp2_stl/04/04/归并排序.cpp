//
//  归并排序.cpp
//  04
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

//归并排序：分易合难 
#include <iostream>
using namespace std;

void display(int a[],int size)
{
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void mmerge(int *a,int low,int middle ,int high )
{
    int fronArray[100],postArray[100];
    int front=middle-low+1;
    int post=high-middle;
    for(int i=0;i<front;i++)
        fronArray[i]=a[low+i];
    
    for(int j=0;j<post;j++)
        postArray[j]=a[middle+j+1];
    
    fronArray[front]=9999; //哨兵
    postArray[post]=9999;
    
    int i=0,j=0;
    for(int k=low;k<=high;k++)
    {
        if(fronArray[i]<postArray[j])
            a[k]=fronArray[i++];
        else
            a[k]=postArray[j++];
    }
}

void merge_sort(int *a,int low,int high)
{
    if(low<high)
    {
        int middle=(low+high)/2;
        merge_sort(a,low,middle);
        merge_sort(a,middle+1,high);
        mmerge(a,low,middle,high);
    }
}

int main()
{
    int a[]={9,3,5,7,6,8,10,22,21,34};
    display(a,10);
    merge_sort(a,0,9);
    display(a,10);
    
    return 0;
}

