//
//  main.cpp
//  JUL28
//
//  Created by Shrey Shourya on 28/07/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>
using namespace std;

int binarySearch(int a[],int first,int last,int ele)
{
    if(first==last)
    {
        if(ele==a[first])
            return first;
        else
            return -1;
    }
    else
    {
        int mid=(first+last)/2;
        if(a[mid]==ele)
            return mid;
        else
        {
            if (ele<a[mid])
                binarySearch(a, first, mid-1, ele);
            else
                binarySearch(a, mid+1, last, ele);
        }
    }
}

int main()
{
    int a[] = {12,23,34,45,56,67,78,89,90};
    int n = sizeof(a)/sizeof(a[0]);
    int ele = 23;
    int ans = binarySearch(a, 0, n-1, ele);
    if(ans < 0)
        cout<<"Not found";
    else
        cout<<"Found";
    return 0;
}
