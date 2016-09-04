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

int mincost(int arr[R][C], int m, int n) {
	if (m < 0 || n < 0) return 100;
	if (m == 0 && n == 0) return arr[0][0];
	return arr[m][n] + min(mincost(arr, m - 1, n), mincost(arr, m, n - 1), mincost(arr, m - 1, n - 1));
}

int main()
{
	/*
	1 2 3
	4 8 7
	1 5 3
	*/
	
	int arr[R][C] = {{1, 2, 3}, {4, 8, 7}, {1, 5, 3}};
	cout << mincost(arr, 2, 2) << '\n';	
	return 0;
}