//
//  main.cpp
//  binary search in 3d array
//
//  Created by Shrey Shourya on 26/05/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[100][100][100];

void binarySearch(int x,int y,int z,int n)
{
    int a0,b0,a1,b1,a2,b2;
    int mid_x,mid_y,mid_z;
    int flag=0;
    int n1=0,n2=0,n3=0;
    int m1=0,m2=0;
    a0=0;
    b0=x-1;
    mid_x=0;
    
    while (a0<=b0)
    {
        mid_x=(a0+b0)/2;
        int x1=arr[mid_x][0][0];
        int x2=arr[mid_x][y-1][z-1];
        n1++;
        
        if(n>=x1 && n<=x2)
        {
            cout<<x1<<" "<<x2<<endl;
            m1=n1;
            
            a1=0;
            b1=y-1;
            mid_y=0;
            
            while(a1<=b1)
            {
                mid_y=(a1+b1)/2;
                
                int y1=arr[mid_x][mid_y][0];
                int y2=arr[mid_x][mid_y][z-1];
                
                n2++;
                
                if(n>=y1 && n<=y2)
                {
                    cout<<y1<<" "<<y2<<endl;
                    m2=n2;
                    
                    a2=0;
                    b2=z-1;
                    mid_z=0;
                    
                    while (a2<=b2)
                    {
                        mid_z=(a2+b2)/2;
                        n3++;
                        
                        if (arr[mid_x][mid_y][mid_z]==n)
                        {
                            cout<<mid_x<<" "<<mid_y<<" "<<mid_z<<endl;
                            cout<<n1+n2+n3<<endl;
                            flag++;
                            return;
                        }
                        
                        if (arr[mid_x][mid_y][mid_z]<n) {
                            a2=mid_z+1;
                        }
                        else
                            b2=mid_z-1;
                    }
                }
                
                if (n>y1) {
                    a1=mid_y+1;
                }
                else
                    b2=mid_y-1;
            }
        }
        
        if(n>x1)
            a0=mid_x+1;
        else
            b0=mid_x-1;
            
    }
    if (m1!=0) {
        n1=m1;
    }
    if(m2!=0)
    {
        n2=m2;
    }
    if(flag!=1)
    {
        cout<<0<<endl;
        cout<<n1+n2+n3<<endl;
    }
    
}

int main()
{
    int i,j,k,X,Y,Z,N;
    cin>>X>>Y>>Z>>N;
//    int array[X][Y][Z];
    
    for (i=0; i<X; i++) {
        for (j=0; j<Y; j++) {
            for (k=0; k<Z; k++) {
                cin>>arr[i][j][k];
            }
        }
    }
    
    binarySearch(X, Y, Z, N);
   
    return 0;
}
