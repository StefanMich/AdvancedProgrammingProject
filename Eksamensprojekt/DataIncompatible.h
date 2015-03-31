#pragma once
#include <ostream>

class DataIncompatible
{
public:
	DataIncompatible();
	~DataIncompatible();

	int k;
	friend bool operator<(const DataIncompatible& d1, const DataIncompatible& d2);
	friend std::ostream &operator<<(std::ostream &output, const DataIncompatible &d);
};

