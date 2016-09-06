// solution for
// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/pair-sums/

#include "iostream"
#include "map"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main()
{
	int n, k, x;
	map<int, int> existsMap;

	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> x;
		existsMap[x]++;
	}

	bool found = false;
	for(map<int, int>::iterator it = existsMap.begin(); it != existsMap.end(); it++) {
		x = k - it->first;
		if (x + x == k && existsMap[x] <= 1) continue;
		if (existsMap.find(k - it->first) != existsMap.end()) {found = true; break;}
	}

	if (found) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}