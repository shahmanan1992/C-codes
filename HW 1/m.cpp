#include <iostream>
using namespace std;

int main()
{
string str1 = "string1";
 string str2 = "string2";
 string *ptr1 = new string("string3"); 
string *ptr2; 
string &ref1(str1);
// • Which ones are valid? 1 h ll


*ptr1 = ref1; 
ptr2 = &ref1; 
string &ref2(*ptr1); 
cout<<ref2<<"\n";
string **ptr3;
ptr3 = &ptr1;
cout<<**ptr3<<"\n";

}
