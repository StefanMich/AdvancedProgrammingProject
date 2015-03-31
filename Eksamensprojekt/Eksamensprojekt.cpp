// Eksamensprojekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "StackOfInt.h"
#include "StackTemplate.h"
#include "StackTemplateValueArgument.h"
#include "StackTemplateBoolSpecialization.h"

#include "Node.h"
#include "BinarySearchTree.h"
#include "Data.h"
#include "DataIncompatible.h"

#include <string>
#include <iostream>



using string = std::string;


void StackOfIntTest();
void StackTemplateTest();
void StackTemplateBoolSpecializationTest();

void BSTConceptTest();

int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

void StackOfIntTest()
{
	StackOfInt s = StackOfInt();
	s.Push(5);
	s.Push(4);
	s.Push(3);

	std::cout << s.Pop() << "\n";
	std::cout << s.Pop() << "\n";
	std::cout << s.Pop() << "\n";
}

void StackTemplateTest(){
	StackTemplate<int> s = StackTemplate<int>();
	s.Push(5);
	s.Push(4);
	s.Push(3);

	std::cout << s.Pop() << "\n";
	std::cout << s.Pop() << "\n";
	std::cout << s.Pop() << "\n";

	StackTemplate<string> t = StackTemplate<string>();
	t.Push("first");
	t.Push("second");
	t.Push("third");

	std::cout << t.Pop() << "\n";
	std::cout << t.Pop() << "\n";
	std::cout << t.Pop() << "\n";
}

void StackTemplateValueArgumentTest()
{
	StackTemplateValueArgument<int, 3> s = StackTemplateValueArgument<int, 3>();
	s.Push(5);
	s.Push(4);
	s.Push(3);

	std::cout << s.Pop() << "\n";
	std::cout << s.Pop() << "\n";
	std::cout << s.Pop() << "\n";

	int k;
	std::cin >> k;

	StackTemplateValueArgument<int, 2> t = StackTemplateValueArgument<int, 2>();
	t.Push(5);
	t.Push(4);
	t.Push(3);

	std::cout << t.Pop() << "\n";
	std::cout << t.Pop() << "\n";
	std::cout << t.Pop() << "\n";
}

void StackTemplateBoolSpecializationTest()
{
	StackTemplateBoolSpecialization<int> st = StackTemplateBoolSpecialization<int>();
	st.Push(1);
	st.Push(1);
	st.Push(2);

	std::cout << st.Pop() << "\n";
	std::cout << st.Pop() << "\n";
	std::cout << st.Pop() << "\n";

	StackTemplateBoolSpecialization<bool> s = StackTemplateBoolSpecialization<bool>();

	for (int i = 0; i < 8; i++)
	{
		s.Push(false);
		s.Push(true);
	}

	for (int j = 0; j < 16; j++)
		std::cout << "Popping: " << s.Pop() << "\n";
}

void BSTConceptTest()
{
	BinarySearchTree<Data>* bst = new BinarySearchTree<Data>(Data(1));
	bst->Insert(Data(2));
	bst->Insert(Data(3));

	bst->InorderTreeWalk();

	/*
	BinarySearchTree<DataIncompatible>* bstIncompatible = new BinarySearchTree<DataIncompatible>(DataIncompatible(1));
	bstIncompatible->Insert(DataIncompatible(2));
	bstIncompatible->Insert(DataIncompatible(3));

	bstIncompatible->InorderTreeWalk();
	*/
}