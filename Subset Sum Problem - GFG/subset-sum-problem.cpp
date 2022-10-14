//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

bool find(vector<int> arr, int sum, int ind, vector<vector<int>> &dp)
{
    if(sum < 0 || ind <0)
    return false;
    if(dp[ind][sum]!=-1)
    return dp[ind][sum];
    if(sum - arr[ind] == 0)
    return dp[ind][sum] = true;
    bool notPick = find(arr,sum,ind-1,dp);
    bool pick = find(arr,sum-arr[ind],ind-1,dp);
    return dp[ind][sum] = pick  | notPick;
}
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return find(arr,sum,arr.size()-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends