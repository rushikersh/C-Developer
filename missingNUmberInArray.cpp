#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
	public:
		int MissingNumber(vector<int>& array, int n) 
		{
			int expectedSum = n * (n + 1) / 2;
			int actualSum = accumulate(array.begin(), array.end(), 0);
			cout<<"expectedSum = "<<expectedSum<<endl;
			cout<<"actualSum = "<<actualSum<<endl;
			return expectedSum - actualSum;
		}

};


int main() 
{
	int t;
	int n;
	cin >> n;

	vector<int> array(n - 1);
	for (int i = 0; i < n - 1; ++i) 
		cin >> array[i];

	Solution obj;
	cout << obj.MissingNumber(array, n) << "\n";
	return 0;
}
