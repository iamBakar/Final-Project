#define _CRT_SECURE_NO_WARNINGS
#include "socialNetworkApp.h"
#include "user.h"
#include "page.h"
#include "post.h"
#include "comment.h"
#include "memory.h"
#include "activity.h"
#include<iostream>
#include <fstream>
#include <sstream>


using namespace std;

// asked ai to make run according to the sample output 

void SocialNetworkApp::run()
{
	loadPages("Pages.txt");
	loadUsers("Users.txt");
	loadPosts("Posts.txt");
	loadComments("Comments.txt");

	// ✅ 2. Set system date
	setSystemDate(15, 11, 2017);

	// ✅ 3. Set current user
	setCurrentUser("u7");

	if (currentUser == nullptr)
	{
		cout << "Program terminated.\n";
		return;  
	}

	cout << "\n--------------------------------------------------\n";

	// ✅ View friend list (recommended test)
	cout << "Command: View Friend List\n";
	currentUser->viewFriendList();

	cout << "\n--------------------------------------------------\n";

	// ✅ View Home
	cout << "Command: View Home\n";
	viewHome();

	cout << "\n--------------------------------------------------\n";

	// ✅ View Timeline (profile)
	cout << "Command: View Timeline\n";
	viewTimeline();

	cout << "\n--------------------------------------------------\n";

	// ✅ View Page
	cout << "Command: View Page (p1)\n";
	viewPage("p1");

	cout << "\n--------------------------------------------------\n";

	// ✅ View specific post
	cout << "Command: View Post (post4)\n";
	viewPost("post4");

	cout << "\n--------------------------------------------------\n";

	// ✅ View liked list
	cout << "Command: View Liked List (post5)\n";
	viewLikedList("post5");

	cout << "\n--------------------------------------------------\n";

	// ✅ Like a post
	cout << "Command: Like Post (post5)\n";
	likePost("post5");

	// show updated likes
	viewLikedList("post5");

	cout << "\n--------------------------------------------------\n";

	// ✅ Comment on post
	cout << "Command: Post Comment\n";
	postComment("post4", "Good Luck for your Result");

	// verify comment
	viewPost("post4");

	cout << "\n--------------------------------------------------\n";

	// ✅ See Memories
	cout << "Command: See Your Memories\n";
	seeYourMemories();

	cout << "\n--------------------------------------------------\n";

	// ✅ Share Memory
	cout << "Command: Share Memory\n";
	shareMemory("post10", "Never thought I will be specialist in this field...");

	// ✅ Show updated timeline with memory
	viewTimeline();

	cout << "\n--------------------------------------------------\n";
}

SocialNetworkApp::SocialNetworkApp() {
	users = nullptr;
	pages = nullptr;
	posts = nullptr;
	currentUser = nullptr;
	
	userCount = 0;
	pageCount = 0;
	postCount = 0;
}


SocialNetworkApp::~SocialNetworkApp()
{
	for (int i = 0; i < userCount; i++)
		delete users[i];

	for (int i = 0; i < pageCount; i++)
		delete pages[i];

    for (int i = 0; i < postCount; i++)
        delete posts[i];

	delete[] users;
	delete[] pages;
	delete[] posts;
}

void SocialNetworkApp::setCurrentUser(const char* userID) { // #1
	currentUser = userByID(userID);

	if (currentUser != nullptr) {
		cout << currentUser->getName() << " is active user now." << endl;
	}
	else {
		cout << "No user found\n";
		return;
	}
}

void SocialNetworkApp::setSystemDate(int d, int m, int y) {
	cout << "Command: Set current System Date ";
	systemdate = date(d, m, y);
	cout << d << " " << m << " " << y << " " << endl;
	cout << "System Date: " << d << "/" << m << "/" << y << "/" << endl;
}

User* SocialNetworkApp::userByID(const char* id) const {
	for (int i = 0; i < userCount; i++) {
		if (strcmp(users[i]->getID(), id) == 0) {
			return users[i];
		}
	}
	return nullptr;
}

Post* SocialNetworkApp::postByID(const char* id) const {
	for (int i = 0; i < postCount; i++) {
		if (strcmp(posts[i]->getID(), id) == 0) {
			return posts[i];
		}
	}
	return nullptr;
}

Page* SocialNetworkApp::pageByID(const char* id) const {
	for (int i = 0; i < pageCount; i++) {
		if (strcmp(pages[i]->getID(), id) == 0) {
			return pages[i];
		}
	}
	return nullptr;
}

void SocialNetworkApp::viewPage(const char* pageID) const { // #10
	Page* page = pageByID(pageID);
	if (page != nullptr) {
		page->viewTimeline();
	}
	else {
		cout << "Page not found!" << endl;
		return;
	}
}

