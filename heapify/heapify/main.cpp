//
//  main.cpp
//  heapify
//
//  Created by Shrey Shourya on 18/08/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>
using namespace std;

void insert(int a[],int n)
{
    int i=n,temp;
    temp=a[i];
    
    while(i>0 && temp>a[i/2])
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}

int deletef(int a[],int n)
{
    int i,j,x,temp,val;
    val=a[0];
    x=a[n];
    a[0]=a[n];
    a[n]=val;
    i=0;
    j=2*i+1;
    
    while(j<n-1)
    {
        if(a[j+1]>a[j])
            j=j+1;
        
        if (a[i]<a[j]) {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
    }
    return val;
}


int main()
{
    int a[] = {10,20,30,25,5,40,35};
    int n=7,i;
    for(i=0;i<n;i++)
        insert(a, i);
    
    for(i=n-1;i>=0;i--)
        deletef(a, i);
        
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    
    return 0;
}
