#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)
#define R 3
#define C 3

using namespace std;

int min(int x, int y) {
	return (x < y) ? x : y;
}

int min(int x, int y, int z) {
	return min(min(x, y), z);
}

int mincostDP[R][C];
int mincost(int arr[R][C], int m, int n) {
	if (mincostDP[m][n] != -1) return mincostDP[m][n];
	cout << m << " " << n << '\n';
	if (m < 0 || n < 0) return 100;
	if (m == 0 && n == 0) return arr[0][0];
	mincostDP[m][n] = arr[m][n] + min(mincost(arr, m - 1, n), mincost(arr, m, n - 1), mincost(arr, m - 1, n - 1));
	return mincostDP[m][n];
}

int main()
{
	/*
	1 2 3
	4 8 10
	1 2 3
	*/
	for(int i = 0; i < R; i++)
		for(int j = 0; j < R; j++) mincostDP[i][j] = -1;
	int arr[R][C] = {{1, 2, 3}, {4, 8, 10}, {1, 2, 3}};
	cout << mincost(arr, 2, 2) << '\n';	
	return 0;
}