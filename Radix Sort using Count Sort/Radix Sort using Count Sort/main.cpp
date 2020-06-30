//
//  main.cpp
//  Radix Sort using Count Sort
//
//  Created by Shrey Shourya on 21/05/20.
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

node *head;

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

void countsort(int n,int pow)
{
    node *temp=head;
    int outputArray[n],i;
    int count[10]={0};
    while(temp->data!=-1)
    {
        count[ (temp->data/pow)%10 ]++;
        temp=temp->next;
    }
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    temp=head;
    while(temp->data!=-1)
    {
        outputArray[count[ (temp->data/pow)%10 ] - 1] = temp->data;
        count[ (temp->data/pow)%10 ]--;
        temp=temp->next;
    }
    temp=head;i=n-1;
    while (temp->data!=-1) {
        temp->data=outputArray[i--];
        temp=temp->next;
    }
}

void radixsort(int n)
{
    node *temp=head;
    int max=temp->data;
    while(temp->data!=-1)
        {
            if(temp->data>max)
                max=temp->data;
            temp=temp->next;
        }
    
    for(int pow=1;max/pow>1;pow*=10)
    {
        countsort(n,pow);
        node *temp=head;
            while(temp->data!=-1)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
    }
}


//void display()
//{
//    node *temp=head;
//    while(temp!=NULL)
//    {
//        cout<<temp->data<<" ";
//        temp=temp->next;
//    }
//    cout<<endl;
//}



int main()
{
    head=NULL;
    int i,n,ele;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        insert(&head, ele);
    }
    insert(&head, -1);
    radixsort(n);
    return 0;
}
