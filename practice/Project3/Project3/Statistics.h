#ifndef _STATISTICS_H_
#define _STATISTICS_H_
#include "Time.h"
#include <list>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

template< class T >
class Statistics
{
public:
   /**
    * Calculate the mean (average) of the data entered.
    *
    * @return the mean of the data pushed into our data set
    */
   T mean();

   /**
    * Calculate the median (middle element when the data is sorted)
    *
    * @return the mode of the data pushed into our data set
    */
   T median();

   /**
    * Calculate the mode (most common element). 
    *
    * @return a set of the most common elements.  This can be the empty set if
    * there is a uniform distribution
    */
   set<T> mode();

   /**
    * Get the value of the smallest element
    *
    * @return the minimum value of the data pushed in 
    */
   T min();

   /**
    * Get the value of the largest element
    *
    * @return the maximum value of the data pushed in 
    */
   T max();

   /**
    * Add an element to our data set
    *
    * @param t Element to add to our data
    */
    void push(T t);

   /**
    * Removes all elements from the data
    */
   void clear();

   //bool compare_total(T &t1,T &t2);
  // bool operator > (Time &t);
private:
   list<T> cal; 
};

template<class T>
T Statistics<T>::mean()
{
    int sum=0;
    T a;
	for (typename list<T>::iterator i = cal.begin(); i != cal.end(); ++i)
    { 
       sum=sum+ ((i->gethour())*3600)+((i->getmin())*60)+(i->getsec());
    }
    sum=sum/cal.size();
	a.sethour(sum / 3600) ;
    sum=sum%(a.gethour()*3600);
	a.setmin(sum / 60) ;
    sum=sum%(a.getmin()*60);
    a.setsec(sum);
    return a;
}

template<class T>
T Statistics<T>::median()
{
	T a;
	int med = 0;
	int size = cal.size();
	typename list<T>::iterator iter=cal.begin();
	cal.sort(compare_total);
	
	if ((size % 2) == 0)
	{
		advance(iter, (size / 2)-1);
		int value = (iter->gettotal());
		iter++;
		med=(value+iter->gettotal()) / 2;
	}
	else
	{
		advance(iter, size / 2);
		med=iter->gettotal();
	}
	a.sethour(med / 3600);
	med = med % (a.gethour() * 3600);
	a.setmin(med / 60);
	med = med % (a.getmin() * 60);
	a.setsec(med);
	return a;
}

bool found(int number, int contain[], int length)
{
	for (int i = 0; i<length; i++ )
	{
		if (number == contain[i])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}


template<class T>
set<T> Statistics<T>::mode()
{
	set<T> a;
	int size = cal.size();
	int arr[20];
	int i = 0;
	bool unique = true;
	for (typename list<T>::iterator iter = cal.begin(); iter != cal.end(); iter++)
	{
		arr[i] = iter->gettotal();
		i++;
	}
	for (int j = 0; j<size - 1; j++)
	{
		for (int k = j + 1; k<size - 1; k++)
		{
			if (arr[j] == arr[k])
			{
				unique = false;
			}
		}
	}
	if (unique == false)
	{
		return a;
	}
	else
	{
		int contain[50];
		int count = 0;
		for (int j = 0; j < sizeof(arr) / size(*arr); j++)
		{
			int number = arr[j][0];
			if (!found(number, contain, 20))
			{
				contain[count]++;
				for (int m = 0; i < sizeof(arr) / sizeof(*arr); m++)
				{
					if (arr[m] == number && j != m)
					{
						arr[i][1]++;
					}
				}
			}
		}
		return a;
	}


}

template<class T>
T Statistics<T>::min()
{   
	T a;
	list<T>::iterator iter;
	iter = (std::min_element(cal.begin(), cal.end(), compare_total));
	return *iter;
}

template<class T>
T Statistics<T>::max()
{
	T a;
	list<T>::iterator iter;
	iter=(std::max_element(cal.begin(), cal.end(),compare_total));
	return *iter;
}

template<class T>
void Statistics<T>::push(T t)
{
    cal.push_back(t);
}

template<class T>
void Statistics<T>::clear()
{
    cal.erase(cal.begin(),cal.end());
}

//template<class T>
bool compare_total(Time &t1, Time &t2)
{
	return t1.gettotal() < t2.gettotal();
}

/*template<class T>
bool Statistics<T>::operator > (T &t) 
{ 
	if (this.gettotal()->compareTo(t.gettotal()) > 0) 
	return true; 
	else 
	return false; 
}*/

#endif // _STATISTICS_H_
