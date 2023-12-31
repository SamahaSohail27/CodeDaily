#include <iostream>
using namespace std;

int* CountingSort(int* arr, int n, int k) {
    int* temp = new int[k + 1];
    for (int i = 0; i <= k; i++) {
        temp[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        temp[arr[i]]++;
    }

    int out = 0;
    for(int i=0;i<k;i++)
    {
        while(temp[i]>0)
        {
            arr[out++]=i;
            temp[i]--;
        }
    }
    return arr;
}

int main() {
    int arr[7] = {2, 1, 2, 3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 4; // Assuming the range of values is 0 to 4

    int* arr2 = CountingSort(arr, n, k);

    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";

    

    return 0;
}
