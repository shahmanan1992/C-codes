/**
* Time.cpp
* For use with 4003-703-01, Homework 2
* Winter 2012
* Department OF COMPUTER Science
* Rochester Institute of Technology
* Author: Travis Brown
*/
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time(void)
{
	seconds = 0;
}

Time::Time(int _seconds)
{
	seconds = _seconds;
}

Time::Time(string t)
{
	
	setTime(t);
}

Time Time::add(Time t)
{
	return seconds+= t.seconds;
}

Time Time::subtract(Time t)
{
	return seconds -= t.seconds;

}

std::string Time::str() const
{
	/* Use ostringstream to convert from int to string. This will be covered in
	* detail in week 8
	*/
	ostringstream oss;
	oss << seconds / 3600 << ":" << setfill('0') << setw(2) << (seconds % 3600) / 60;
	return oss.str();

}

void Time::setTime(std::string t)
{
	
	/* Seperating hours from hh:mm format
	*/
	string hr = t.substr(0, t.find(":"));
	int hour;
    istringstream hours(hr);
	hours >> hour;

	/* This is used to handle grabage values 
	*  for hours i.e. the negative values
	*/
	if (hour<0 || hour>24)
	{
		hour = 0;
	}

	/* Seperating minutes from hh:mm format
	*/
	string min = t.substr(t.find(":") + 1, t.length());
	int minute;
	istringstream minutes(min);
	minutes >> minute;
	if (minute<0 || minute>60)
	{
		minute = 0;
	}

	/* Calculating seconds
	*/
	seconds = (hour * 3600) + (minute * 60);
	
}