#ifndef TIME_H
#define TIME_H
#include <string>
using namespace std;


class Time
{
public:
    Time();
    friend istream &operator >> (istream &in,Time &t);
    friend ostream &operator << (ostream &os,Time &item);
    void colon2();
    void colon1();
    void colon();
	int gethour();
	int getmin();
	int getsec();
	void sethour(int h);
	void setmin(int m);
	void setsec(int s);
	int gettotal();
	void settotal(int t);
private:
    int hour,min,sec,total;
    string i_time;
};

#endif

