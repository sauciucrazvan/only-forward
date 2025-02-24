#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Exception.h"

#include <iostream>
#include <ctime>

Exception::Exception(char* _id, char* _desc) {
	this->id = new char[strlen(_id) + 1];
	this->desc = new char[strlen(_desc) + 1];

	strcpy_s(this->id, strlen(_id) + 1, _id); strcpy_s(this->desc, strlen(_desc) + 1, _desc);
}

void Exception::Print() {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	std::cerr << "[" << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "] " << "[EXCEPTION - " << this->id << "] " << this->desc << std::endl;
}