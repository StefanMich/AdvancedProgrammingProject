#pragma once

#include <stdexcept>
#include <iostream>
#include <bitset>

void printArr(unsigned char* arr);
void printChar(unsigned char ch);

template<typename T>
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


template<typename T>
StackTemplateBoolSpecialization<T>::StackTemplateBoolSpecialization() : topIndex{ -1 }
{
	arr = new T[10];
}

template<typename T>
StackTemplateBoolSpecialization<T>::~StackTemplateBoolSpecialization()
{
	delete arr;
}

template<typename T>
T StackTemplateBoolSpecialization<T>::Top()
{
	return arr[topIndex];
}

template<typename T>
bool StackTemplateBoolSpecialization<T>::StackEmpty()
{
	if (topIndex == -1)
		return true;
	else return false;
}

template<typename T>
void StackTemplateBoolSpecialization<T>::Push(T i)
{
	topIndex++;

	if (topIndex >= 10)
		throw std::out_of_range{ "overflow" };
	else arr[topIndex] = i;
}

template<typename T>
T StackTemplateBoolSpecialization<T>::Pop()
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

template<>
class StackTemplateBoolSpecialization<bool>
{
public:
	StackTemplateBoolSpecialization();
	~StackTemplateBoolSpecialization();

	void Push(bool i);
	bool Pop();

	bool StackEmpty();
	bool Top();

private:
	unsigned char* arr;
	int topIndex;
};

StackTemplateBoolSpecialization<bool>::StackTemplateBoolSpecialization() : topIndex{ -1 }
{
	arr = new unsigned char[2];
	arr[0] = 0;
	arr[1] = 0;
}

StackTemplateBoolSpecialization<bool>::~StackTemplateBoolSpecialization()
{
	delete arr;
}

bool StackTemplateBoolSpecialization<bool>::Top()
{
	int positionInRepr = topIndex / 8;
	int positionInByte = topIndex % 8;

	char entry = arr[positionInRepr] << (positionInByte );
	entry = entry >> 7;
	bool poppedEntry = (bool)entry;

	return poppedEntry;
}

bool StackTemplateBoolSpecialization<bool>::StackEmpty()
{
	if (topIndex == -1)
		return true;
	else return false;
}

void StackTemplateBoolSpecialization<bool>::Push(bool i)
{
	if (topIndex >= 16)
		throw std::out_of_range{ "overflow" };

	
	int positionInRepr = (topIndex+1) / 8;

	int index = arr[positionInRepr];

	if (i == true)
	{
		int mellem = ((topIndex + 1) % 8);
		int shift = 7 - mellem;

		unsigned char bit = 1 << shift;
		index = index | bit;
		arr[positionInRepr] = index;
		topIndex++;
	}
	else if(i == false)
	{
		topIndex++;
	}
	

	//printArr(arr);
	//std::cout << topIndex << std::endl;
}

bool StackTemplateBoolSpecialization<bool>::Pop()
{
	//std::cout << "bool specialization";
	if (StackEmpty())
		throw std::out_of_range{ "underflow" };
	else
	{
		int positionInRepr = topIndex / 8;
		int positionInByte = topIndex % 8;

		// find entry in byte
		bool poppedEntry = Top();

		//reset everything to the right of topIndex to 0
		int indexToShift = 7 - positionInByte;
		unsigned char index = arr[positionInRepr];
		index = index >> indexToShift;
		index = index << indexToShift;
		arr[positionInRepr] = index;

		topIndex--;

		//printArr(arr);
		return poppedEntry;
	}
}

void printArr(unsigned char* arr)
{
	std::cout << "arr: " << std::endl;
	printChar(arr[0]);
	printChar(arr[1]);
	std::cout << std::endl;
}

void printChar(unsigned char ch)
{
	std::bitset<8> a(ch);
	std::cout << a << std::endl;
}
