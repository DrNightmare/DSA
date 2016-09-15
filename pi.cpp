#include "iostream"
#include "iomanip"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main()
{
	float x = 22/7.0;
	int n = 5;
	// print pi to n digits after decimal point
	cout << setprecision(n + 1) << x << '\n';	
	return 0;
}