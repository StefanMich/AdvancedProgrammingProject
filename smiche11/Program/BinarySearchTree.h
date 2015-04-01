#pragma once

#include "Node.h" 
#include <iostream>
#include "Concepts.cpp"

/// <summary>
/// A binary search tree using concepts to check that the less than and output operators are defined on the type argument
/// </summary>
template<typename T>
class BinarySearchTree
{
	
public:
	static_assert(Has_Less_Than<T>(), "template arguement type must implement the less than operator, <, in order to compare the inserted elements");
	static_assert(Has_Output<T>(), "template argument type must implement output operator, <<, in order to print the tree in an inorder tree traversal");

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

/// <summary>
/// Initializes a new instance of the <see cref="BinarySearchTree{T}"/> class.
/// </summary>
/// <param name="k">The k.</param>
template<typename T>
BinarySearchTree<T>::BinarySearchTree(T k)
{
	root = new Node<T>(k);
}

/// <summary>
/// Finalizes an instance of the <see cref="BinarySearchTree{T}"/> class.
/// </summary>
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

/// <summary>
/// Searches for k in the tree
/// </summary>
/// <param name="k">The k.</param>
/// <returns>The node containing k, or nullptr if it does not exist in the tree</returns>
template<typename T>
Node<T>* BinarySearchTree<T>::Search(T k)
{
	return treeSearch(root, k);
}


/// <summary>
/// Inserts the specified k into the tree
/// </summary>
/// <param name="k">The k.</param>
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

/// <summary>
/// Performs an inorders tree walk on the tree, printing every value
/// </summary>
template<typename T>
void BinarySearchTree<T>::InorderTreeWalk()
{
	inordertreewalk(root);
}

/// <summary>
/// Adds k to the key of the root. 
/// </summary>
/// <param name="k">The k.</param>
/// <returns></returns>
template<typename T>
T BinarySearchTree<T>::AddArbitrary(T k)
{
	return root->key + k;
}