#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next,*prev;
    node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

node *head;

void insert_beg(int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=head;
        head=temp;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
}

void insert_end(int x)
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
        temp->prev=ptr;
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

int main()
{
    head=NULL;
    int choice,ele;
    while(1)
    {
        cout<<"Enter your choice\n1.Insert Begin\n2.Insert End\n3.Display\n";
        cin>>choice;
        switch (choice) {
            case 1:{
                cout<<"Enter Element = ";
                cin>>ele;
                insert_beg(ele);
                break;
            }
                
            case 2:{
                cout<<"Enter Element = ";
                cin>>ele;
                insert_end(ele);
                break;
            }
                
            case 3:{
                display();
                break;
            }
        }
    }
}
