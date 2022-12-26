//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string S1, string S2) 
	{ 
	    // Your code goes here
	    int n = S1.size();
	    int m = S2.size();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(S1[i-1] == S2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int maxi = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                maxi = max(maxi,dp[i][j]);
            }
        }
        return m - maxi + n - maxi;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends