#include "object.h"
#include<cstring>

Object::Object() {
	id = nullptr;
}

Object::Object(const char* id) {
	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);
}

const char* Object::getID() const {
	return id;
}

Object::~Object() {
	delete[] id;
}
