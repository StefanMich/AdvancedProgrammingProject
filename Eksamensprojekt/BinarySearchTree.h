#pragma once

#include "Node.h" 
#include <iostream>
#include "Concepts.cpp"

template<typename T>
class BinarySearchTree
{
	
public:
	static_assert(Has_Less_Than<T>(), "template type must implement the less than operator, <");
	static_assert(Has_Output<T>(), "template type must implement output operator, <<");

	BinarySearchTree(T k);
	~BinarySearchTree();

	Node<T>* Search(T k);
	void Insert(T k);
	void Delete();

	T Minimum();
	T Maxiumum();

	void InorderTreeWalk();

	T AddArbitrary(T k);

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
	delete root;
}

template<typename T>
Node<T>* treeSearch(Node<T>* x, int k)
{
	if (x == nullptr || x->key == k)
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
	Node<T>* y = nullptr;

	

	while (x != nullptr)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else x = x->right;
	}

	z->parent = y;

	if (y == nullptr)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else y->right = z;
}

template<typename T>
void inordertreewalk(Node<T>* x)
{
	if (x != nullptr){
		inordertreewalk(x->left);
		std::cout << x->key <<std::endl;
		inordertreewalk(x->right);
	}
}

template<typename T>
void BinarySearchTree<T>::InorderTreeWalk()
{
	inordertreewalk(root);
}

template<typename T>
T BinarySearchTree<T>::AddArbitrary(T k)
{
	return root->key + k;
}