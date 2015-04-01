#include "StackOfInt.h"
#include <stdexcept>

/// <summary>
/// Initializes a new instance of the <see cref="StackOfInt"/> class.
/// </summary>
StackOfInt::StackOfInt() : arr{}, topIndex{ -1 }
{

}


/// <summary>
/// Finalizes an instance of the <see cref="StackOfInt"/> class.
/// </summary>
StackOfInt::~StackOfInt()
{
}

/// <summary>
/// returns the top element of the stack without popping it
/// </summary>
/// <returns>The top element of the stack</returns>
int StackOfInt::Top()
{
	return arr[topIndex];
}

/// <summary>
/// Returns whether the stack is empty
/// </summary>
/// <returns>True if the stack is empty, false otherwise</returns>
bool StackOfInt::StackEmpty()
{
	if (topIndex == -1)
		return true;
	else return false;
}

/// <summary>
/// Pushes the specified element to the stack.
/// </summary>
/// <param name="i">The element to push</param>
void StackOfInt::Push(int i)
{
	topIndex++;
	arr[topIndex] = i;
}


/// <summary>
/// Pops the top element from the stack
/// </summary>
/// <returns>The popped element</returns>
int StackOfInt::Pop()
{
	if (StackEmpty())
		throw std::out_of_range{"underflow"};
	else
	{
		topIndex--;
		return arr[topIndex + 1];
	}
}

