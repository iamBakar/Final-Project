#ifndef SOCIALNETWORKAPP_H
#define SOCIALNETWORKAPP

#include "date.h"

class User; // it should hold all users 
class Page; // pages 
class Post; // posts


class SocialNetworkApp {
protected:
	User** users; // for data storage (users, posts, pages)
	int userCount;

	Page** pages;
	int pageCount;

	Post** posts;
	int postCount;

	User* currentUser; 
	date systemdate;
	
public:
	void run(); // to run the project 

	SocialNetworkApp();
	~SocialNetworkApp();

	void setCurrentUser(const char* userID);
	void setSystemDate(int d, int m, int y);


	User* userByID(const char* id) const;
	Page* pageByID(const char* id) const;
	Post* postByID(const char* id) const;


	void viewHome() const;
	void viewTimeline() const; // is diff from page one as it locates a certain page by id and then displays it 
	void viewPage(const char* pageID) const;

};

#endif