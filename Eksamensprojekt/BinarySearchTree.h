#pragma once

#include "Node.h" 
#include <iostream>

template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree(T k);
	~BinarySearchTree();

	Node* Search(T k);
	void Insert(T k);
	void Delete();

	T Minimum();
	T Maxiumum();

	void InorderTreeWalk();

private:
	Node* root;
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(T k)
{
	root = new Node(k);
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	delete root;
}

Node* treeSearch(Node* x, int k)
{
	if (x == 0 || x->key == k)
		return x;

	if (k < x->key)
		return treeSearch(x->left, k);
	else return treeSearch(x->right, k);
}

template<typename T>
Node* BinarySearchTree<T>::Search(T k)
{
	return treeSearch(root, k);
}


template<typename T>
void BinarySearchTree<T>::Insert(T k)
{
	Node* z = new Node(k);

	Node* x = root;
	Node* y = 0;

	while (x != 0)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else x = x->right;
	}

	z->parent = y;

	if (y == 0)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else y->right = z;
}

void inordertreewalk(Node* x)
{
	if (x != 0){
		inordertreewalk(x->left);
		std::cout << x->key;
		inordertreewalk(x->right);
	}
}

template<typename T>
void BinarySearchTree<T>::InorderTreeWalk()
{
	inordertreewalk(root);
}
