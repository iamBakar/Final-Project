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

	Post** likes;
	int likeCount;

	Comment** comment;
	int commentCount;

	Activity* activity;

public:
	Post();
	
	Post(int id, char* text, date& shareDay);

	void addLike(Object* obj);

	void addComment(Comment* comment);

	virtual void display() const;

	void addLike(Object* likedBy);

	void addComment(Comment* comment);

	virtual ~Post();

	bool iswithin24hours(const date& systemdate) const;
	bool issamedayandmonth(const date& other) const;
	int yeardifference(const date& other) const;
	
	const date& getSharedDay();
};

#endif
