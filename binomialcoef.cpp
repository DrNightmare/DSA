#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)
#define N 20
#define K 20

using namespace std;

int dp[N][K];
int binom(int n, int k) {
	if (dp[n][k] != -1) return dp[n][k];
	cout << n << ' ' << k << '\n';
	if (k == 0 || k == n) return 1;
	dp[n][k] = binom(n - 1, k - 1) + binom(n - 1, k);
	return dp[n][k];
}

int main()
{
	for(int i = 0; i < N; i++)
		for(int j = 0; j < K; j++) dp[i][j] = -1;
	cout << binom(5, 2) << '\n';
	return 0;
}