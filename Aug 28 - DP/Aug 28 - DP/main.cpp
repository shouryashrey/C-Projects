//
//  main.cpp
//  Aug 28 - DP
//
//  Created by Shrey Shourya on 28/08/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>
using namespace std;

//int stairs(int n)
//{
//    if(n==1) return 1;
//    if(n==2) return 2;
//    return stairs(n-1)+stairs(n-2);
//}

unsigned long stairs(int n)
{
    unsigned long a[n+1];
    a[1]=1;
    a[2]=2;
    a[3]=4;
    for(int i=4;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3];
//        cout<<a[i]<<endl;
    }
    return a[n];
}

int main()
{
    unsigned long result = stairs(200);
    cout<<result<<endl;
//    cout<<result/4294967295 <<endl;
    return 0;
}
