#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *left,*right;
    node(int x)
    {
        data=x;
        left=right=NULL;
    }
};

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    
}
