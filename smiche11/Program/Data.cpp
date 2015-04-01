#include "Data.h"
#include <ostream>


/// <summary>
/// Initializes a new instance of the <see cref="Data"/> class.
/// </summary>
/// <param name="k">The value for the Data to contain.</param>
Data::Data(int k )
{
	this->k = k;
}


/// <summary>
/// Finalizes an instance of the <see cref="Data"/> class.
/// </summary>
Data::~Data()
{
}

/// <summary>
/// Less than operator for comparing two Data objects
/// </summary>
/// <param name="d1">The d1.</param>
/// <param name="d2">The d2.</param>
/// <returns></returns>
bool operator<(const Data& d1, const Data& d2)
{
	if (d1.k < d2.k)
		return true;
	else return false;
}

/// <summary>
/// Output operator for displaying the value on an ostream
/// </summary>
/// <param name="output">The output.</param>
/// <param name="d">The d.</param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& output, const Data& d)
{
	output << d.k;
	return output;
}