#pragma once
//A node in a binary tree
class Node;

class Node
{
public:
	Node(int k);
	~Node();

	Node* left;
	Node* right;
	Node* parent;
	int key;


};

