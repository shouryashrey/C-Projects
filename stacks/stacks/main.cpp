#include "iostream"
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

node *head,*head2,*head3;

void push(int x,node **head)
{
    node *temp=new node(x);
    temp->next=*head;
    *head=temp;
}

void pop()
{
    node *temp=head;
    head=temp->next;
    delete(temp);
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

void reverse()
{
    node *prev,*curr,*next;
    prev=next=NULL;
    curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}

int main()
{
    head=NULL;
    push(4,&head);
    push(34,&head);
    push(56,&head);
    push(12,&head);
    
    display();
    
    pop();
    pop();
    
    push(524,&head);
    
    display();
    cout<<"\nReverse function\n";
    reverse();
    cout<<"\nLast\n";
    display();
    
    return 0;
}
