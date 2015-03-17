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

Time::Time( void )
{
   seconds = 0;
}

Time::Time( int _seconds )
{
   seconds = _seconds;
}

Time::Time( string t )
{
   setTime( t );
}

Time Time::add( Time t )
{
   return seconds += t.seconds;
}

Time Time::subtract( Time t )
{
   return seconds -= t.seconds;
}

std::string Time::str() const
{
   /* Use ostringstream to convert from int to string. This will be covered in
    * detail in week 8
    */
   ostringstream oss;
   oss << seconds / 3600 << ":" << setfill('0') << setw(2) << ( seconds % 3600 ) / 60;
   return oss.str();

}

void Time::setTime( std::string t )
{
   /* Your code here */
}
