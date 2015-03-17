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

istream& operator >> (istream &in,Time &t)
{
   
    in>>t.i_time;
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
    /*    string hours=t.i_time.substr(0,t.i_time.find_first_of(":"));
        istringstream hr(hours);
        hr>>t.hour;
        if(t.hour<0)
        {
            t.hour=0;
            t.sec=0;
            t.min=0;
            cout<<"hour neg-1";
            throw runtime_error ("Invalid time entry");
        }

        string mins=t.i_time.substr(t.i_time.find_first_of(":")+1,t.i_time.length());
        istringstream m(mins);
        m>>t.min;
        if(t.min<0 || t.min>60)
        {
            t.hour=0;
            t.sec=0;
            t.min=0;
            cout<<"min neg-1";
            throw runtime_error ("Invalid time entry");
        }
        t.sec=0;
      */
    }  
    else
    if(colon==0)
    {
        t.colon();
    /*    string hours=t.i_time;
        istringstream hr(hours);
        hr>>t.hour;
        t.min=0;
        t.sec=0;
      */
    }
   // t.total=(t.hour*3600)+(t.min*60)+t.sec;
   // cout<<"Time="<<t.total<<endl;
    
       return in;
}

ostream& operator<<(ostream &os, Time &item)
{
   os << item.hour<<":"<<item.min<<":"<<item.sec;
   return os;
}

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
        	
    try
    {
        if(hour<0)
        {
            hour=0;
            sec=0;
            min=0;
            throw runtime_error ("Invalid time entry");
        }

        string mins=i_time.substr(i_time.find_first_of(":")+1,i_time.find_last_of(":"));
        istringstream m(mins);
        m>>min;
        if(min<0 || min>60)
        {
            hour=0;
            sec=0;
            min=0;
            throw runtime_error ("Invalid time entry");
        }

        string secs=i_time.substr(i_time.find_last_of(":")+1,i_time.length());
        istringstream s(secs);
        s>>sec;
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

void Time::colon1()
{
        string hours=i_time.substr(0,i_time.find_first_of(":"));
        istringstream hr(hours);
        hr>>hour;
    try
    {
        if(hour<0)
        {
            hour=0;
            sec=0;
            min=0;
            throw runtime_error ("Invalid time entry");
        }

        string mins=i_time.substr(i_time.find_first_of(":")+1,i_time.length());
        istringstream m(mins);
        m>>min;
        if(min<0 ||min>60)
        {
            hour=0;
            sec=0;
            min=0;
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

void Time::colon()
{
        string hours=i_time;
        istringstream hr(hours);
        hr>>hour;
    try
    {
        if(hour<0)
        {
            hour=0;
            min=0;
            sec=0;
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