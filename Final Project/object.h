#ifndef OBJECT_H
#define OBJECT_H

class Object {
protected:
	char* id; // only child classes can access it 

public:
	Object();

	Object(const char* id);

	const char* getID() const;

	virtual const char* getName() const = 0;

	virtual ~Object(); // as we are gonna us derived objects like posts, user, page 
};

#endif
