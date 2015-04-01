#pragma once
/// <summary>
/// An implementation of a stack that has a template arguemnt T for the type of the elements in the stack
/// </summary>
template<typename T>
class StackTemplate
{
public:
	StackTemplate();
	~StackTemplate();

	void Push(T i);
	T Pop();

	bool StackEmpty();
	T Top();

private:
	T arr[16];
	int topIndex;
};


/// <summary>
/// Initializes a new instance of the <see cref="StackTemplate{T}"/> class.
/// </summary>
template<typename T>
StackTemplate<T>::StackTemplate() : topIndex{ -1}
{
}

/// <summary>
/// Finalizes an instance of the <see cref="StackTemplate{T}"/> class.
/// </summary>
template<typename T>
StackTemplate<T>::~StackTemplate()
{
}

/// <summary>
/// returns the top element of the stack without popping it
/// </summary>
/// <returns>The top element of the stack</returns>
template<typename T>
T StackTemplate<T>::Top()
{
	return arr[topIndex];
}

/// <summary>
/// Returns whether the stack is empty
/// </summary>
/// <returns>True if the stack is empty, false otherwise</returns>
template<typename T>
bool StackTemplate<T>::StackEmpty()
{
	if (topIndex == -1)
		return true;
	else return false;
}

/// <summary>
/// Pushes the specified element to the stack.
/// </summary>
/// <param name="i">The element to push</param>
template<typename T>
void StackTemplate<T>::Push(T i)
{
	topIndex++;
	arr[topIndex] = i;
}

/// <summary>
/// Pops the top element from the stack
/// </summary>
/// <returns>The popped element</returns>
template<typename T>
T StackTemplate<T>::Pop()
{
	if (StackEmpty())
		throw std::out_of_range{ "underflow" };
	else
	{
		topIndex--;
		return arr[topIndex + 1];
	}
}

