#ifndef _STATISTICS_H_
#define _STATISTICS_H_

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
   std::set<T> mode();

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
   void push( T t );

   /**
    * Removes all elements from the data
    */
   void clear();

};
#endif // _STATISTICS_H_
