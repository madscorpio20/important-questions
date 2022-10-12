class Solution {
public:
    int mod = 1000000007;
    int find(int n,int k,int target, vector<vector<int>> &dp)
    {
        if(dp[n][target]!= -1)
            return dp[n][target];
        if(n==1)
        {
            if(target <= k)
                return dp[1][target] = 1;
            return dp[1][target] = 0;
        }
        int sum = 0;
        for(int i=1; i<=k; i++)
        {
            if(i<target)
            {
               sum = (sum%mod + find(n-1,k,target-i,dp)%mod)%mod;
            }
        }
        return dp[n][target] = sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return find(n,k,target,dp);
    }
};