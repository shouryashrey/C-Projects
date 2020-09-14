//
//  main.cpp
//  Aug 25
//
//  Created by Shrey Shourya on 25/08/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "bubblesort.cpp"
using namespace std;

void printJobScheduling(char j[],int d[],int p[], int n)
{
    bubblesort(p,j,d,n);
    
    int result[n];
    bool slot[n];
    
    for (int i=0; i<n; i++)
        slot[i] = false;
    
    for (int i=0; i<n; i++)
    {
        for (int j=min(n, d[i])-1; j>=0; j--)
        {
            if (slot[j]==false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    
    for (int i=0; i<n; i++)
        if (slot[i])
            cout << j[result[i]] << " ";
    
}


int main()
{
    char j[] = {'a','b','c','d','e','f'};
    int d[] = {5,3,3,2,4,2};
    int p[] = {24,18,22,30,12,10};
//
//    char j[] = {'a','b','c','d','e'};
//    int d[] = {2,1,2,1,3};
//    int p[] = {100,19,27,25,15};
//
    int n = sizeof(p)/sizeof(p[0]);
    printJobScheduling(j,d,p,n);
    cout<<endl;
    return 0;
    
}
