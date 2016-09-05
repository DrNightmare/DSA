#include "iostream"
#include "string"
#include "map"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

bool isAnagram(string x, string y) {
	if (x.size() != y.size()) return false;

	// create frequency maps
	map<char, int>map1, map2;
	for(string::iterator it = x.begin(); it != x.end(); it++) map1[*it]++; 
	for(string::iterator it = y.begin(); it != y.end(); it++) map2[*it]++;

	// for every char in map1, check if frequency is same in map2
	// if not, return false. else return true
	for(map<char, int>::iterator it = map1.begin(); it != map1.end(); it++)
		if (it->second != map2[it->first]) return false;

	return true;
}

int main()
{
	cout << isAnagram("nightmare", "marenight") << '\n';
	cout << isAnagram("nightmare", "marenights") << '\n';
	return 0;
}