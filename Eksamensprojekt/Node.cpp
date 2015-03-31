#include "Node.h"
//A node in a binary tree

Node::Node(int k)
{
	key = k;
}


Node::~Node()
{
	delete right;
	delete left;
}
