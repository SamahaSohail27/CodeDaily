// C++ program to sort an array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to sort array using bucket sort
void bucketSort(float inputData[], int dataSize)
{
    // Step 1: Create dataSize empty buckets
    vector<float> buckets[dataSize];

    // Step 2: Put array elements in different buckets
    for (int i = 0; i < dataSize; i++) {

        // Index in bucket
        int bucketIndex = dataSize * inputData[i];
        buckets[bucketIndex].push_back(inputData[i]);
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < dataSize; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Step 4: Concatenate all buckets into inputData
    int currentIndex = 0;
    for (int i = 0; i < dataSize; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            inputData[currentIndex++] = buckets[i][j];
}

// Driver program to test the bucketSort function
int main()
{
    float inputData[]
        = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int dataSize = sizeof(inputData) / sizeof(inputData[0]);
    bucketSort(inputData, dataSize);

    cout << "Sorted array is \n";
    for (int i = 0; i < dataSize; i++)
        cout << inputData[i] << " ";
    return 0;
}
