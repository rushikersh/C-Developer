#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
	long long currSum = 0, maxSum = INT_MIN;
	for(int i = 0; i < n; i++)
	{
		currSum += arr[i];
		maxSum = max(maxSum, currSum);
		if(currSum < 0)
		{
			currSum = 0;
		}
	}
	return maxSum;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << maxSubarraySum(arr, n) << endl;
	return 0;
}
