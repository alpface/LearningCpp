//
//  堆排序.cpp
//  04
//
//  Created by xiaoyuan on 2018/12/21.
//  Copyright © 2018 xiaoyuan. All rights reserved.
//

/*
 堆排序
 (1)用大根堆排序的基本思想
 ① 先将初始文件R[1..n]建成一个大根堆，此堆为初始的无序区
 ② 再将关键字最大的记录R[1](即堆顶)和无序区的最后一个记录R[n]交换，
 由此得到新的无序区R[1..n-1]和有序区R[n]，且满足R[1..n-1].keys≤R[n].key
 ③ 由于交换后新的根R[1]可能违反堆性质，故应将当前无序区R[1..n-1]调整为堆。
 然后再次将R[1..n-1]中关键字最大的记录R[1]和该区间的最后一个记录R[n-1]交换，
 由此得到新的无序区R[1..n-2]和有序区R[n-1..n]，且仍满足关系R[1..n- 2].keys≤R[n-1..n].keys，
 同样要将R[1..n-2]调整为堆。
 ……
 直到无序区只有一个元素为止。
 (2)大根堆排序算法的基本操作：
 ① 初始化操作：将R[1..n]构造为初始堆；
 ② 每一趟排序的基本操作：将当前无序区的堆顶记录R[1]和该区间的最后一个记录交换，然后将新的无序区调整为堆(亦称重建堆)。
 注意：
 ①只需做n-1趟排序，选出较大的n-1个关键字即可以使得文件递增有序。
 ②用小根堆排序与利用大根堆类似，只不过其排序结果是递减有序的。
 堆排序和直接选择排序相反：在任何时刻，堆排序中无序区总是在有序区之前，
 且有序区是在原向量的尾部由后往前逐步扩大至整个向量为止。
 */

#include <iostream>

using namespace std;

//生成大根堆
void HeapAdjust(int SortData[],int StartIndex, int Length)
{
    while(2*StartIndex+1 < Length)
    {
        int MaxChildrenIndex = 2*StartIndex+1 ;
        if(2*StartIndex+2 < Length )
        {
            //比较左子树和右子树，记录最大值的Index
            if(SortData[2*StartIndex+1]<SortData[2*StartIndex+2])
            {
                MaxChildrenIndex = 2*StartIndex+2;
            }
        }
        if(SortData[StartIndex] < SortData[MaxChildrenIndex])
        {
            //交换i与MinChildrenIndex的数据
            int tmpData =SortData[StartIndex];
            SortData[StartIndex] =SortData[MaxChildrenIndex];
            SortData[MaxChildrenIndex] =tmpData;
            //堆被破坏，需要重新调整
            StartIndex = MaxChildrenIndex ;
        }
        else
        {
            //比较左右孩子均大则堆未破坏，不再需要调整
            break;
        }
    }
}

//堆排序
void HeapSortData(int SortData[], int Length)
{
    int i=0;
    
    //将Hr[0,Length-1]建成大根堆
    for (i=Length/2-1; i>=0; i--)
    {
        HeapAdjust(SortData, i, Length);
    }
    
    for (i=Length-1; i>0; i--)
    {
        //与最后一个记录交换
        int tmpData =SortData[0];
        SortData[0] =SortData[i];
        SortData[i] =tmpData;
        //将H.r[0..i]重新调整为大根堆
        HeapAdjust(SortData, 0, i);
    }
}

//TestCase
int main()
{
    int SortData[] ={12,36,24,85,47,30,53,91};
    
    HeapSortData(SortData, 8);
    
    for (int i=0; i<8; i++)
    {
        cout<<SortData[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}

