#include "iostream"
#include "string"

#define REP(i, n) for(int i = 0; i < n; i++)
#define PARENT 20
#define SUB 15

using namespace std;

// call with (parent, x, 0, 0)
int dp[PARENT][SUB];
int numsubs(string parent, string x, int posParent, int posSub) {
	if (posParent == parent.size()) return 0;

	if (dp[posParent][posSub] != - 1) return dp[posParent][posSub];
	if (x[posSub] == parent[posParent]) {
		// matched all the way till last element, return 1
		if (posSub == x.size() - 1) return 1;
		return dp[posParent][posSub] = numsubs(parent, x, posParent + 1, posSub + 1) + numsubs(parent, x, posParent + 1, posSub);
	}
	else return dp[posParent][posSub] = numsubs(parent, x, posParent + 1, posSub);
}

int main()
{
	string parent = "aabcd";
	string x = "abc";

	for(int i = 0; i < PARENT; i++)
		for(int j = 0; j < SUB; j++) dp[i][j] = -1;

	cout << numsubs(parent, x, 0, 0) << '\n';
	return 0;
}