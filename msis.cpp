#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int msis(int arr[], int n) {
	int dp[n];

	for(int i = 0; i < n; i++) dp[i] = arr[i];
	for(int i = 1; i < n; i++)
		for(int j = 0; j < i; j++)
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) dp[i] = dp[j] + arr[i];

	int max = dp[0];
	for(int i = 1; i < n; i++)
		if (dp[i] > max) max = dp[i];

	return max;
}

int main()
{
	int arr[] = {1, 101, 2, 3, 100, 90};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << msis(arr, n) << '\n';
	return 0;
}