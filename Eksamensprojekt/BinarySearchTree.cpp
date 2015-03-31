#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree(int k)
{
	root = new Node(k);
}


BinarySearchTree::~BinarySearchTree()
{
}

Node* treeSearch(Node* x, int k)
{
	if (x == 0 || x->key == k)
		return x;

	if (k < x->key)
		return treeSearch(x->left, k);
	else return treeSearch(x->right, k);
}

Node* BinarySearchTree::Search(int k)
{
	return treeSearch(root, k);
}



void BinarySearchTree::Insert(int k)
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


void BinarySearchTree::InorderTreeWalk()
{
	inordertreewalk(root);
}

void Delete();
int Minimum();
int Maxiumum();