#include "iostream"

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int max(int x, int y) {
	return (x > y) ? x : y;
}

int lis(int arr[], int size) {
	int ans = 1;
	int dp[size];
    for(int i = 0; i < size; i++){
        dp[i] = 1;
        for(int j = i - 1 ; j >= 0; j--){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
	return ans;
}

int main()
{
	int test[] = {4, 3, 1 ,2, 8, 3};
	int size = sizeof(test)/sizeof(test[0]);
	cout << lis(test, size) << '\n';
	return 0;
}
