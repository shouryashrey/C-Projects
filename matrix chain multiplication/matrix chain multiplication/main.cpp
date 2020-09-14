//
//  main.cpp
//  matrix chain multiplication
//
//  Created by Shrey Shourya on 08/09/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

#include <iostream>
using namespace std;


int MCM(int arr[], int i, int j)
{
    if(i>j)
        return -1;
    
    int min = INT_MAX;
    int count = 0;
    
    if(i==j)
        return 0;
    else
    {
        for(int k=i;k<j;k++)
        {
            count = MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
            
            if (min>count) {
                min = count;
            }
        }
    }
    return min;
    
}

int main()
{
    int arr[] = {10,100,20,5,80};
    cout<<"Total calculations = "<<MCM(arr,1,4)<<endl;
    return 0;
}
