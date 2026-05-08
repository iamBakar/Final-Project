#ifndef MEMORY_H
#define MEMOERY_H
#include "post.h"

class Memory : public Post {
protected:
	Post* originalPost; // ppointer to old post

public:
	Memory(const char* id, Object* sharedBy, const char* text, date& shareDay, Post* originalPost);

	void display() const;
};

#endif