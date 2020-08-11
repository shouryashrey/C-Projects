//
//  countSort.cpp
//  Project06AUG
//
//  Created by Shrey Shourya on 10/08/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>
using namespace std;

int largest(int a[],int n)
{
    int max=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}

void countSort(int a[],int n)
{
    int max = largest(a,n),i,j=0;
    int count[max+1];
    
    for(i=0;i<max+1;i++)
        count[i]=0;
    
    for(i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    
    for(i=0;i<max+1;i++)
    {
        if(count[i]!=0)
        {
            a[j]=i;
            count[i]--;
            j++;
        }
    }
}
