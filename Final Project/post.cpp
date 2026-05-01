#include "post.h"
#include<iostream>
#include "object.h"
//#include "comment.h"
//#include "activity.h"
#include "user.h"
#include "date.h"
//#include "page.h"

using namespace std;

const int MAX_LIKES = 10;
const int MAX_COMMENTS = 10;

Post::Post() {
	id = 0;
	text = nullptr;

	likedBy = new Object * [MAX_LIKES];
	comment = new Comment * [MAX_COMMENTS];

	likeCount = 0;
	commentCount = 0;
}

Post::Post(int id, char* text, date& shareDay) : Object(id), shareDay(shareDay) {
	this->text = new char[strlen(text) + 1];
	strcpy(this->text, text);

	likedBy = new Object * [MAX_LIKES];
	comment = new Comment * [MAX_COMMENTS];

	likeCount = 0;
	commentCount = 0;
}

Post::~Post() {
	delete[] likedBy;
	delete[] comment;
	delete[] text;
	delete[] activity;
}


void Post::addLike(Object* likedBy)
{
	if (likeCount < MAX_LIKES)
	{
		this->likedBy[likeCount++] = likedBy;
	}
}

void Post::addComment(Comment* comment)
{
	if (commentCount < MAX_COMMENTS)
	{
		this->comment[commentCount++] = comment;
	}
}

