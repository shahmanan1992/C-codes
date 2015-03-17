#include <iostream> 
#include <fstream> 
using namespace std;

void displayStudent(Student st) 
{ 
	cout << st.getFirstName() << endl; 
	cout << st.getLastName() << endl; 
	cout << st.getScore() << endl; 
}
int main() 
{
	fstream binio;
	binio.open("obj.dat", ios::out | ios::binary); 
	Student st1("John", "Smith", 90); 
	Student st2("Eric", "Jones", 85); 
	binio.write(reinterpret_cast<char *>(&st1), sizeof(Student)); 
	binio.write(reinterpret_cast<char *>(&st2), sizeof(Student)); 
	binio.close();
	binio.open("obj.dat", ios::in | ios::binary); 
	Student st3; binio.read(reinterpret_cast<char *>(&st3), sizeof(Student)); 
	displayStudent(st3); 
	binio.read(reinterpret_cast<char *>(&st3), sizeof(Student)); 
	displayStudent(st3); 
	binio.close();
}