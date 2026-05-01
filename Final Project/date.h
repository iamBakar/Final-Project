#ifndef DATE_H
#define DATE_H

class date {
private:
	int day;
	int month;
	int year;

public:
	date();

	date(int day, int month, int year);

	int getday() const;

	int getyear() const;

	int getmonth() const;

	bool iswithin24hours(const date& systemdate) const;
	bool issamedayandmonth(const date& other) const;
	int yeardifference(const date& other) const;

	void print() const;

#endif
};
