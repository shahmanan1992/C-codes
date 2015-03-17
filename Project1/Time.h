#ifndef TIME_H
#define TIME_H
#include <string>
using namespace std;


class Time
{
public:
    Time();
    /**overloading operator >> to take input**/
    friend istream &operator >> (istream &in,Time &t);

     /**overloading operator << to give output**/
    friend ostream &operator << (ostream &os,Time item);
    
    /**checking if colon is two then gets executed**/
    void colon2();

    /**checking if colon is one then gets executed**/
    void colon1();
  
    /**checking if colon is none then gets executed**/
    void colon();

   /**etters and setters forhours,mins and seconds**/
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

