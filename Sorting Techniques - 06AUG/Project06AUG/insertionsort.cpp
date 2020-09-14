//
//  insertionsort.cpp
//  Project06AUG
//
//  Created by Shrey Shourya on 08/08/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>
using namespace std;

void insertionsort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int temp = a[i];
        int j=i-1;
        while(a[j]>temp && j>-1) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
