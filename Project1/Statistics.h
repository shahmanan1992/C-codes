#ifndef _STATISTICS_H_
#define _STATISTICS_H_
#include "Time.h"
#include <list>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <deque>
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
   typedef T value_type;
   
private:
   /**List is used because we can insert values easily..Random access is not possible but
   * it provides various functions making code easier to write.**/
    list<T> cal; 
};

/**Comparator function written for comparing < values**/
bool total_compare(Time t1, Time t2)
{
        return t1.gettotal() < t2.gettotal();
}

/**Calculating mean**/
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
    /**setting objects hour,minutes and seconds **/
    a.sethour(sum / 3600) ;
    if(a.gethour()!=0)
    {
        sum=sum%(a.gethour()*3600);
    }
    a.setmin(sum / 60) ;
    if(a.getmin()!=0)
    {
        sum=sum%(a.getmin()*60);
    }
    a.setsec(sum);
    return a;
}

/**calculating median**/
template<class T>
T Statistics<T>::median()
{
    T a;
    int med = 0;
    int size = cal.size();
    cal.sort(total_compare);
    typename list<T>::iterator iter=cal.begin();

    /**checking if value is even,then returns sum of two of them**/	
    if ((size % 2) == 0)
    {	
        advance(iter, (size / 2)-1);
	int value = (iter->gettotal());
	iter++;
	med=(value + iter->gettotal()) / 2;
        a.sethour(med / 3600);
        if(a.gethour()!=0)
        {
            med = med % (a.gethour() * 3600);
        }
        a.setmin(med / 60);
        if(a.getmin()!=0)
        {
            med = med % (a.getmin() * 60);
        }
            a.setsec(med);
            return a;
    }
    /**checking if value is odd then returns middle value**/
    else
    {

            advance(iter, (size / 2));
            return *iter;
    }
}

/**checks for value if its found in deque or not**/
bool found(int number,deque<int> contain)
{
    for(int i=0;i<contain.size();i++)
    {
        if(number==contain.at(i))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

/*void findmax(int a[][],int l)
{
    deque<int> c;
    int number=a[0][1];
    for(int j=1;j<l;j++)
    {
        if(number<a[j][1])
        {
          number=a[j][1];
        }
    }
    for(int j=0;j<l;j++)
    {
       if(number==a[j][1])
       {
           contain.push_back(number);
       }
    }
    convert(c);
        
}
*/
/*void convert(deque<int> c)
{
    Time a;
    int sum=0;
    for(int i=0;i<c.size();i++)
    {
        sum=c.at(i);
        a.sethour(sum/3600);
        if(a.gethour()!=0)
        {
            sum=sum%(a.gethour()*3600);
        }
        a.setmin(sum/60);
        if(a.getmin()!=0)
        {
            sum=sum%(a.getmin()*60);
        }
        a.setsec(sum);
        cout<<a.gethour<<":"<<a.getmin()<<":"<<a.getsec()<<"\t";
    }
}
*/

/**calculating mode**/
template<class T>
set<T> Statistics<T>::mode()
{
    set<T> a;
    int size=cal.size();
    int arr[20][20];
    int i=0;
    bool unique=true;
    deque<int> contain;
    for(typename list<T>::iterator iter=cal.begin();iter!=cal.end();iter++)
    {
        arr[i][0]=iter->gettotal();
        arr[i][1]=1;
        i++;
    }
    for(int j=0;j<size-1;j++)
    {
        for(int k=j+1;k<size-1;k++)
        {  
            if(arr[j][0]==arr[k][0])
            {   
                unique=false;
                break;
            }
        }
    }
    if(unique==true)
    {
        return a;
    }
    else
    {   
        int count=0;
        for(int j=0;j<sizeof(arr)/sizeof(*arr);j++)
        {
            int number=arr[j][0];
            if(!found(number,contain))
            {
                contain.push_back(number);
            }
            for(int m=0;m<(sizeof(arr)/sizeof(*arr));m++)
            {
                if((arr[m][0]==number) && (j!=m))
                {
                    arr[j][1]++;
                }
            }      
        }
    }
   // findmax(arr,i);
    return a;
}

/**calculating minimum value**/
template<class T>
T Statistics<T>::min()
{   
    typename list<T>::iterator iter;
    iter = (std::min_element(cal.begin(), cal.end(), total_compare));
    return *iter;
}

/**calculating max value**/
template<class T>
T Statistics<T>::max()
{
    T a;
    typename list<T>::iterator iter;
    iter=(std::max_element(cal.begin(), cal.end(),total_compare));
    return *iter;
}
/**pushing the value in list**/
template<class T>
void Statistics<T>::push(T t)
{
    cal.push_back(t);
}
/**clears the complete list**/
template<class T>
void Statistics<T>::clear()
{
    cal.erase(cal.begin(),cal.end());
}



#endif // _STATISTICS_H_
