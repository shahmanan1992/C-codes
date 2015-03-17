#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

string rem(string &word)
{
	word.erase(remove(word.begin(), word.end(), ','), word.end());
	word.erase(remove(word.begin(), word.end(), '.'), word.end());
	word.erase(remove(word.begin(), word.end(), '?'), word.end());
	word.erase(remove(word.begin(), word.end(), '!'), word.end());
	word.erase(remove(word.begin(), word.end(), ':'), word.end());
	word.erase(remove(word.begin(), word.end(), ';'), word.end());
	word.erase(remove(word.begin(), word.end(), '|'), word.end());
	word.erase(remove(word.begin(), word.end(), '-'), word.end());
	word.erase(remove(word.begin(), word.end(), '\''), word.end());
	return word;
}

void check_map(string &word)
{

}

map<string> words;
int main()
{
	fstream f;
	string s,word;
	f.open("manan.txt");
	if (f.is_open())
	{
		while (!f.eof())
		{
			getline(f, s);
			istringstream ss(s);
			while (ss >> word)
			{
				word=rem(word);
				check_map(word);
				cout << word << endl;
			}
		}
	}
	int x;
	cin >> x;
	return 0;
}
