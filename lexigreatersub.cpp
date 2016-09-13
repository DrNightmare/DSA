#include "iostream"
#include "string"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

// prints lexicographically greater substring
void printResult(string x) {
	int minIndex = 0;
	for(int i = 0; i < x.size(); i++)
		if (x[i] > x[minIndex]) {
			char temp = x[i]; x[i] = x[minIndex]; x[minIndex] = temp;
			cout << x << '\n';
			break;
		}
		else minIndex = i;
}

int main()
{
	string test = "abcd";
	printResult(test);
	return 0;
}