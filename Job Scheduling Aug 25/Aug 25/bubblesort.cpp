//
//  printFunction.cpp
//  Project06AUG
//
//  Created by Shrey Shourya on 07/08/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
    int z=*a;
    *a=*b;
    *b=z;
}

void bubblesort(int a[],char b[],int c[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if (a[j]<a[j+1]) {
                swap(a[j],a[j+1]);
                swap(b[j],b[j+1]);
                swap(c[j],c[j+1]);
            }
        }
    }
}
