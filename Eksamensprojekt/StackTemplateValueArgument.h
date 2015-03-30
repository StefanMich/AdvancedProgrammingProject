#pragma once
template<typename T,int entries>
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
	T arr[10];
	int topIndex;
};


template<typename T>
StackTemplateValueArgument<T>::StackTemplateValueArgument() : arr{}, topIndex{ -1 }
{
}

template<typename T>
StackTemplateValueArgument<T>::~StackTemplateValueArgument()
{
}

template<typename T>
T StackTemplateValueArgument<T>::Top()
{
	return arr[topIndex];
}

template<typename T>
bool StackTemplateValueArgument<T>::StackEmpty()
{
	if (topIndex == -1)
		return true;
	else return false;
}

template<typename T>
void StackTemplateValueArgument<T>::Push(T i)
{
	topIndex++;
	arr[topIndex] = i;
}

template<typename T>
T StackTemplateValueArgument<T>::Pop()
{
	if (StackEmpty())
		throw "underflow";
	else
	{
		topIndex--;
		return arr[topIndex + 1];
	}
}