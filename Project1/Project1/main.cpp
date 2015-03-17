/**
* main.cpp
* For use with 4003-703-01, Homework 2
* Winter 2012
* Department of Computer Science
* Rochester Institute of Technology
* Author: Travis Brown
*/
#include "Time.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
	string str;
	string break_string;
	do
	{
		getline(cin, str);

		//Instance of time and temp variable is initialized to differentiate operators
		Time t;
		int temp = 0;

		//First string is read and add function is called to add with zero
		istringstream iss(str);
		iss >> break_string;
		t.add(Time(break_string));

		while (iss){
			iss >> break_string;
			if (break_string == "+"){
				temp = 1;
			}
			else if (break_string == "-"){
				temp = 2;
			}
			if (temp==1){
				iss >> break_string;
				t.add(Time(break_string));
			}
			else if(temp==2){
				iss >> break_string;
				t.subtract(Time(break_string));
			}
			//Resetting the value of temp
			temp = 0;
		}
			//prints the final time output
			cout << t.str() << endl;
		
	} while (!cin.eof());

}