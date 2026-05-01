#ifndef USER_H
#define USER_H

#include "object.h"

class Page; // forward declarations: tells these classes exist later on 
class Post;

class User : public Object { // tells every user automatically has id 
private:
	char* name;

	// posts shared
	Post** posts;
	int postCount;

	// total pages liked by user
	Page** pagesLiked;
	int likedPagesCount;
	
	// friends of user
	User** friends;
	int friendsCount;

public:
	User();

	User(int id, const char* name);

	~User();

	const char* getName() const;

	// Page related functions as asked in #3
	void likePage(Page* page);

	// Friend related functions as asked in #9
	void viewFriendList() const; 

	// Post related functions as asked #8
	void addPost(Post* post); // since user has posts there should be a method to add more
	void viewProfile() const; 

};

#endif