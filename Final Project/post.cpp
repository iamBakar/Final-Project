#define _CRT_SECURE_NO_WARNINGS
#include "post.h"
#include<iostream>
#include "object.h"
#include "comment.h"
#include "activity.h"
#include "user.h"
#include "date.h"
#include "page.h"

using namespace std;

const int MAX_LIKES = 10;
const int MAX_COMMENTS = 10;

Post::Post() {
	id = nullptr;
	text = nullptr;
	activity = nullptr;

	likedBy = new Object * [MAX_LIKES];
	comment = new Comment * [MAX_COMMENTS];

	likeCount = 0;
	commentCount = 0;

	sharedBy = nullptr;
}

Post::Post(const char* id, Object* sharedBy, const char* text, date& shareDay) : Object(id), sharedBy(sharedBy), shareDay(shareDay) {
	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);

	this->text = new char[strlen(text) + 1];
	strcpy(this->text, text);

	likedBy = new Object * [MAX_LIKES];
	comment = new Comment * [MAX_COMMENTS];

	likeCount = 0;
	commentCount = 0;

	activity = nullptr;
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

const date& Post::getSharedDay() {
	return shareDay;
}

bool Post::iswithin24hours(const date& systemdate) const { //systemdate is basicallt today's date
	return shareDay.iswithin24hours(systemdate);
}


const char* Post::getName() const {
	return sharedBy->getName();
}

void Post::display() const { // for one post basic structure 
	cout << "ID: " << id;
	cout << "Text: " << text;


	cout << "Shared on: ";
	shareDay.print();

	cout << sharedBy->getName();

	if (activity != nullptr)
	{
		activity->display();
	}

	cout << "Likes: " << likeCount << endl;

	cout << "Comments: " << endl;
	if (commentCount > 0) {
		for (int i = 0; i < commentCount; i++) {
			comment[i]->display();
			cout << endl;
		}
	}
	else {
		cout << "No comments to display\n";
	}
}

Object** Post::getLiker() const {
	return likedBy;
}

int Post::getLikeCount() const {
	return likeCount;
}

void Post::setActivity(Activity* act) {
	activity = act;
}


