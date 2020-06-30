#include<iostream>
using namespace std;

void swapm(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void bubblesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
                swapm(&a[j],&a[j+1]);
        }
    }
}

int main()
{
    int a[]{74,73,61,16,68,96};
    int n=sizeof(a)/sizeof(a[0]);
    
    bubblesort(a, n);
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
