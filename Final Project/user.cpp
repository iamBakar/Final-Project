#include "user.h"
#include "post.h"
//#include "page.h"
#include<cstring>
#include<iostream>

using namespace std;

const int MAX_FRIENDS = 20;
const int MAX_POSTS = 20;
const int MAX_PAGES = 20;

User::User() {
	id = 0;
	name = nullptr;

	postCount = 0;
	likedPagesCount = 0;
	friendsCount = 0;

	friends = new User * [MAX_FRIENDS]; // max friends 
	posts = new Post * [MAX_POSTS]; // max posts shared 
	pagesLiked = new Page * [MAX_PAGES]; // max pages liked
}

User::User(int id, const char* name) : Object(id) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);


	postCount = 0;
	likedPagesCount = 0;
	friendsCount = 0;

	friends = new User * [MAX_FRIENDS];
	posts = new Post * [MAX_POSTS]; 
	pagesLiked = new Page * [MAX_PAGES]; 
}

User::~User() {
	delete[] friends;
	delete[] posts;
	delete[] pagesLiked;
	delete[] name;
}

const char* User::getName() const {  // for proper encapsulation not using directly 
	return name;
}

void User::likePage(Page* page) {
	if (likedPagesCount < MAX_PAGES) {
		pagesLiked[likedPagesCount++] = page;
	}
}

void User::viewFriendList() const {
	cout << "Name: " << name << endl;
	cout << "Friend List of" << name << " is:\n";
	
	if (friendsCount == 0) {
		cout << "No friends to display\n";
	}

	for (int i = 0; i < friendsCount; i++) {
		cout << friends[i]->getName() << endl;
	}
}

void User::addPost(Post* post) {
	if (postCount < MAX_POSTS) {
		posts[postCount++] = post;
	}
}

void User::viewProfile() const {
	cout << "User Profile\n";
	cout << "User Name: " << name;
	cout << "Posts:\n"
		;
	if (postCount == 0) {
		cout << "No posts to display!" << endl;
	}

	for (int i = 0; i < postCount; i++) {
		//cout << posts[i]->display() << endl; // polymorphism 
	}
}