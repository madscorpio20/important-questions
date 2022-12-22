//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int find(int price[], int n, vector<int> &dp)
    {
        if(n == 0)
        return 0;
        int maxi = price[n-1];
        if(dp[n]!=-1)
        return dp[n];
        for(int i=1; i<n; i++)
        {
            maxi = max(maxi,find(price,n-i,dp) + price[i-1]);
        }
        return dp[n] = maxi;
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int> dp(n+1,-1);
        return find(price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends