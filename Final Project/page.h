#ifndef PAGE_H
#include "object.h"
#define PAGE_H

class Post;
class User;

class Page : public Object {
protected:
	User* owner;
	char* title;
	Post** posts; // for timeline posts (list of posts it has shared)
	int postCount; // to see no: of posts 

public:
	Page();

	Page(int id, char* title, User* owner);

	~Page();


	const char* getName() const override;

	void addPost(Post* post);
	void viewTimeline() const;
};

#endif