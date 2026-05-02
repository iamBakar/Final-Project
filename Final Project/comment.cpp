#include "comment.h"
#include "object.h"
#include<iostream>
#include<cstring>

using namespace std;

Comment::Comment() {
	text = nullptr;
	whoCommented = nullptr;
}

Comment::Comment(const char* text, Object* whoCommented) : whoCommented(whoCommented) {
	this->text = new char[strlen(text) + 1];
	strcpy(this->text, text);
}

Comment::~Comment() {
	delete[] text;
}

void Comment::display() const {
	cout << whoCommented->getID() << " commented " << text << endl;
}