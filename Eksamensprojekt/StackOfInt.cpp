#include "StackOfInt.h"


StackOfInt::StackOfInt() : arr{}, topIndex{ 0 }
{

}


StackOfInt::~StackOfInt()
{
}

int StackOfInt::Top()
{
	return arr[topIndex];
}

bool StackOfInt::StackEmpty()
{
	if (topIndex == 0)
		return true;
	else return false;
}

void StackOfInt::Push(int i)
{
	topIndex++;
	arr[topIndex] = i;
}

int StackOfInt::Pop()
{
	if (StackEmpty())
		throw "underflow";
	else
	{
		topIndex--;
		return arr[topIndex + 1];
	}
}

