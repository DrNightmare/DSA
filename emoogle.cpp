#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int balance = 0;
		int n, x;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> x;
			balance = (x) ? balance + 1 : balance - 1;
		}
		cout << balance << '\n';
	}	
	return 0;
}