void SocialNetworkApp::viewTimeline() const{
	if (currentUser != nullptr) { // we alr have a currentuser as found above 
		cout << currentUser->getName() << " - Timeline" << endl;
		currentUser->viewProfile();
	}
	else {
		cout << "No current user!" << endl;
		return;
	}
}

void SocialNetworkApp::viewHome() const { // #2
	if (currentUser == nullptr) {
		cout << "No current user set." << endl;
		return;
	}

	cout << currentUser->getName() << " - Home Page" << endl;

	User** friends = currentUser->getFriends();   // for friends posts
	int friendCount = currentUser->getFriendCount();

	for (int i = 0; i < friendCount; i++) {
		Post** posts = friends[i]->getPosts();
		int postCount = friends[i]->getPostCount();

		for (int j = 0; j < postCount; j++) {
			if (posts[j]->iswithin24hours(systemdate)) //  filtering for last 24 hrs only 
			{
				posts[j]->display();
			}
		}
	}


	Page** pages = currentUser->getLikedPages();  // for posts of pages liked 
	int pageCount = currentUser->getLikedPageCount();

	for (int i = 0; i < pageCount; i++) {
		Post** posts = pages[i]->getPosts();
		int postCount = pages[i]->getPostCount();

		for (int j = 0; j < postCount; j++)
		{
			if (posts[j]->iswithin24hours(systemdate)) // filtering as asked 
			{
				posts[j]->display();
			}
		}
	}
}

void SocialNetworkApp::likePost(const char* postID) { // #3
	if (currentUser == nullptr) {
		cout << "No current user." << endl;
		return;
	}

	Post* post = postByID(postID);

	if (post == nullptr) {
		cout << "Post not found." << endl;
		return;
	}

	post->addLike(currentUser);   // adds current user as liker
}


void SocialNetworkApp::viewLikedList(const char* postID) const
{
	if (currentUser == nullptr) {
		cout << "No current user." << endl;
		return;
	}

	Post* post = postByID(postID);

	if (post == nullptr) {
		cout << "Post not found." << endl;
		return;
	}

	Object** likedBy = post->getLiker();  
	int count = post->getLikeCount(); 

	for (int i = 0; i < count; i++)
	{
		cout << likedBy[i]->getID() << " - "
			<< likedBy[i]->getName() << endl;
	}
}

void SocialNetworkApp::postComment(const char* postID, const char* text) { // #5
	if (currentUser == nullptr) {
		cout << "No current user" << endl;
		return;
	}

	Post* post = postByID(postID);

	if (post == nullptr) {
		cout << "Post not found." << endl;
		return;
	}

	Comment* comment = new Comment(text, currentUser);
	post->addComment(comment);
}


void SocialNetworkApp::viewPost(const char* postID) const // #6
{
	if (currentUser == nullptr) {
		cout << "No current user" << endl;
		return;
	}

	Post* post = postByID(postID);

	if (post == nullptr) {
		cout << "Post not found." << endl;
		return;
	}

	post->display();
}

void SocialNetworkApp::seeYourMemories() const
{
	if (currentUser == nullptr)
	{
		cout << "No current user set." << endl;
		return;
	}

	cout << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago.\n";
	cout << "On this Day\n";

	Post** posts = currentUser->getPosts();
	int count = currentUser->getPostCount();

	for (int i = 0; i < count; i++)
	{
		const date& postDate = posts[i]->getSharedDay();

		if (postDate.issamedayandmonth(systemdate) &&
			postDate.getyear() < systemdate.getyear())
		{
			int years = postDate.yeardifference(systemdate);

			cout << years << " Years Ago\n";
			cout << "--- ";
			posts[i]->display();
		}
	}
}


void SocialNetworkApp::shareMemory(const char* postID, const char* text)
{
	if (currentUser == nullptr) {
		cout << "No current user set." << endl;
		return;
	}

	Post* original = postByID(postID);

	if (original == nullptr) {
		cout << "Post not found." << endl;
		return;
	}

	// now we will create a new copy of this original post and give it unique id 
	// used ai to learn this and to now how to make a new memory using sprintf method 

	char newID[10];
	sprintf_s(newID, "post%d", postCount + 1);

	Memory* mem = new Memory(
		newID,
		currentUser,
		text,
		systemdate, // current day
		original // orig or old post
	);

	currentUser->addPost(mem);
	posts[postCount++] = mem;
}

void SocialNetworkApp::loadPages(const char* filename)
{
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "File not opening!\n";
	}
	else {
		cout << "pages.txt File opened!" << endl;
	}

	file >> pageCount;
	file.ignore();

	pages = new Page * [pageCount];

	for (int i = 0; i < pageCount; i++)
	{
		char id[20], title[100];

		file >> id;
		file.getline(title, 100);

		char* cleanTitle = title;
		if (cleanTitle[0] == ' ') // removes leading spaces 
			cleanTitle++;

		pages[i] = new Page(id, cleanTitle, nullptr);
	}

	file.close();
}

