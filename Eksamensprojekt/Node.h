#pragma once
//A node in a binary tree

template<typename T>
class Node
{
public:
	Node(T k );
	~Node();

	Node* left;
	Node* right;
	Node* parent;
	T key;


};

template<typename T>
Node<T>::Node(T k)
{
	key = k;
}

template<typename T>
Node<T>::~Node()
{
	if (left != 0)
		delete left;
	if (right != 0)
		delete right;
}

