#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
};

node *head;

void insert_beg(int x)
{
    node *temp=new node();
    temp->data=x;
    temp->next=head;
    head=temp;
}

void insert(int x,int pos)
{
    node *temp=new node();
    temp->data=x;
    temp->next=NULL;
    node *temp1=head;
    for(int i=0;i<pos-2;i++)
        temp1=temp1->next;
    temp->next=temp1->next;
    temp1->next=temp;
}

void insert_end(int x)
{
    node *temp=new node();
    temp->data=x;
    temp->next=NULL;
    node *temp1=head;
    while(temp1->next!=NULL)
        temp1=temp1->next;
    temp1->next=temp;
}

void delet(int pos)
{
    node *temp=new node();
    temp=head;
    for(int i=0;i<pos-2;i++)
        temp=temp->next;
    node *temp1=temp->next;
    temp->next=temp1->next;
    delete(temp1);
}

void display()
{
    node *temp=new node();
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    head=NULL;
    int choice,ele,pos;
    while (1) {
        cout<<"\nEnter your choice\n";
        cout<<"1.Insert Begin\n2.Insert\n3.Insert End\n4.Delete\n5.Display\n";
        cin>>choice;
        
        switch (choice) {
            case 1:{
                cout<<"Enter element\n";
                cin>>ele;
                insert_beg(ele);
                break;
            }
                
            case 2:{
                cout<<"Enter element\n";
                cin>>ele;
                cout<<"Enter Position\n";
                cin>>pos;
                insert(ele,pos);
                break;
            }
             
            case 3:{
                cout<<"Enter element\n";
                cin>>ele;
                insert_end(ele);
                break;
            }
                
            case 4:{
                cout<<"Enter Position\n";
                cin>>pos;
                delet(pos);
                break;
            }
            case 5:{
                display();
                break;
            }
            default:{
                cout<<"You have entered a invalid option\n";
                break;
            }
        }
    }
    
    return 0;
}
