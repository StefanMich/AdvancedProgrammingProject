#pragma once
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


template<typename T, int entries>
StackTemplateValueArgument<T, entries>::StackTemplateValueArgument() : topIndex{ -1 }
{
	arr = new T[entries];
}

template<typename T, int entries>
StackTemplateValueArgument<T, entries>::~StackTemplateValueArgument()
{
	delete arr;
}

template<typename T, int entries>
T StackTemplateValueArgument<T, entries>::Top()
{
	return arr[topIndex];
}

template<typename T, int entries>
bool StackTemplateValueArgument<T, entries>::StackEmpty()
{
	if (topIndex == -1)
		return true;
	else return false;
}

template<typename T, int entries>
void StackTemplateValueArgument<T, entries>::Push(T i)
{
	topIndex++;

	if (topIndex >= entries)
		throw std::out_of_range{ "overflow" };
	else arr[topIndex] = i;
}

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