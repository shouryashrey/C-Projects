//
//  radixSort.cpp
//  Project06AUG
//
//  Created by Shrey Shourya on 10/08/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>
using namespace std;

int partition(int a[],int low,int high)
{
    int pivot = a[high];
    int i=low-1;
    
    for(int j=low;j<high;j++)
    {
        if (a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int a[],int low,int high)
{
    if (low<high)
    {
        int pi = partition(a,low,high);
        
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}
