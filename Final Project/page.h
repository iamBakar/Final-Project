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

	Page(const char* id, const char* title, User* owner);

	~Page();


	const char* getName() const override;

	void addPost(Post* post);
	void viewTimeline() const;

	Post** getPosts() const; // to get posts access of a page
	int getPostCount() const;
};

#endif