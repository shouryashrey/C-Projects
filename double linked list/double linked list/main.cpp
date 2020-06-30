#include "iostream"
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
};

node *head;

void insert_beg()
{
    node *temp=new node();
    
}
void insert();
void insert_end();
void delet();
void display();

int main()
{
    head=NULL;
    int choice,element,position;
    while(1)
    {
        cout<<"1.Insert at begining\n"<<"2.Insert at position\n"<<"3.Insert at end\n";
        cout<<"4.Delete Element at position\n"<<"5.Display all Elements\n";
        cout<<"\nEnter your choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter element";
                cin>>element;
                insert_beg();
                break;
            }
            
            case 2:
            {
                cout<<"Enter element and position";
                cin>>element>>position;
                insert();
                break;
            }
            
            case 3:
            {
                cout<<"Enter element";
                cin>>element;
                insert_end();
                break;
            }
                
            case 4:
            {
                cout<<"Enter element and position";
                cin>>element>>position;
                delet();
                break;
            }
                
            case 5:
            {
                display();
                break;
            }
                
            default:{
                cout<<"You entered wrong choice";
            }
        }
    }
}
