
#include "LinkMinHeap.h"
#include <iostream>
#include "Stack.h"
using namespace std;

// Constructor
template<typename T>
LinkMinHeap<T>::LinkMinHeap()
{
    root = nullptr;
    nodeCount = 0;
}

// Function to insert a new element into the Min Heap
template<typename T>
void LinkMinHeap<T>::insert(T val)
{
    // Stack to store the binary representation of the insertion path
    Stack<int> binary;
    // Stack to store the path of nodes traversed during insertion
    Stack<BTNode<T>*> path;
    // Create a new node with the given value
    BTNode<T>* node = new BTNode<T>(val);

    // If the heap is empty, set the new node as the root
    if (!root)
    {
        root = node;
        return;
    }

    BTNode<T>* ptr = root;
    BTNode<T>* child = ptr;
    path.push(ptr);

    // Convert the node count to binary to determine the path for insertion
    int n = nodeCount + 1;
    while (n > 1)
    {
        binary.push(n % 2);
        n = n / 2;
    }

    // Traverse the path based on binary representation and insert the node
    while (!binary.isEmpty())
    {
        int curr = binary.pop();
        if (curr == 1)
        {
            // Move to the right child if the bit is 1
            if (ptr->right)
            {
                ptr = ptr->right;
                path.push(ptr);
            }
            else
            {
                // If the right child is null, insert the new node
                ptr->right = node;
                child = ptr;
            }
        }
        else
        {
            // Move to the left child if the bit is 0
            if (ptr->left)
            {
                ptr = ptr->left;
                path.push(ptr);
            }
            else
            {
                // If the left child is null, insert the new node
                ptr->left = node;
                child = ptr;
            }
        }
    }

    // Perform the necessary swaps to maintain the min-heap property
    nodeCount++;
    T p;
    BTNode<T>* temp = nullptr;
    while (!path.isEmpty())
    {
        temp = path.pop();
        if (child->info < temp->info)
        {
            // Swap values if the child's value is less than the parent's value
            p = temp->info;
            temp->info = child->info;
            child->info = p;
        }
        else
            break;
        child = temp;
    }
}

// Function to remove the minimum element from the Min Heap
template<typename T>
void LinkMinHeap<T>::removeMin()
{
    if (!root)
        exit(0);  // Assuming you want to exit on an empty heap

    // Check if there's only one node in the heap
    if (!root->left && !root->right)
    {
        nodeCount--;
        delete root;
        root = nullptr;
        return;
    }

    // Find the node with the smallest value (leftmost node in the bottom level)
    BTNode<T>* minNode = findMinNode(root);
    if (!minNode)
        return;  // No minimum node found

    // Find the parent of the minimum node
    BTNode<T>* parent = findParent(root, minNode);

    // Replace the minimum node's value with the rightmost leaf's value
    minNode->info = deleteDeepest(root);

    // Perform necessary swaps to maintain the min-heap property
    heapifyAfterDeletion(parent, minNode);
}

// Function to find the node with the smallest value in the Min Heap
template<typename T>
BTNode<T>* LinkMinHeap<T>::findMinNode(BTNode<T>* node)
{
    if (!node)
        return nullptr;

    // Traverse to the leftmost node in the bottom level
    while (node->left)
        node = node->left;

    return node;
}

// Function to find the parent of a given node in the Min Heap
template<typename T>
BTNode<T>* LinkMinHeap<T>::findParent(BTNode<T>* root, BTNode<T>* node)
{
    if (!root || !node)
        return nullptr;

    if (root->left == node || root->right == node)
        return root;

    // Recursively search in the left and right subtrees
    BTNode<T>* left = findParent(root->left, node);
    BTNode<T>* right = findParent(root->right, node);

    return (left ? left : right);
}

// Function to delete the deepest node in the Min Heap
template<typename T>
T LinkMinHeap<T>::deleteDeepest(BTNode<T>* root)
{
    T deletedValue;
    BTNode<T>* deepest = nullptr;
    BTNode<T>* parent = nullptr;

    // Find the deepest node and its parent
    while (root->left)
    {
        parent = root;
        root = root->left;
    }

    deepest = root;
    deletedValue = deepest->info;

    // If the deepest node is also the rightmost leaf, remove the parent's reference
    if (parent)
        parent->left = nullptr;
    else
        this->root = nullptr;

    delete deepest;
    nodeCount--;

    return deletedValue;
}

// Function to heapify after deletion to maintain the Min Heap property
template<typename T>
void LinkMinHeap<T>::heapifyAfterDeletion(BTNode<T>* parent, BTNode<T>* child)
{
    if (!parent || !child)
        return;

    T temp;

    // Swap values until the Min Heap property is restored
    while (child != root && child->info < parent->info)
    {
        temp = parent->info;
        parent->info = child->info;
        child->info = temp;

        // Move up the heap
        child = parent;
        parent = findParent(root, child);
    }
}

// Function to get the minimum element from the Min Heap
template<typename T>
T LinkMinHeap<T>::getMin()
{
    if (!root)
        exit(0);  // Assuming you want to exit on an empty heap
    return root->info;
}

// Function for in-order traversal of the Min Heap
template<typename T>
void LinkMinHeap<T>::LVR(BTNode<T>* printNode)
{
    if (!printNode)
        return;
    if (printNode->left)
        LVR(printNode->left);
    cout << printNode->info << ":";
    if (printNode->right)
        LVR(printNode->right);
}



// Function to perform in-order traversal from the root of the Min Heap
template<typename T>
void LinkMinHeap<T>::inOrderTraversal()
{
    LVR(root);
    cout << endl;
}

// Function to perform post-order traversal from the root of the Min Heap
template<typename T>
void LinkMinHeap<T>::postOrderTraversal()
{
    LRVR(root);
    cout << endl;
}

// Function for post-order traversal of the Min Heap
template<typename T>
void LinkMinHeap<T>::LRVR(BTNode<T>* printNode)
{
    if (!printNode)
        return;
    if (printNode->left)
        LRVR(printNode->left);
    if (printNode->right)
        LRVR(printNode->right);
    cout << printNode->info << ":";
}

// Destructor
template<typename T>
LinkMinHeap<T>::~LinkMinHeap()
{
    // Perform post-order traversal to delete all nodes
    deleteTree(root);
}

// Function to delete all nodes in the Min Heap
template<typename T>
void LinkMinHeap<T>::deleteTree(BTNode<T>* node)
{
    if (!node)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}


