#include<iostream>
using namespace std;

class node
{
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

void insert(int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        node *ptr=head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=temp;
    }
}

void display()
{
    node *temp=head;
    cout<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

node *reverse_k(node *head,int k)
{
    node *prev,*curr,*next;
    curr=head;
    prev=next=NULL;
    int p=0;
    while(curr!=NULL && p<k)
    {
        p++;
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    if(next!=NULL)
        head->next=reverse_k(next,k);
    
    return prev;
}

int main()
{
    head=NULL;
    insert(12);
    insert(22);
    insert(32);
    insert(42);
    insert(52);
    insert(62);
    insert(72);
    insert(82);
    display();
    //cout<<(head->next)->data<<endl;
    head=reverse_k(head,4);
    display();
    return 0;
}
