#include "Data.h"
#include "Data.h"


Data::Data()
{
}


Data::~Data()
{
}

bool Data::operator<(const Data& d)
{
	if (k < d.k)
		return true;
	else return false;
}