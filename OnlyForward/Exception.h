#pragma once

#include <cstring>

class Exception
{
private:
	char *id, *desc;
public:
	Exception(char* _id, char* _desc);
	void Print();
};

