#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main()
{
	int nums[] = {1, 2, 3, 4, 5};
	int size = sizeof(nums)/sizeof(nums[0]);

	int leftProd[size], rightProd[size];

	leftProd[0] =  1;
	for(int i = 1; i < size; i++) {
		leftProd[i] = leftProd[i - 1] * nums[i - 1];
	}

	rightProd[size - 1] = 1;
	// i = 3
	// 
	for(int i = size - 2; i >= 0; i--) {
		rightProd[i] = rightProd[i + 1] * nums[i + 1];
	}

	cout << "Product of other numbers for each number in array: \n";
	for(int i = 0; i < size; i++) {
		cout << leftProd[i] * rightProd[i] << ' ';
	}
	cout << '\n';
	return 0;
}