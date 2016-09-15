#include <iostream>
#include <string>

using namespace std;

int main() {
	string x;
	while(true) {
		cin >> x;
		if (x[0] == '*') break;
		if (x[0] == 'H') cout << "Hajj-e-Akbar\n";
		else cout << "Hajj-e-Asghar\n";
	}
	return 0;
}