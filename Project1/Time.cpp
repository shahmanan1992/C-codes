#include "Time.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

Time::Time()
{
    hour=0;
    min=0;
    sec=0;
    total=0;
}
/** overloading operator >> to take input**/
istream& operator >> (istream &in,Time &t)
{
   /***to check for underflow exception*/
    try
    {
        if(in.eof())
        {
            throw underflow_error("Not enough data");
        }
    }
    catch (underflow_error &e)
    {
        cout<<e.what()<<endl;
    }  
    in>>t.i_time;
    t.hour=0;
    t.min=0;
    t.sec=0;
    int colon=0;
    for(int i=0;i < t.i_time.length();i++)
    {
        if(t.i_time.at(i)==':')
        {
            colon++;
        }
    }
    if(colon==2)
    {
        t.colon2();      
    }
    else
    if(colon==1)
    {
        t.colon1();
    }
    else
    if(colon==0)
    {
        t.colon();
    }
   
    return in;
}

/** overloading operator << to give output in time format**/
ostream& operator<<(ostream &os, Time item)
{
    return os << item.gethour()<<":"<<item.getmin()<<":"<<item.getsec();
}

/** checking if colon are two then this function gets executed**/
void Time::colon2()
{
    string hours=i_time.substr(0,i_time.find_first_of(":"));
    if (hours == "")
    {
	hour = 0;
    }
    else
    {
	istringstream hr(hours);
	hr >> hour;
    }		
    /**to check for invalid data entry**/
    try
    {
        if(hour<0)
        {
            throw runtime_error ("Invalid time entry");
        }

    string mins=i_time.substr(i_time.find_first_of(":")+1,i_time.find_last_of(":"));
    if (mins == "")
    {
        min = 0;
    }
    else
    {
        istringstream m(mins);
        m >> min;
    }
    /**to check for invalid data entry**/
    if(min<0 || min>60)
    {
        throw runtime_error ("Invalid time entry");
    }

    string secs=i_time.substr(i_time.find_last_of(":")+1,i_time.length());
    if (secs == "") 
    {
        sec = 0;
    }
    else
    {
        istringstream s(secs);
        s >> sec;
    }
    /**to check for invalid data entry**/
    if(sec<0 || sec>60)
    {
        throw runtime_error ("Invalid time entry");
    }
    }
    catch(runtime_error &e)
    {
        cerr << "Time-Runtime exception: " << e.what() << endl;
    }
    total=(hour*3600)+(min*60)+sec;
    
}

/** checking if colon is one then this function gets executed**/
void Time::colon1()
{
    string hours=i_time.substr(0,i_time.find_first_of(":"));
    if (hours == "")
    {
        hour = 0;
    }
    else
    {
        istringstream hr(hours);
        hr >> hour;
    }
    /**to check for invalid data entry**/
    try
    {
        if(hour<0)
        {
            throw runtime_error ("Invalid time entry");
        }

    string mins=i_time.substr(i_time.find_first_of(":")+1,i_time.length());
        if (mins == "")
        {
            min = 0;
        }
        else
        {
            istringstream m(mins);
            m >> min;
        }
       /**to check for invalid data entry**/
        if(min<0 ||min>60)
        {
            throw runtime_error ("Invalid time entry");
        }
    sec=0;
    }
    catch(runtime_error &e)
    {
        cerr << "Time-Runtime exception: " << e.what() << endl;
    }
    total=(hour*3600)+(min*60)+sec;

} 

/** checking if colon is none then this function gets executed**/

void Time::colon()
{
    string hours=i_time;
    if(hours == "")
    {
        hour = 0;
    }
    else
    {
        istringstream hr(hours);
        hr >> hour;
    }
    try
    {
       /**to check for invalid data entry**/
        if(hour<0)
        {
           throw runtime_error("Invalid Time entry");
        }
    min=0;
    sec=0;
    }
    catch(runtime_error &e)
    {
        cerr << "Time-Runtime exception: " << e.what() << endl;
    }
    total = hour * 3600 + min + sec;
}

int Time::gethour()
{
    return hour;
}

int Time::getmin()
{
    return min;
}

int Time::getsec()
{
    return sec;
}

void Time::sethour(int h)
{
    hour = h;
}

void Time::setmin(int m)
{
    min = m;
}

void Time::setsec(int s)
{
    sec = s;
}

int Time::gettotal()
{
    return total;
}

void Time::settotal(int t)
{
    total = t;
}
