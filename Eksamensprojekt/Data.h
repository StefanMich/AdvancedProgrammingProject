#pragma once
#include <ostream>

class Data
{
public:
	Data();
	~Data();

	int k;
	friend bool operator<(const Data& d1, const Data& d2);
	friend std::ostream &operator<<(std::ostream &output, const Data &d);
};

