#include "Exception.h"

#include <iostream>

Exception::Exception(char* _id, char* _desc) {
	this->id = new char[strlen(_id) + 1];
	this->desc = new char[strlen(_desc) + 1];

	strcpy_s(this->id, strlen(_id) + 1, _id); strcpy_s(this->desc, strlen(_desc) + 1, _desc);
}

void Exception::Print() {
	std::cerr << "[EXCEPTION - " << this->id << "]: " << this->desc << std::endl;
}