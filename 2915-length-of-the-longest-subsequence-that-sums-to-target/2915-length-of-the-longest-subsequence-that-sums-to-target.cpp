class Solution {
public:
    int helper(int ind, vector<int> &nums, int target, vector<vector<int>> &dp){
        if(target == 0){
            return 0;
        }
        if(ind == nums.size()){
            return -1e7;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int notPick = helper(ind+1, nums, target,dp);
        
        int pick = -1;
        if(target - nums[ind] >= 0){
            pick = helper(ind+1, nums, target-nums[ind],dp);
        }
        if(pick < 0 && notPick < 0) return dp[ind][target] =  -1e7;
        return dp[ind][target] = max(pick+1, notPick);
        
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int> (target + 1, -1));
        int ans = helper(0, nums, target, dp);
        if(ans <= 0) return -1;
        return ans;
    }
};