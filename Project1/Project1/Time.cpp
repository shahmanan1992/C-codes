/**
* Time.cpp
* For use with 4003-703-01, Homework 2
* Winter 2012
* Department of Computer Science
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
	return seconds += t.seconds;
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
	// variables for storing the hours and minutes of the passed string in the argument
	int hours;
	int minutes;
		
		seconds = 0;
		//Finds the position of ':' in the string
		int position = t.find(':');
		
		//hh and mm part of the passed string is calculated and stored in hh & mm variables.
		string hh = t.substr(0, position);
		string mm = t.substr(position + 1);

		//Condition for no 'hh' part is handled here
		if (t.find(':') != 0){
			istringstream hourObj(hh);
			hourObj >> hours;
			seconds += hours * 3600;
		}
		
		// minutes are read and saved in the minutes int local variable.
		istringstream minObj(mm);
		minObj >> minutes;
		
		//Seconds is calculated and saved in the seconds variable.
		seconds += minutes * 60;
		
}
