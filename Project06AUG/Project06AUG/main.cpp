//
//  main.cpp
//  Project06AUG
//
//  Created by Shrey Shourya on 06/08/20.
//  Copyright © 2020 Shrey Shourya. All rights reserved.
//

//ANSWER
//29 355 365 511 571 615 814 900 913 980

#include <iostream>
#include "bubblesort.cpp"
#include "insertionsort.cpp"
#include "selectionSort.cpp"
#include "mergeSort.cpp"
#include "shellSort.cpp"
#include "countSort.cpp"
#include "quickSort.cpp"

using namespace std;

int main()
{
    int a[] = {571, 511, 913, 29, 615, 365, 814, 980, 900, 355};
    int n=10;
    
//    bubblesort(a,n);
//    insertionsort(a,n);
//    selectionSort(a,n);
//    mergeSort(a, 0, n-1);
//    shellSort(a,n);
//    countSort(a, n);
    quickSort(a,0,n-1);
    
    for (int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
