#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
};

node *head;

int largest()
{
    node *temp=head;
    int max=temp->data;
    while(temp!=NULL)
    {
        if(temp->data>max)
            max=temp->data;
        temp=temp->next;
    }
    return max;
}

void count_sort()
{
    int max=largest();
    int a[max+1];
    for(int i=0;i<max+1;i++)
        a[i]=0;
    node *temp=head;
    while(temp!=NULL)
    {
        a[temp->data]+=1;
        temp=temp->next;
    }
    cout<<endl<<endl;
    for(int j=0;j<max+1;j++)
    {
        if(a[j]>0)
        {
            for(int i=0;i<a[j];i++)
                cout<<j<<endl;
        }
    }
}

void insert(int x,node **head)
{
    node *temp=new node();
    temp->data=x;
    temp->next=NULL;
    if(*head==NULL)
    {
        temp->next=*head;
        *head=temp;
    }
    else
    {
    node *temp1=*head;
    while(temp1->next!=NULL)
        temp1=temp1->next;
    temp1->next=temp;
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
        cout<<"Enter your choice\n";
        cout<<"1.Element\n2.Count Sort\n3.Display\n";
        cin>>choice;
        switch(choice)
        {
            case 1:{
                cout<<"Enter Element = ";
                cin>>ele;
                insert(ele,&head);
                break;
            }
            case 2:{
                count_sort();
                break;
            }
            case 3:{
                display();
                break;
            }
            default:{
                cout<<"\nWrong Choice\n";
            }
        }
    }
}