void SocialNetworkApp::loadUsers(const char* filename)
{
	ifstream file(filename);

	if (!file.is_open()) {
		cout << "FAILED to open Users.txt\n";
	}
	else {
		cout << "Users.txt opened successfully\n";
	}

	file >> userCount;

	/*if (file.fail())
	{
		cout << "Reading userCount failed!\n";
	}*/

	file.ignore(1000, '\n');
	users = new User * [userCount];

	// ✅ PASS 1: CREATE USERS
	for (int i = 0; i < userCount; i++)
	{
		char id[20], firstName[50], lastName[50];

		file >> id;
		file >> firstName >> lastName;   // ✅ reads full name correctly

		char fullName[100];
		strcpy(fullName, firstName);
		strcat(fullName, " ");
		strcat(fullName, lastName);

		users[i] = new User(id, fullName);

		file.ignore(1000, '\n');
	}

	file.close();

	// PASS 2: LINK FRIENDS + PAGES
	file.open(filename);
	file >> userCount;

	for (int i = 0; i < userCount; i++)
	{
		char id[20], firstName[50], lastName[50];

		file >> id;
		file >> firstName >> lastName;

		char temp[20];

		// ✅ FRIENDS
		file >> temp;
		while (strcmp(temp, "-1") != 0)
		{
			User* f = userByID(temp);
			if (f != nullptr)
				users[i]->addFriend(f);

			file >> temp;
		}

		// ✅ PAGES
		file >> temp;
		while (strcmp(temp, "-1") != 0)
		{
			Page* p = pageByID(temp);
			if (p != nullptr)
				users[i]->likePage(p);

			file >> temp;
		}
	}
	file.close();
}

void SocialNetworkApp::loadPosts(const char* filename)
{
	ifstream file(filename);

	if (!file.is_open()) {
		cout << "File not opening!\n";
		return;
	}
	else {
		cout << "posts.txt file opened!" << endl;
	}

	file >> postCount;
	posts = new Post * [postCount];

	for (int i = 0; i < postCount; i++)
	{
		int type;
		char postID[20];

		file >> type >> postID;

		int day, month, year;
		file >> day >> month >> year;

		date d(day, month, year);

		file.ignore();

		char text[200];
		file.getline(text, 200);

		Activity* act = nullptr;

		// ✅ Activity (if exists)
		if (type == 2)
		{
			int aType;
			char value[100];
			file >> aType;
			file.getline(value, 100);

			char* clean = value;
			if (clean[0] == ' ')
				clean++;

			act = new Activity(aType, clean);
		}

		char sharedID[20];
		file >> sharedID;

		// ✅ Find sharer
		Object* sharedBy = userByID(sharedID);
		if (sharedBy == nullptr)
			sharedBy = pageByID(sharedID);

		// ✅ Create post
		Post* p = new Post(postID, sharedBy, text, d);

		// ✅ Attach activity
		if (act != nullptr)
			p->setActivity(act);

		// ✅ ADD TO GLOBAL LIST
		posts[i] = p;

		// ✅ ADD TO OWNER (USER or PAGE)
		User* u = userByID(sharedID);
		if (u != nullptr)
			u->addPost(p);

		Page* pg = pageByID(sharedID);
		if (pg != nullptr)
			pg->addPost(p);

		char likerID[20];
		file >> likerID;

		while (strcmp(likerID, "-1") != 0)
		{
			Object* liker = userByID(likerID);
			if (liker == nullptr)
				liker = pageByID(likerID);

			if (liker != nullptr)
				p->addLike(liker);

			file >> likerID;
		}
	}

	file.close();
}


void SocialNetworkApp::loadComments(const char* filename)
{
	ifstream file(filename);

	if (!file.is_open()) {
		cout << "File not opening!\n";
		return;
	}
	else {
		cout << "comments.txt file opened!" << endl;
	}

	int commentCount;
	file >> commentCount;

	for (int i = 0; i < commentCount; i++)
	{
		char commentID[20], postID[20], userID[20], text[200];

		file >> commentID;
		file >> postID;
		file >> userID;

		file.getline(text, 200);

		// remove leading space
		char* cleanText = text;
		if (cleanText[0] == ' ')
			cleanText++;

		// find post
		Post* post = postByID(postID);
		if (post == nullptr)
			continue;

		// find commenter (user or page)
		Object* commenter = userByID(userID);
		if (commenter == nullptr)
			commenter = pageByID(userID);

		if (commenter == nullptr)
			continue;

		// create comment
		Comment* c = new Comment(cleanText, commenter);

		// attach to post
		post->addComment(c);
	}

	file.close();
}
