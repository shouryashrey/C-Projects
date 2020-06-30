#include <iostream>
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

class queue
{
public:
    node *f,*r;
    queue()
    {
        f=r=NULL;
    }
    
    void enqueue(int x)
    {
        node *temp=new node(x);
        
        if(r==NULL)
        {
            f=r=temp;
            return;
        }
        r->next=temp;
        r=temp;
    }
    
    void dequeue()
    {
        if(f==NULL)
            return;
        else
        {
            node *temp=f;
            f=f->next;
            if(f==NULL)
                r=NULL;
            delete(temp);
        }
    }
    
};

node *head;

void display()
{
    queue q;
    cout<<"Queue Front Element : "<<(q.f)->data<<endl;
    cout<<"Queue Rear Element : "<<(q.r)->data<<endl;;
}

int main()
{
    head=NULL;
    int choice,ele;
    queue q;
    while(1)
    {
        cout<<"\nEnter Choice\n";
        cout<<"1.Enqueue\n2.Dequeue3.Display\n";
        cin>>choice;
        
        switch (choice) {
            case 1:{
                cout<<"Enter Element = ";
                cin>>ele;
                q.enqueue(ele);
                break;
            }
                
            case 2:{
                q.dequeue();
                break;
            }
            case 3:{
                display();
                break;
            }
                
            default:
                break;
        }
    }
}
