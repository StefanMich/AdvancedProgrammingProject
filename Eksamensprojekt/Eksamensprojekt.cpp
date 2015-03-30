// Eksamensprojekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "StackOfInt.h"
#include <iostream>

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

	std::cout << s.Pop() << s.Pop() << s.Pop();
}