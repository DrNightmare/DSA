#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)
#define N 30

using namespace std;

struct Item{
	int size; int val;

	Item(int s, int v) { size = s; val = v;};
};

Item items[4] = {Item(3, 50), Item(6, 30), Item(4, 40), Item(5, 10)};

int computedCaps[20];
int knap(int cap) {
	int n, space, max, t;
	max = 0;
	n = 4;
	for(int i = 0; i < n; i++)
		if ((space = cap - items[i].size) >= 0){
			if (!computedCaps[space]) computedCaps[space] = knap(space);
			if ((t = computedCaps[space] + items[i].val) > max)
				max = t;
		}
	return max;
}

int main()
{
	for(int i = 0; i < N; i++) computedCaps[i] = 0;
	cout << knap(12);
	cout << '\n';
	return 0;
}