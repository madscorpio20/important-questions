//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> dp(n,1);
       int overallMax = 1;
       for(int i=1; i<n; i++)
       {
           int maxi = 0;
           for(int j=0; j<i; j++)
           {
               if(a[j] < a[i])
               maxi = max(maxi,dp[j]);
           }
           dp[i] = maxi+1;
           overallMax = max(overallMax,dp[i]);
       }
       return overallMax;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends