#include "iostream"
#include "stack"
#include "string"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

bool isBalanced(string x) {
	stack<char> s;
	char c;

	for(int i = 0; i < x.size(); i++) {
		// if starting bracket, push onto stack
		if (x[i] == '[' || x[i] == '{' || x[i] == '(') s.push(x[i]);
		else if (x[i] == ']' || x[i] == '}' || x[i] == ')') {
			c = s.top(); s.pop(); 
			// if c is a matching starting bracket, fine
			if ((x[i] == ']' && c == '[') || (x[i] == '}' && c == '{') || (x[i] == ')' && c == '(')) continue;
			else return false;
		}
	}

	if (!s.empty()) return false;
	return true;
}

int main()
{
	string x = "[{]";

	cout << isBalanced(x) << '\n';

	return 0;
}