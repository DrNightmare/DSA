#include "iostream"
#include "string"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int max(int x, int y) {
	return (x > y)? x : y;
}

int lcs(string x, string y, int m, int n) {
	if (m == 0 || n == 0) return 0;
	if (x[m - 1] == y[n - 1]) return 1 + lcs(x, y, m - 1, n - 1);
	else return max(lcs(x, y, m - 1, n), lcs(x, y, m, n - 1));
}

int main()
{
	string x = "ABCDGH";
	string y = "AEDFHR";
	// answer is 3, 'ADH' is the LCS
	
	cout << lcs(x, y, x.size(), y.size()) << '\n';
	return 0;
}
