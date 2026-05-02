#ifndef COMMENT_H
#define COMMENT_H
#include "object.h"

class Object;

class Comment : public Object {
protected:
	char* text;
	Object* whoCommented; // tells either user or post 

public:
	Comment();

	Comment(const char* text, Object* whoCommented);

	~Comment();

	virtual void display() const;
};

#endif
