#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)
#define N 31
using namespace std;

int dp[N];
int numWays(int n) {
	if (n < 0) return 0;
	if (n == 0 || n == 1) return 1;

	if (dp[n] != -1) return dp[n];
	dp[n] = numWays(n - 1) + numWays(n - 2);
	return dp[n]; 
}

int main()
{
	for(int i = 0; i <= 30; i++) dp[i] = -1; 
	cout << numWays(4) << '\n';
	return 0;
}