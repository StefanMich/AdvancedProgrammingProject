#pragma once

template<typename T, int entries>
class StackTemplateBoolSpecialization
{
public:
	StackTemplateBoolSpecialization();
	~StackTemplateBoolSpecialization();

	void Push(T i);
	T Pop();

	bool StackEmpty();
	T Top();

private:
	T* arr;
	int topIndex;
};


template<typename T, int entries>
StackTemplateBoolSpecialization<T, entries>::StackTemplateBoolSpecialization() : topIndex{ -1 }
{
	arr = new T[entries];
}

template<typename T, int entries>
StackTemplateBoolSpecialization<T, entries>::~StackTemplateBoolSpecialization()
{
	delete arr;
}

template<typename T, int entries>
T StackTemplateBoolSpecialization<T, entries>::Top()
{
	return arr[topIndex];
}

template<typename T, int entries>
bool StackTemplateBoolSpecialization<T, entries>::StackEmpty()
{
	if (topIndex == -1)
		return true;
	else return false;
}

template<typename T, int entries>
void StackTemplateBoolSpecialization<T, entries>::Push(T i)
{
	topIndex++;

	if (topIndex >= entries)
		throw std::out_of_range{ "overflow" };
	else arr[topIndex] = i;
}

template<typename T, int entries>
T StackTemplateBoolSpecialization<T, entries>::Pop()
{
	if (StackEmpty())
		throw std::out_of_range{ "underflow" };
	else
	{
		topIndex--;
		return arr[topIndex + 1];
	}
}




// Complete bool specialization

template< int entries>
class StackTemplateBoolSpecialization<bool,entries>
{
public:
	StackTemplateBoolSpecialization();
	~StackTemplateBoolSpecialization();

	void Push(bool i);
	bool Pop();

	bool StackEmpty();
	bool Top();

private:
	char* arr;
	int topIndex;
};

template< int entries>
StackTemplateBoolSpecialization<bool,entries>::StackTemplateBoolSpecialization() : topIndex{ -1 }
{
	int bytes = (entries / 8) + 1;
	char arr[bytes] = {0};

}

template<int entries>
StackTemplateBoolSpecialization<bool,entries>::~StackTemplateBoolSpecialization()
{
	delete arr;
}

template<int entries>
bool StackTemplateBoolSpecialization<bool,entries>::Top()
{
	return arr[topIndex];
}

template< int entries>
bool StackTemplateBoolSpecialization<bool,entries>::StackEmpty()
{
	if (topIndex == -1)
		return true;
	else return false;
}

template< int entries>
void StackTemplateBoolSpecialization<bool,entries>::Push(bool i)
{
	if (topIndex >= entries)
		throw std::out_of_range{ "overflow" };

	
	int positionInRepr = topIndex / 8;

	int index = arr[positionInRepr];

	if (i == true)
	{
		index = index | 1 << ((8 - (topIndex % 8)) - 1);
		arr[positionInRepr] = index;
		topIndex++;
	}
	else if(i == false)
	{
		topIndex++;
	}
}

template< int entries>
bool StackTemplateBoolSpecialization<bool,entries>::Pop()
{
	std::cout << "bool specialization";
	if (StackEmpty())
		throw std::out_of_range{ "underflow" };
	else
	{
		int positionInRepr = topIndex / 8;
		int positionInByte = topIndex % 8;

		// find entry in byte
		char entry = arr[positionInRepr] << (positionInByte - 1);
		entry = entry>> 7;
		bool poppedEntry = (bool)entry;

		//reset everything to the right of topIndex to 0
		int indexToShift = 8 - (positionInByte);
		char index = arr[positionInRepr];
		index = index >> indexToShift;
		index = index << indexToShift;

		topIndex--;

		return poppedEntry;
	}
}

