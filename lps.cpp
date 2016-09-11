#include "iostream"
#include "string"

#define REP(i, n) for(int i = 0; i < n; i++)
#define START 20
#define END 20

using namespace std;

int dp[START][END];
int lps(string x, int start, int end) {
	if (start < 0 || end > x.size() || start > end) return 0;
	if (start == end) return 1;
	if (dp[start][end] != -1) return dp[start][end];

	if (x[start] == x[end]) dp[start][end] = 2 + lps(x, start + 1, end - 1);
	else dp[start][end] = max(lps(x, start + 1, end), lps(x, start, end - 1));
	return dp[start][end];
}

int main()
{
	for(int i = 0; i < START; i++)
		for(int j = 0; j < END; j++) dp[i][j] = -1;

	string test = "BBABCBCAB";
	cout << lps(test, 0, test.size() - 1) << '\n';
	return 0;
}
