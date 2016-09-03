#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

void printList(int arr[], int n) {
	for (int i = 1; i < n; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
}

void fixUp(int heapArray[], int k) {
	int temp;
	while(k > 1 && heapArray[k/2] < heapArray[k]) {
		temp = heapArray[k];
		heapArray[k] = heapArray[k/2];
		heapArray[k/2] = temp;
		k = k/2;
	}
}

void heapify(int heapArray[], int size) {
	for (int i = size - 1; i > 1; --i) {
		fixUp(heapArray, i);
	}
}

int main()
{
	/*
				1
			2		3
		4		5

		after heapify:

				5
			4		3
		1		2
	*/
	int heapArray[] = {-1, 1, 2, 3, 4, 5};
	int size =  sizeof(heapArray)/sizeof(heapArray[0]);

	printList(heapArray, size);
	heapify(heapArray, size);
	printList(heapArray, size);

	return 0;
}