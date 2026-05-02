#include "date.h"
#include<iostream>

using namespace std;

date:: date(): day(1),month(1),year(2000){}

date::date(int d, int m, int y): day(d), month(m), year(y){}

int date::getday() const { 
	return day;
}
int date::getmonth() const { return month; }
int date::getyear() const { return year; }

void date::print() const { cout << day << "/" << month << "/" << year << endl; }

bool date::iswithin24hours(const date& systemdate) const {
	if (year != systemdate.year || month != systemdate.month)return false;
	return (day == systemdate.day || day == systemdate.day - 1);
}

bool date::issamedayandmonth(const date& other) const {
	return (day == other.day && month == other.month);
}

int date::yeardifference(const date& other) const {
	return other.year - year;
}