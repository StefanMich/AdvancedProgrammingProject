#pragma once
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
	T arr[10];
	int topIndex;
};


template<typename T>
StackTemplate<T>::StackTemplate() : topIndex{ -1}
{
}

template<typename T>
StackTemplate<T>::~StackTemplate()
{
}

template<typename T>
T StackTemplate<T>::Top()
{
	return arr[topIndex];
}

template<typename T>
bool StackTemplate<T>::StackEmpty()
{
	if (topIndex == -1)
		return true;
	else return false;
}

template<typename T>
void StackTemplate<T>::Push(T i)
{
	topIndex++;
	arr[topIndex] = i;
}

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