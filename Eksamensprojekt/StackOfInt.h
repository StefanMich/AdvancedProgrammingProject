#pragma once
class StackOfInt
{
public:
	StackOfInt();
	~StackOfInt();

	void Push(int i);
	int Pop();

	bool StackEmpty();
	int Top();

private:
	int arr[10];
	int topIndex;
};

