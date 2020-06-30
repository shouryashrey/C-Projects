//
//  main.cpp
//  sorting and stacks
//
//  Created by Shrey Shourya on 23/05/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>

using namespace std;

#define max 100

int a[max],b[max];
int top1=-1,top2=-1;


void push(int a[],int &top,int x)
{
    if(top==max-1)
        return;
    a[++top]=x;
}


void pop(int top)
{
    if(top==-1)
        return;
    else
        top--;
}

int Top(int a[],int top)
{
    if(top>=0)
        return a[top];
    else
        return -1;
}

void display(int a[],int top)
{
    int i;
    if(top>=0) {
    for (i=0; i<=top; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    }
    else
        return;
}

int mod(int a,int b)
{
    if(a-b<0)
        return b-a;
    else
        return a-b;
}

void func()
{
    int a=Top(&a, top1);
    int b=Top(&b, top2);
    
    if(b==-1 || b<a)
    {
        push(&b, top2, a);
        pop(top1);
    }
    else if (mod(a, b)==1)
    {
        
    }
}

int main()
{
    int n,i,ele;
    
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        push(a,top1,ele);
    }
    display(a, top1);
    return 0;
}
