#include "Data.h"
#include <ostream>


Data::Data(int k )
{
	this->k = k;
}


Data::~Data()
{
}

bool operator<(const Data& d1, const Data& d2)
{
	if (d1.k < d2.k)
		return true;
	else return false;
}

std::ostream& operator<<(std::ostream& output, const Data& d)
{
	output << d.k;
	return output;
}