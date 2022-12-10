//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int find(int wt[],int val[],int n, int ind, int W, vector<vector<int>> &dp)
    {
        if(ind == n)
        return 0;
        if(dp[ind][W]!=-1)
        return dp[ind][W];
        int notPick = find(wt,val,n,ind+1,W,dp);
        int pick = 0;
        if(W-wt[ind] >= 0)
        pick = find(wt, val, n, ind+1, W-wt[ind],dp) + val[ind];
        return dp[ind][W] = max(pick,notPick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int>(W+1,-1));
       return find( wt,val,n, 0, W,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends