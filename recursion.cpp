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

int main()
{
	cout << factorial(0) << '\n';
	cout << gcd(60, 12) << '\n';

	return 0;
}