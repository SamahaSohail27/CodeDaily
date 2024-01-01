#pragma once
template<typename T>
class BTNode
{
public:
	T info;
	BTNode<T>* left;
	BTNode<T>* right;
	BTNode();
	BTNode(T);
};

