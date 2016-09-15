#include "iostream"
#include "string"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int dow(int y, int m, int d) {
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;

	return (y + y/4 - y/100 + y/400 + t[m - 1] + d) % 7;
}

int main()
{
	string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int y, m, d;
	y = 2016;
	m = 9;
	d = 15;
	cout << days[dow(y, m, d)] << '\n';
	return 0;
}