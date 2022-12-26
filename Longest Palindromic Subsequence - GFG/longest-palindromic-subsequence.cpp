//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        int siz = A.size();
        vector<vector<int>> dp(siz+1,vector<int> (siz+1,0));
        string B = "";
        for(int i = siz-1; i>=0; i--)
        {
            B+= A[i];
        }
        for(int i=1; i<=siz; i++)
        {
            for(int j=1; j<=siz; j++)
            {
                if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[siz][siz];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends