//
//  main.cpp
//  Radix Sort Decreasing order
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
node *basket[10];

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

void display()
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int largest()
{
    int max;
    node *temp=head;
    max=temp->data;
    while(temp!=NULL)
    {
        if(temp->data>max)
            max=temp->data;
        temp=temp->next;
    }
    return max;
}


//Radix Sort Function

void radixsort()
{
    int max=largest(),i=1,j;
    node *temp;
    while (max>0) {
        temp=head;
        while(temp!=NULL) {
            int check=(temp->data/i)%10;
            insert(&basket[check], temp->data);
            temp=temp->next;
        }
        head=NULL;
        
        for (j=9; j>=0; j--) {
            temp=basket[j];
            while(temp!=NULL)  {
                insert(&head, temp->data);
                temp=temp->next;
            }
        }
        i*=10;
        max/=10;
        for (int m=0; m<10; m++) {
            basket[m]=NULL;
        }
        display();
    }
}
//134 229 336 485 987 651
int main()
{
    head=NULL;
    int i,n,ele;
    for (i=0; i<10; i++)
    {
        basket[i]=NULL;
    }
    
    //Accepting Size of Array
    cin>>n;
    for (i=0; i<n; i++) {
        cin>>ele;
        insert(&head, ele);
    }
    
    radixsort();
    
    return 0;
}
