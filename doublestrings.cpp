// solution for
// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/xsquare-and-double-strings-1/

#include "iostream"
#include "string"
#include "map"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main()
{
	string x;
	map<char, int> charFreq;

	int t;
	cin >> t;

	while(t--) {
		cin >> x;

		bool possible = false;
		for(int i = 0; i < x.size(); i++) {
			charFreq[x[i]]++;
			if (charFreq[x[i]] == 2) {possible = true; break;}
		}

		if (possible) cout << "Yes\n";
		else cout << "No\n";

		charFreq.clear();
	}
	return 0;
}