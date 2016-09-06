// solution for
// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/string-permutations-1/

#include "iostream"
#include "map"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main()
{
	int t;
	string x;
	map<string, int> stringsFreq;

	cin >> t;
	int maxFreq = 0;
	while(t--) {
		cin >> x;
		stringsFreq[x]++;
		if (stringsFreq[x] > maxFreq) maxFreq = stringsFreq[x];
	}

	int sum = 0;
	for(map<string, int>::iterator it = stringsFreq.begin(); it != stringsFreq.end(); it++)
		if (it->second == maxFreq)
			sum += it->second;
	cout << sum << '\n';
	return 0;
}