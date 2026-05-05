#include "page.h"
#include "user.h"
#include "post.h"
#include<iostream>

using namespace std;

const int MAX_POSTS = 10;

Page::Page() {
	id = 0;
	title = nullptr;
	owner = nullptr;

	posts = new Post * [MAX_POSTS];
	postCount = 0;
}

Page::Page(int id, char* title, User* owner) : Object(id), owner(owner) {
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);

	posts = new Post * [MAX_POSTS];
	postCount = 0;
}

Page::~Page() {
	delete[] title;
	delete[] posts;
}

const char* Page::getName() const {
	return title;
}

void Page::addPost(Post* post) {
	if (postCount < MAX_POSTS) {
		posts[postCount++] = post;
	}
}

void Page::viewTimeline() const {
	cout << title;

	if (postCount == 0) {
		cout << "No posts to show\n";
		return;
	}
	else {
		for (int i = 0; i < postCount; i++) {
			posts[i]->display();
		}
	}
}