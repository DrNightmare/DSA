#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int longestBitonic(int arr[], int n) {
	int LIS[n], LDS[n];

	for(int i = 0; i < n; i++) LIS[i] = LDS[i] = 1;

	for(int i = 1; i < n; i++)
		for(int j = 0; j < i; j++)
			if (arr[i] >= arr[j] && LIS[i] < (LIS[j] + 1))
				LIS[i] = LIS[j] + 1;
			else if (arr[i] < arr[j] && LDS[i] < (LDS[j] + 1))
				LDS[i] = LDS[j] + 1;

	int max = LIS[0] + LDS[0] - 1;
	for(int i = 1; i < n; i++)
		if ((LIS[i] + LDS[i] - 1) > max)
			max = LIS[i] + LDS[i] - 1;

	return max;
}

int main()
{
	int arr[] = {80, 60, 30, 40, 20, 10};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << longestBitonic(arr, n) << '\n';
	return 0;
}