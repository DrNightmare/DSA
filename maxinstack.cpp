#include "iostream"
#include "stack"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main()
{
	stack<int> s1, s2;
	int arr[] = {3, 4, 2, 1, 5};
	int size = sizeof(arr)/sizeof(arr[0]);

	int max = arr[0];
	for(int i = 0; i < size; i++) {
		s1.push(arr[i]);
		if (arr[i] > max) max = arr[i];
		s2.push(max);
	}

	for(int i = 0; i < size; i++) {
		cout << "Max in stack : " << s2.top() << '\n';
		cout << "Removing : " << s1.top() << ' ' << '\n';
		s1.pop();
		s2.pop();
	}

	return 0;
}