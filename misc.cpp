#include "iostream"
#include "map"
#include "string"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int maxProfit(int prices[], int n) {
	int maxprofit = 0;

	for(int i = 1; i < n; i++)
		if (prices[i] > prices[i - 1])
			maxprofit += (prices[i] - prices[i - 1]);

	return maxprofit;
}

int moreThanNbyK(int arr[], int n, int k) {
	map<int, int> counts;
	for(int i = 0; i < n; i++)
		counts[arr[i]]++;
	int x = n/k;
	for(map<int, int>::iterator it = counts.begin(); it != counts.end(); it++)
		if (it->second > x)
			cout << it->first << ' ';
}

bool isUnique(string x) {
	map <char, int> seen;
	for(string::iterator it = x.begin(); it != x.end(); it++) {
		if (seen[*it] == 1) return 0;
		seen[*it]++;
	}
	return 1;
}

int main()
{
	int prices[] = {1, 7, 2, 3, 6, 7, 6, 7};
	cout << maxProfit(prices, 8);
	cout << '\n';

	int testArray[] = {3, 1, 2, 2, 1, 2, 3, 3};
	moreThanNbyK(testArray, 8, 4);
	cout << '\n';

	string x = "abcdefghijk";
	cout << isUnique(x);
	cout << '\n';
	return 0;
}