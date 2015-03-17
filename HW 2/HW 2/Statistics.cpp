#include "Time.h"
#include <stdexcept>
#include <iostream>
using namespace std;

template<class T>
void Statistics<T>::push(T t)
{
    cal.push_back(t.total);
}

template<class T>
void Statistics::clear()
{
    cal.clear();
}



