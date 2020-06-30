#include<iostream>
using namespace std;

int main()
{
    int n,i;
    while(1){
        int sum=0;
    cout<<"Enter";
    cin>>n;
    
    for(i=1;i<n;i++)
    {
        if(i%3==0 || i%5==0)
        {
            sum+=i;
        }
    }
    cout<<sum;
    }
    return 0;
}

