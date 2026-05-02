#ifndef MEMORY_H
#define MEMOERY_H
#include "post.h"

class Memory : public Post {
protected:
	Post* originalPost; // ppointer to old post

public:
	Memory(int id, Object* sharedBy, char* text, date& shareDay, Post* originalPost);

	void display() const;
};

#endif