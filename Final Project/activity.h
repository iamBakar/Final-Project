#ifndef ACTIVITY_H
#define ACTIVITY_H

class Activity {
protected:
	int type;
	char* value;
	
public:
	Activity();

	Activity(int type, char* value);

	~Activity();

	void display() const;
};

#endif
