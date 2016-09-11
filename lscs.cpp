#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int lscs(int arr[], int n) {
	int dp[n];

	for(int i = 0; i < n; i++) dp[i] = arr[i];

	for(int i = 1; i < n; i++)
		if (arr[i] + dp[i - 1] > dp[i]) dp[i] = arr[i] + dp[i - 1];

	int maxsum = 0;
	for(int i = 0; i < n; i++) if (dp[i] > maxsum) maxsum = dp[i];
	return maxsum;
}

int main()
{
	int arr[] = {-2, 3, -4, -1, 2, 1, 5, -3};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << lscs(arr, n) << '\n';
	return 0;
}