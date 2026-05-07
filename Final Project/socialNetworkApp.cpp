#include "socialNetworkApp.h"
#include "user.h"
#include "page.h"
#include "post.h"
#include<iostream>

using namespace std;
void SocialNetworkApp::run() {
	cout << "RUNNING";
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

void SocialNetworkApp::setCurrentUser(const char* userID) {
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
	systemdate = date(d, m, y);
	cout << "Date set" << endl;
}

User* SocialNetworkApp::userByID(const char* id) const {
	for (int i = 0; i < userCount; i++) {
		if (strcmp(users[i]->getID(), id) == 0) {
			return users[i];
		}
		return nullptr;
	}
}

Post* SocialNetworkApp::postByID(const char* id) const {
	for (int i = 0; i < postCount; i++) {
		if (strcmp(posts[i]->getID(), id) == 0) {
			return posts[i];
		}
		return nullptr;
	}
}

Page* SocialNetworkApp::pageByID(const char* id) const {
	for (int i = 0; i < pageCount; i++) {
		if (strcmp(pages[i]->getID(), id) == 0) {
			return pages[i];
		}
		return nullptr;
	}
}

void SocialNetworkApp::viewPage(const char* pageID) const {
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

void SocialNetworkApp::viewHome() const {
	if (currentUser == nullptr)
	{
		cout << "No current user set." << endl;
		return;
	}

	cout << currentUser->getName() << " - Home Page" << endl;


}