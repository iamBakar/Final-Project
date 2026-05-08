#define _CRT_SECURE_NO_WARNINGS
#include "page.h"
#include "user.h"
#include "post.h"
#include<iostream>

using namespace std;

const int MAX_POSTS = 10;

Page::Page() {
	id = nullptr;
	title = nullptr;
	owner = nullptr;

	posts = new Post * [MAX_POSTS];
	postCount = 0;
}

Page::Page(const char* id, const char* title, User* owner) : owner(owner) {
	this->id = new char[strlen(id) + 1];
	strcpy(this->id, id);

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

Post** Page::getPosts() const {
	return posts;
}

int Page::getPostCount() const {
	return postCount;
}