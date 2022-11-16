//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  int find(int arr[], int n, int sum, int curr, int ind,vector<vector<int>> &dp)
  {
      if(ind < 0)
      return curr;
      if(dp[ind][curr]!=-1)
      return dp[ind][curr];
      int notPick = find(arr,n,sum,curr,ind-1,dp);
      int Pick = 0;
      if(curr + arr[ind] <= sum)
      Pick = find(arr,n,sum,curr+arr[ind], ind-1,dp);
      return dp[ind][curr] = max(Pick,notPick);
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int total = 0;
	    for(int i=0; i<n; i++)
	    {
	        total += arr[i];
	    }
	    int sum = total /2;
	    vector<vector<int>> dp(n,vector<int> (sum+1,-1));
	    int s1 = find(arr,n,sum,0,n-1,dp);
	    int s2 = total - s1;
	    return abs(s1-s2);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends