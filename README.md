# CodeDaily
Construct binary tree form inorder and postorder:
Algorithm
1. Start from the end of postorder & pick an element to create a node
2. Decrement postorder idx
3. Search for picked element's pos in inorder
4. Call to build right subtree from inorder's pos+1 to n
5. Call to build left subtree from inorder 0 to pos-1
6. Return the node

Basically we take root node from preorder or post order then go to inorder and find its right and left nodes. If root has no element on left or right side it means they have no left or right node.

# Construct binary tree from preorder and postorder
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

