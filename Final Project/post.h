#ifndef POST_H
#define POST_H
#include "object.h"
#include "date.h"

class Comment;
class Date;
class User;
class Activity;
class Page;

class Post : public Object { // posts also have a unique id
protected:
	char* text; // for description
	date shareDay; // date the post was shared
	Object** likedBy; // making object as likes can come from user or pages
	Object* sharedBy;

	Post** likes;
	int likeCount;

	Comment** comment;
	int commentCount;

	Activity* activity;

public:
	Post();
	
	Post(int id, Object* sharedBy, char* text, date& shareDay);

	void addLike(Object* obj);

	void addComment(Comment* comment);

	virtual void display() const;

	void addLike(Object* likedBy);

	void addComment(Comment* comment);

	virtual ~Post();

	bool iswithin24hours(const date& systemdate) const; // as we only need posts of last 24 hrs
	
	const date& getSharedDay();
};

#endif
