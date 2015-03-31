#include "DataIncompatible.h"
#include <ostream>


DataIncompatible::DataIncompatible()
{
}


DataIncompatible::~DataIncompatible()
{
}

bool operator<(const DataIncompatible& d1, const DataIncompatible& d2)
{
	if (d1.k < d2.k)
		return true;
	else return false;
}

std::ostream& operator<<(std::ostream& output, const DataIncompatible& d)
{
	output << d.k;
	return output;
}