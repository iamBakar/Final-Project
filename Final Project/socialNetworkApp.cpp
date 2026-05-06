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

