#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

void printList(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
}

void twoColors(int arr[], int n) {
	int low = 0;
	int high = n - 1;
	int temp;

	while(low <= high) {
		if (arr[low] == 0) low++;
		else { temp = arr[low]; arr[low] = arr[high]; arr[high--] = temp;}
	}
}

void threeColors(int arr[], int n) {
	int low = 0;
	int high = n - 1;
	int temp;
	int mid = 0;

	while(mid <= high) {
		if (arr[mid] == 0) { temp = arr[low]; arr[low++] = arr[mid]; arr[mid++] = temp;}
		else if (arr[mid] == 1) mid++;
		else { temp = arr[high]; arr[high--] = arr[mid]; arr[mid] = temp;};
	}
}

int main()
{
	int arr[] = {0, 1, 0, 1, 1, 0, 0, 0};
	int size =  sizeof(arr)/sizeof(arr[0]);

	printList(arr, size);
	twoColors(arr, size);
	printList(arr, size);

	int arr2[] = {2, 1, 0, 2, 1, 0, 0, 0};
	int size2 =  sizeof(arr2)/sizeof(arr2[0]);

	printList(arr2, size);
	threeColors(arr2, size);
	printList(arr2, size);

	return 0;
}