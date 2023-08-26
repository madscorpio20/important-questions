class Solution {
public:
//     int helper(vector<vector<int>> &pairs,int ind, int prev, vector<vector<int>> &dp){
//         if(ind == pairs.size())
//             return 0;
//         if(dp[ind][prev+1]!=-1)
//             return dp[ind][prev+1];
//         int notPick = helper(pairs,ind+1,prev,dp);
//         int pick = 0;
        
//         if(prev == -1 || pairs[ind][0] > pairs[prev][1]){
//             pick = helper(pairs,ind+1,ind,dp) + 1;
//         }
//         return dp[ind][prev+1] = max(pick,notPick);
//     }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        // vector<vector<int>> dp(pairs.size(),vector<int>(pairs.size()+1,0));
        // return helper(pairs,0,-1,dp);
        int n = pairs.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            int prev = 0;
            for(int j=0; j<i; j++){
                if(pairs[j][1] < pairs[i][0])
                {
                    prev = dp[j];
                }
            }
            dp[i] = prev + 1;
        }
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};