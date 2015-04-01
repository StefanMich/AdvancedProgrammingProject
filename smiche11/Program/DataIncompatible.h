#pragma once
#include <ostream>

/// <summary>
/// A simple class with an integer value.Does NOT implement less than and output
/// </summary>
class DataIncompatible
{
public:
	DataIncompatible(int k = 0);
	~DataIncompatible();

	int k;
};

