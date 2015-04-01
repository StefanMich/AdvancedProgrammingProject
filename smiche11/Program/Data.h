#pragma once
#include <ostream>

/// <summary>
/// A simple class with an integer value. Implements less than and output
/// </summary>
class Data
{
public:
	Data(int k = 0);
	~Data();

	int k;
	friend bool operator<(const Data& d1, const Data& d2);
	friend std::ostream &operator<<(std::ostream &output, const Data &d);
};

