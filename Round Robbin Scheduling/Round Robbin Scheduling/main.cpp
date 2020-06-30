//
//  main.cpp
//  Round Robbin Scheduling
//
//  Created by Shrey Shourya on 24/05/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>

using namespace std;

const int tq=1;

class node
{
public:
    int pid,at,bt;
    node *next;
    node(int a,int b,int c)
    {
        pid=a;at=b;bt=c;
        next=NULL;
    }
};

node *head;

void insert(int pid,int at,int bt)
{
    node *temp=new node(pid,at,bt);
    
    if (head==NULL) {
        temp->next=temp;
        head=temp;
    }
    else {
        node *ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
        ptr->next=temp;
        temp->next=head;
    }
}

void display()
{
    node *ptr=head;
    while(ptr->next!=head)
    {
        cout<<ptr->pid<<" "<<ptr->at<<" "<<ptr->bt<<endl;
        ptr=ptr->next;
    }
    cout<<ptr->pid<<" "<<ptr->at<<" "<<ptr->bt<<endl;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int a[][3],int n)
{
    for (int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(a[j][1]>a[j+1][1]) {
                swap(&a[j][0],&a[j+1][0]);
                swap(&a[j][1],&a[j+1][1]);
                swap(&a[j][2],&a[j+1][2]);
            }
        }
    }
}

void roundRobbin(int ll[][3],int n)
{
    int i=0;
    
    insert(ll[i][0], ll[i][1], ll[i][2]);
    node *temp=head;
    int t=temp->at;
    while(1)
    {
        bool done=true;
        temp=head;
        
        while(temp!=NULL)
        {
            if (temp->bt>0) {
                done=false;
                
                if (temp->bt>tq) {
                    t+=tq;
                    temp->bt-=tq;
                }
                else {
                    t+=temp->bt;
                    temp->bt=0;
                }
                cout<<temp->pid<<" ";
            }
            
            if (ll[i+1][1]==t && i<n) {
                i++;
                insert(ll[i][0], ll[i][1], ll[i][2]);
            }
            
            temp=temp->next;
            
            if (temp==head) {
                break;
            }
        }
        
        if (done==true) {
            break;
        }
    }
    cout<<endl;
}

/*
4
1 7 1
2 5 1
3 3 4
4 2 2
*/

int main()
{
    head=NULL;
    int n,i;
    cin>>n;
    int ll[n][3];
    for (i=0; i<n; i++) {
        cin>>ll[i][0]>>ll[i][1]>>ll[i][2];
    }
    sort(ll,n);
    roundRobbin(ll,n);
    return 0;
}
