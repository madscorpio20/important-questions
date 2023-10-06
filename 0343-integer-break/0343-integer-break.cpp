class Solution {
public:
    int helper(int n, int original, vector<int> &dp){
        if(n == 1) return 1;
        if(dp[n]!=-1) return dp[n];
        int maxi = 1;
        if(n!=original)
            maxi = n;
        for(int i=1; i<=n-1; i++){
            maxi = max(helper(n-i,original,dp)*i, maxi);
        }
        return dp[n] = maxi;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,n,dp);
    }
};