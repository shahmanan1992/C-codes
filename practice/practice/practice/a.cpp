#include <iostream>
using namespace std;

class Date
{
public:
	void p();
private:
	int month;
	int year;
	int day;
};
void Date::p() {
	//Date date; 
	year = 2000;
	cout << year;
}
int main() {
	Date d;
	d.p();
}