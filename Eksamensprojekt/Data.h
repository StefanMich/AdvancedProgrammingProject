#pragma once
class Data
{
public:
	Data();
	~Data();

	int k;
	bool operator<(const Data& d);
};

