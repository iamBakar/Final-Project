#include "object.h"

Object::Object() {
	id = 0;
}

Object::Object(int id) : id(id) {}

int Object::getID() const {
	return id;
}

Object::~Object() {

}
