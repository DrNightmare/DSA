#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--) {
		string x;
		cin >> x;
		if (x.size() == 1) cout << "+\n";
		else if (x[0] == '7' && x[1] == '8' && x.size() == 2) cout << "+\n";
		else if (x[x.size() - 1] == '5' && x[x.size() - 2] == '3') cout << "-\n";
		else if (x[0] == '9' && x[x.size() - 1] == '4') cout << "*\n";
		else if (x[0] == '1' && x[1] == '9' && x[2] == '0') cout << "?\n";
	}	

	return 0;
}