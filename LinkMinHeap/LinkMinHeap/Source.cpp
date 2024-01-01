#include "LinkMinHeap.h"
#include<iostream>
using namespace std;

int main()
{
    // Example usage
    LinkMinHeap<int> minHeap;

    minHeap.insert(5);
    minHeap.insert(10);
    minHeap.insert(3);
    minHeap.insert(7);
    minHeap.insert(1);

    cout << "Min Heap after insertions: ";
    minHeap.inOrderTraversal();

    cout << "Removing the minimum element from Min Heap..." << endl;
    minHeap.removeMin();

    cout << "Min Heap after removal: ";
    minHeap.inOrderTraversal();

    return 0;
}
