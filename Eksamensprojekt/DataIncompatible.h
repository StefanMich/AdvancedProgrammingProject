#pragma once
#include <ostream>

class DataIncompatible
{
public:
	DataIncompatible(int k = 0);
	~DataIncompatible();

	int k;
};

