#ifndef OBJECT_H
#define OBJECT_H

class Object {
protected:
	int id; // only child classes can access it 

public:
	Object();

	Object(int id);

	int getID() const;

	virtual const char* getName() const = 0;

	virtual ~Object(); // as we are gonna us derived objects like posts, user, page 
};

#endif
