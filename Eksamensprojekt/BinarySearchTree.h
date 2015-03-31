#pragma once

#include "Node.h" 
#include <iostream>

template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree(T k);
	~BinarySearchTree();

	Node<T>* Search(T k);
	void Insert(T k);
	void Delete();

	T Minimum();
	T Maxiumum();

	void InorderTreeWalk();

private:
	Node<T>* root;
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(T k)
{
	root = new Node<T>(k);
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	std::cout << "delete bst";
	delete root;
}

template<typename T>
Node<T>* treeSearch(Node<T>* x, int k)
{
	if (x == 0 || x->key == k)
		return x;

	if (k < x->key)
		return treeSearch(x->left, k);
	else return treeSearch(x->right, k);
}

template<typename T>
Node<T>* BinarySearchTree<T>::Search(T k)
{
	return treeSearch(root, k);
}


template<typename T>
void BinarySearchTree<T>::Insert(T k)
{
	Node<T>* z = new Node<T>(k);

	Node<T>* x = root;
	Node<T>* y = 0;

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

template<typename T>
void inordertreewalk(Node<T>* x)
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
