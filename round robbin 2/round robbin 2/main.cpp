//
//  main.cpp
//  round robbin scheduling
//
//  Created by Shrey Shourya on 26/05/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include "iostream"
using namespace std;
struct node
{
    int p,b;
    struct node *next;
};

struct node *insertBegin(struct node *last, int data,int data1)
{
    
    if (last != NULL)
        return last;
    
    
    struct node *temp =
    (struct node*)malloc(sizeof(struct node));
    
    
    temp -> p = data;
    temp->b=data1;
    last = temp;
    
    
    last -> next = last;
    
    return last;
}
int traverse(struct node *last)
{
    struct node *p;
    
    
    if (last == NULL)
    {
        
        return 0;
    }
    
    p = last -> next;
    int f;
    
    do
    {
        if(p->b==0)
            f=0;
        else
        {
            f=1;
            break;
        }
        p = p -> next;
        
    }
    while(p != last->next);
    return f;
    
}

struct node *insertLast(struct node *last, int data,int data1)
{
    if (last == NULL)
        return insertBegin(last, data,data1);
    
    struct node *temp =
    (struct node *)malloc(sizeof(struct node));
    
    temp -> p = data;
    temp->b=data1;
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;
    
    return last;
}


int main()
{
    int n;
    struct node *last=NULL;
    struct node *curr=NULL;
    cin>>n;
    int P_id[n],arrivalTime[n],burstTime[n],p[n],t=0,i,sum=0,k;
    for (i=0; i<n; i++) {
        p[i]=0;
    }
    for(i=0;i<n;i++)
    {
        cin>>P_id[i]>>arrivalTime[i]>>burstTime[i];
    }
    for(i=0;i<n;i++)
        sum=sum+burstTime[i];
    int T[sum];
    int f=0,ti=0,c=1;
    while(1)
    {
        
        for(i=0;i<n;i++)
        {
            if(arrivalTime[i]==ti)
            {
                if(f==0)
                {
                    last=insertBegin(last,P_id[i],burstTime[i]);
                    curr=last;
                    c=0;
                    f=1;
                }
                else
                    last=insertLast(last,P_id[i],burstTime[i]);
                
            }
        }
        if(f==0)
        {
            ti++;
            continue;
        }

        k=traverse(last);
        
        if(k==0)
        {
            ti++;
            continue;
        }
        if(c==1)
            curr=curr->next;
        if(c==0)
        {
            c=1;
        }
        
        ti++;
        while(curr->b==0)
        {
            if(t==sum)
                break;
            curr=curr->next;
            //fl++;
        }
    
        curr->b=(curr->b)-1;
        T[t]=curr->p;
        t++;
        if(t==sum)
            break;
        
    }
    for(i=0;i<sum;i++)
        cout<<T[i]<<" ";
}
