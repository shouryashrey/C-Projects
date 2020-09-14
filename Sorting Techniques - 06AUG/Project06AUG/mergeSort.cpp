//
//  mergeSort.cpp
//  Project06AUG
//
//  Created by Shrey Shourya on 09/08/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include<iostream>
using namespace std;

void merge(int a[],int first,int mid,int last)
{
    int n1 = mid-first+1;
    int n2 = last-mid;
    
    int L[n1],R[n2],i,j;
    
    for(i=0;i<n1;i++)
        L[i]=a[first+i];
    for(i=0;i<n2;i++)
        R[i]=a[mid+1+i];
    
    i=j=0;
    int k=first;
    
    while (i<n1 && j<n2) {
        if(L[i]<R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int first,int last)
{
    if(first<last)
    {
        int mid = (first+last)/2;
        
        mergeSort(a,first,mid);
        mergeSort(a,mid+1,last);
        
        merge(a,first,mid,last);
    }
}
