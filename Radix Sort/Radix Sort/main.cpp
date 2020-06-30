#include "iostream"
using namespace std;

class node{
public:
    int data;
    node *next;
};

node *head,*head1,*head2,*head3,*head4,*head5,*head6,*head7,*head8,*head9,*head0;

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
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
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

void radixsort()
{
    node *temp=new node();
    int max=largest(),i=1;
    while (max>0)
    {
        temp=head;
        while(temp!=NULL)
        {
            int check=(temp->data/i)%10;
            
            if(check==0)
                insert(temp->data, &head0);
            else if(check==1)
                insert(temp->data, &head1);
            else if(check==2)
                insert(temp->data, &head2);
            else if(check==3)
                insert(temp->data, &head3);
            else if(check==4)
                insert(temp->data, &head4);
            else if(check==5)
                insert(temp->data, &head5);
            else if(check==6)
                insert(temp->data, &head6);
            else if(check==7)
                insert(temp->data, &head7);
            else if(check==8)
                insert(temp->data, &head8);
            else if(check==9)
                insert(temp->data, &head9);
            
            temp=temp->next;
        }
        head=NULL;
        //temp=head;
        //temp->next=NULL;
        for(int j=0;j<10;j++)
        {
            if(j==0)
            {
                node *temp0=head0;
                while(temp0!=NULL)
                {
                    insert(temp0->data, &head);
                    temp0=temp0->next;
                }
            }
            else if(j==1)
            {
                node *temp1=head1;
                while(temp1!=NULL)
                {
                    insert(temp1->data, &head);
                    temp1=temp1->next;
                }
            }
            else if(j==2)
            {
                node *temp2=head2;
                while(temp2!=NULL)
                {
                    insert(temp2->data, &head);
                    temp2=temp2->next;
                }
            }
            else if(j==3)
            {
                node *temp3=head3;
                while(temp3!=NULL)
                {
                    insert(temp3->data, &head);
                    temp3=temp3->next;
                }
            }
            else if(j==4)
            {
                node *temp4=head4;
                while(temp4!=NULL)
                {
                    insert(temp4->data, &head);
                    temp4=temp4->next;
                }
            }
            else if(j==5)
            {
                node *temp5=head5;
                while(temp5!=NULL)
                {
                    insert(temp5->data, &head);
                    temp5=temp5->next;
                }
            }
            else if(j==6)
            {
                node *temp6=head6;
                while(temp6!=NULL)
                {
                    insert(temp6->data, &head);
                    temp6=temp6->next;
                }
            }
            else if(j==7)
            {
                node *temp7=head7;
                while(temp7!=NULL)
                {
                    insert(temp7->data, &head);
                    temp7=temp7->next;
                }
            }
            else if(j==8)
            {
                node *temp8=head8;
                while(temp8!=NULL)
                {
                    insert(temp8->data, &head);
                    temp8=temp8->next;
                }
            }
            else if(j==9)
            {
                node *temp9=head9;
                while(temp9!=NULL)
                {
                    insert(temp9->data, &head);
                    temp9=temp9->next;
                }
            }
        }
        
        max=max/10;
        i*=10;
        head0=head1=head2=head3=head4=head5=head6=head7=head8=head9=NULL;
    }
}

int main()
{
    head=head0=head1=head2=head3=head4=head5=head6=head7=head8=head9=NULL;
    int choice,ele;
    while(1)
    {
        cout<<"Enter your choice\n";
        cout<<"1.Element\n2.Radix Sort\n3.Display\n";
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
                radixsort();
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
    return 0;
}
