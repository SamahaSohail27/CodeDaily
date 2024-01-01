		
#ifndef LINK_MIN_HEAP_H
#define LINK_MIN_HEAP_H

template <typename T>
struct BTNode {
    T info;
    BTNode* left;
    BTNode* right;

    BTNode(T val) : info(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class LinkMinHeap {
private:
    BTNode<T>* root;
    int nodeCount;

    void LVR(BTNode<T>* printNode);
    BTNode<T>* findMinNode(BTNode<T>* node);
    BTNode<T>* findParent(BTNode<T>* root, BTNode<T>* node);
    T deleteDeepest(BTNode<T>* root);
    void heapifyAfterDeletion(BTNode<T>* parent, BTNode<T>* child);
    void LRVR(BTNode<T>* printNode);
    void deleteTree(BTNode<T>* node);

public:
    LinkMinHeap();
    ~LinkMinHeap();

    void insert(T val);
    void removeMin();
    T getMin();
    void inOrderTraversal();
    void postOrderTraversal();
};

#endif  // LINK_MIN_HEAP_H
