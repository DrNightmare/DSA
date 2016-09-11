#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)
#define N 251
#define M 51

using namespace std;

// for m, pass index of last element in coins array
int dp[N][M];
int numWays(int n, int coins[], int m) {
	// cout << n << ' ' << m << '\n';
 	if (n < 0 || m < 0) return 0;
	if (n == 0) return 1;

	if (dp[n][m] != -1) return dp[n][m];

	// number of ways by using mth coin + number of ways by not using mth coin 
	dp[n][m] = numWays(n - coins[m], coins, m) + numWays(n, coins, m - 1);
	return dp[n][m];
}

int main()
{
	int coins[] = {1, 5, 10, 25};
	int n = 100;
	int m = sizeof(coins)/sizeof(coins[0]);

	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++) dp[i][j] = -1;

	cout << numWays(n, coins, m - 1) << '\n';	
	return 0;
}