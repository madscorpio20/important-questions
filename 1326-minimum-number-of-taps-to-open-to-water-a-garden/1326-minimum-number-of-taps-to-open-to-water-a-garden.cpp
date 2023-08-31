class Solution {
public:
    int helper(vector<int> &v, int ind,vector<int> &dp){
        if(ind == v.size()-1)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int mini = 1e9;
        for(int i=ind+1; i<=v[ind]; i++){
            mini = min(mini,helper(v,i,dp) + 1);
        }
        // cout<<ind<<" "<<mini<<" "<<ranges[i]<<endl;
        return dp[ind] = mini;
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<int> v(n+1,0);
        for(int i=0; i<n+1; i++){
            int mini = i - ranges[i];
            if(mini < 0)
                mini = 0;
            int maxi = i + ranges[i];
            if(maxi > n){
                maxi = n;
            }
            v[mini] = max(v[mini],maxi);
        }
        vector<int> dp(n+1,-1);
        int ans = helper(v,0,dp);
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};