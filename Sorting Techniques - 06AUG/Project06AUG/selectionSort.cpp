//
//  selectionSort.cpp
//  Project06AUG
//
//  Created by Shrey Shourya on 09/08/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include<iostream>
using namespace std;

void selectionSort(int a[],int n)
{
    for (int i=0; i<n-1; i++) {
        int min_index=i;
        for (int j=i+1; j<n; j++) {
            if (a[j]<a[min_index]) {
                min_index=j;
            }
        }
        swap(a[min_index],a[i]);
    }
}

