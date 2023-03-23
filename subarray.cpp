//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
	public:
		//Function to find a continuous sub-array which adds up to a given number.
		vector<int> subarraySum(vector<int>A, int n, long long S)
		{

			int i = 0, j = 0, sum = 0;
			while (j < n) 
			{
				sum += A[j];
				while (sum > S) 
				{
					sum -= A[i];
					i++;
				}
				if (sum == S)
				{
					return {i + 1, j + 1};
				}
				j++;
			}
			return {-1};
		}     

};

//{ Driver Code Starts.

int main()
{
	int t=5;
	while(t--)
	{
		int n;
		long long s;
		cin>>n>>s;
		vector<int>arr(n);
		const int mx = 1e9;
		cout<<"Enter array\n";
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		Solution ob;
		vector<int>res;
		res = ob.subarraySum(arr, n, s);
		cout<<"output\n";
		for(int i = 0;i<res.size();i++)
		{
			cout<<res[i]<<" ";
		}
		cout<<endl;

	}
	return 0;
}
