//
//  main.cpp
//  May 17
//
//  Created by Shrey Shourya on 17/05/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//



#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

node *ll1,*ll2,*ll3;

void insert(node **head,int x)
{
    node *temp=new node(x);
    if(*head==NULL)
    {
        temp->next=*head;
        *head=temp;
    }
}

void display(node **head)
{
    node *temp=*head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}

int main() {
    ll1=ll2=ll3=NULL;
    int n,ele;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        insert(&ll1,ele);
    }
    display(&ll1);
    
    return 0;
}
