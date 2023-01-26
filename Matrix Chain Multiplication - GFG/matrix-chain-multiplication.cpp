//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int find(int arr[], int i, int j,vector<vector<int>> &dp)
    {
        if(i==j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int mini = 1e9;
        for(int k=i; k<j; k++)
        {
            mini = min(mini, find(arr,i,k,dp) + find(arr,k+1,j,dp) + arr[i-1]*arr[j]*arr[k]);
        }
        // cout<<i<<" "<<j<<" "<<mini<<endl;
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int> (N,-1));
        return find(arr,1,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends