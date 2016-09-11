#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)
#define N 10
#define SUM 100

using namespace std;

int dp[N][SUM];
bool isSubsetSum(int arr[], int n, int sum) {
	if (dp[n][sum] != -1) return (dp[n][sum] == 1);
	if (n == 0 && sum != 0) return false;
	if (sum == 0) return true;

	bool flag = (isSubsetSum(arr, n - 1, sum - arr[n - 1]) || isSubsetSum(arr, n - 1, sum));
	dp[n][sum] = (flag) ? 1 : 0;
	return (dp[n][sum] == 1);
}

int main()
{
	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= SUM; j++) dp[i][j] = -1;

	int arr[] = {3, 34, 10, 12, 1, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 46;

	cout << isSubsetSum(arr, n, sum) << '\n';
	return 0;
}