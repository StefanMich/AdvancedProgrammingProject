#pragma once

#include "Node.h" 


class BinarySearchTree
{
public:
	BinarySearchTree(int k);
	~BinarySearchTree();

	Node* Search(int k);
	void Insert(int k);
	void Delete();

	int Minimum();
	int Maxiumum();

	void InorderTreeWalk();

private:
	Node* root;
};

