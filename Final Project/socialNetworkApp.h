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
	SocialNetworkApp();
	~SocialNetworkApp();

	void setCurrentUser();
	void setSystemDate(int d, int m, int y);




};

#endif