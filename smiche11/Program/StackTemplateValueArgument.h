#pragma once
/// <summary>
/// An implementation of a stack that has a template arguemnt T for the type of the elements in the stack as well as a integer template argument specifying the size of the stack
/// </summary>
template<typename T, int entries>
class StackTemplateValueArgument
{
public:
	StackTemplateValueArgument();
	~StackTemplateValueArgument();

	void Push(T i);
	T Pop();

	bool StackEmpty();
	T Top();

private:
	T* arr;
	int topIndex;
};


/// <summary>
/// Initializes a new instance of the <see cref="StackTemplateValueArgument{T, entries}"/> class.
/// </summary>
template<typename T, int entries>
StackTemplateValueArgument<T, entries>::StackTemplateValueArgument() : topIndex{ -1 }
{
	arr = new T[entries];
}

/// <summary>
/// Finalizes an instance of the <see cref="StackTemplateValueArgument{T, entries}"/> class.
/// </summary>
template<typename T, int entries>
StackTemplateValueArgument<T, entries>::~StackTemplateValueArgument()
{
	delete[] arr;
}

/// <summary>
/// returns the top element of the stack without popping it
/// </summary>
/// <returns>The top element of the stack</returns>
template<typename T, int entries>
T StackTemplateValueArgument<T, entries>::Top()
{
	return arr[topIndex];
}

/// <summary>
/// Returns whether the stack is empty
/// </summary>
/// <returns>True if the stack is empty, false otherwise</returns>
template<typename T, int entries>
bool StackTemplateValueArgument<T, entries>::StackEmpty()
{
	if (topIndex == -1)
		return true;
	else return false;
}

/// <summary>
/// Pushes the specified element to the stack.
/// </summary>
/// <param name="i">The element to push</param>
template<typename T, int entries>
void StackTemplateValueArgument<T, entries>::Push(T i)
{
	topIndex++;

	if (topIndex >= entries)
		throw std::out_of_range{ "overflow" };
	else arr[topIndex] = i;
}

/// <summary>
/// Pops the top element from the stack
/// </summary>
/// <returns>The popped element</returns>
template<typename T, int entries>
T StackTemplateValueArgument<T, entries>::Pop()
{


	if (StackEmpty())
		throw std::out_of_range{ "underflow" };
	else
	{
		topIndex--;
		return arr[topIndex + 1];
	}
}