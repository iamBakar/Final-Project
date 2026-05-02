#include "activity.h"
#include "user.h"
#include <iostream>

using namespace std;

Activity::Activity() {
	value = nullptr;
	type = 0;
}

Activity::Activity(int type, char*value) : type(type) {
	this->value = new char[strlen(value) + 1];
	strcpy(this->value, value);
}

Activity::~Activity() {
	delete[] value;
}

void Activity::display() const { // only prints activity not name as its alr in post (post knows who updated)
	switch (type) {
    case 1:
        cout << " is feeling " << value << endl;
        break;

    case 2:
        cout << " is thinking about " << value << endl;
        break;

    case 3:
        cout << " is making " << value << endl;
        break;

    case 4:
        cout << " is celebrating " << value << endl;
        break;
	}
}

