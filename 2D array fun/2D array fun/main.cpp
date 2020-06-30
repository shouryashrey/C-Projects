//
//  main.cpp
//  2D array fun
//
//  Created by Shrey Shourya on 22/05/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int n,i,j,k=0,tempi,tempj,temp;
    int flag=0,count=0;
    cin>>n;
    int a[n][n];
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cin>>a[i][j];
        }
    }
    
    while (k<n-1) {
        
        for (j=0; j<n; j++) {
            int min=a[k][j];
            tempi=k;tempj=j;
            flag=0;
            for (i=k; i<n; i++) {
                if(a[i][j]<min){
                    min=a[i][j];
                    tempi=i;tempj=j;
                    flag=1;
                }
            }
            if(flag==1){
                count++;
                temp=a[k][j];
                a[k][j]=a[tempi][tempj];
                a[tempi][tempj]=temp;
            }
        }
        
        for (i=0; i<n; i++) {
            int min=a[i][k];
            tempi=i;tempj=k;
            flag=0;
            for (j=k; j<n; j++) {
                if(a[i][j]<min){
                    min=a[i][j];
                    tempi=i;tempj=j;
                    flag=1;
                }
            }
            if(flag==1){
                count++;
                temp=a[i][k];
                a[i][k]=a[tempi][tempj];
                a[tempi][tempj]=temp;
            }
        }
        k++;
    }
    
    cout<<count<<endl;
    
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cout<<a[i][j]<<" ";
        }
    }
    cout<<endl;
    
    return 0;
}
