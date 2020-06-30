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
int n=0,sum=0;

void insert(node **head,int x)
{
    node *temp=new node(x);
    if(*head==NULL)
    {
        temp->next=*head;
        *head=temp;
    }
    else
    {
        node *ptr=*head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=temp;
    }
}

void display(node **head)
{
    node *temp=*head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int count()
{
    node *temp=ll1;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void insertbetween(node **ptr1,node **ptr2)
{
    node *prev=*ptr1;
    node *curr=*ptr2;
    *ptr2=curr->next;
    
    curr->next=prev->next;
    prev->next=curr;
    
}

void createll()
{
    node *temp1,*temp2;
    temp1=temp2=ll1;
    temp1=temp1->next;
    temp1=temp1->next;
    while(temp1!=NULL)
    {
        insert(&ll2,temp1->data+temp2->data);
        for(int i=0;i<2;i++)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    
    temp1=temp2=ll1;
    for(int i=0;i<3;i++)
        temp1=temp1->next;
    temp2=temp2->next;
    
    while(temp1!=NULL)
    {
        insert(&ll3,temp1->data+temp2->data);
        temp1=temp1->next;
        if(temp1!=NULL)
            temp1=temp1->next;
        temp2=temp2->next;
        temp2=temp2->next;
    }
}

void updatedll()
{
    node *temp1,*temp2,*temp3;
    temp1=ll1;
    temp2=ll2;
    temp3=ll3;
    
    while(temp1!=NULL && temp2!=NULL)
    {
        insertbetween(&temp1,&temp2);
        temp1=temp1->next;
        temp1=temp1->next;
//        temp2=temp2->next;
    }
    temp1=temp1->next;
    while(temp1!=NULL && temp3!=NULL)
    {
        insertbetween(&temp1,&temp3);
        temp1=temp1->next;
        temp1=temp1->next;
//        temp3=temp3->next;
    }
    temp1=ll1;
    temp2=ll1;
    temp3=ll1;
    while(temp1->next!=NULL)
        temp1=temp1->next;
    sum=temp1->data+temp2->data;
    for(int i=0;i<2*n-2;i++)
        temp3=temp3->next;
    node *newNode=new node(sum);
    insertbetween(&temp3,&newNode);
}


int main() {
    ll1=ll2=ll3=NULL;
    int ele;
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        cin>>ele;
        insert(&ll1,ele);
    }
    createll();
    display(&ll2);
    display(&ll3);
    updatedll();
    cout<<sum<<endl;
    display(&ll1);
    cout<<count()<<endl;
    return 0;
}
