/**
* main.cpp
* For use with 4003-703-01, Homework 2
* Winter 2012
* Department of Computer Science
* Rochester Institute of Technology
* Author: Travis Brown
*/

#include <iostream>
#include <sstream>
#include <string>
#include "Time.h"

using namespace std;

int main()
{
	string str;
	int count = 0;
	string op="+";
	do
	{
		getline(cin,str);	
		string time;
		
		/* Creating a object each time to make seconds zero 
		* for each different line
		*/
		Time t;

		/* Using istringstream to parse the input in seperate strings
		*/
		istringstream input(str);
		input.clear();

		/* This while loop runs till it keeps finding string
		*/
		while (input >> str)
		{
			/* It goes into this loop only if it is string & not any operator
			*/
			if ((str!= "+") && (str!= "-"))
			{
				count++;
				Time t1(str);
				/* This loop is for adding the two time in seconds
				*  and passing the value in string "time".
				*/
				if (op == "+" && count> 0)
				{
					t = t.add(t1);
					time = t.str();	
				}

				/* This loop is for subtracting the two time in seconds
				*  and passing the value in string "time".
				*/
				if (op == "-" && count > 0)
				{
					t = t.subtract(t1);
					time = t.str();
				}
			}

			/* It stores the operator and is later used either 
			*  for addition or subtraction.
			*/
			else
			{
				op = str;
			}
		}
		/* Displaying the final time
		*/
		cout << time << "\n";

	} while (!cin.eof());
}
