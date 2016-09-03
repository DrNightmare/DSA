#include "iostream"
#include "map"
#include "string"

#define REP(i, n) for(int i = 0; i < n; i++)
#define N 30

using namespace std;

int factorial(int x) {
	if (x == 0 || x == 1) return 1;
	return x * factorial(x - 1);
}

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

// test function that computes f(N) = (N/2) + f(N/2) in a top down manner
int computed[N];
int rel(int x) {
	if (x == 0) return 0;
	if (computed[x]) return computed[x];
	computed[x] = (x/2) + rel(x/2);
	return computed[x];
}

int computedSums[N];
int sumTillN(int n) {
	cout << "Called : " << n << '\n';
	if (n == 0) return 0;
	if (computedSums[n]) return computedSums[n];
	computedSums[n] = n + sumTillN(n - 1);
	return computedSums[n];
}

int main()
{
	cout << factorial(0) << '\n';
	cout << gcd(60, 12) << '\n';
	cout << rel(5) << '\n';

	for(int i = 0; i < N; i++) computedSums[i] = 0;
	cout << sumTillN(5);
	cout << '\n';
	cout << sumTillN(7);
	cout << '\n';

	return 0;
}