#include <bits/stdc++.h> 
using namespace std; 
/* Sorts the array using pigeonhole algorithm */
void pigeonholeSort(int arr[], int n) 
{ 
    // Find minimum and maximum values in arr[] 
    int min = arr[0], max = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        if (arr[i] < min) 
            min = arr[i]; 
        if (arr[i] > max) 
            max = arr[i]; 
    } 
    int range = max - min + 1;  
    vector holes[range]; 
    
    for (int i = 0; i < n; i++) 
        holes[arr[i]-min].push_back(arr[i]); 
     
    int index = 0;  
    for (int i = 0; i < range; i++) 
    { 
       vector::iterator it; 
       for (it = holes[i].begin(); it != holes[i].end(); ++it) 
            arr[index++]  = *it; 
    } 
} 

int main() 
{ 
    int arr[] = {9,2,3,8,1,6,9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    pigeonholeSort(arr, n); 
    printf("Sorted order is : "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    return 0; 
}
