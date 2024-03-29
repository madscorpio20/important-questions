class Solution {
public:
    int helper(vector<int> &nums, int ind, int target, vector<int> &dp){
        if(target == 0)
            return 1;
        if(dp[target]!=-1)
            return dp[target];
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(target - nums[i] >= 0){
                ans+= helper(nums,i,target-nums[i],dp);
            }
        }    
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1,0);
        // return helper(nums,0,target,dp);
        dp[0] = 1;
        for(int i=1; i<=target; i++){
            for(int j=0; j<nums.size(); j++){
                if(i - nums[j] >= 0 )
                    dp[i] += dp[i-nums[j]];
            }
        }
        return (int)dp[target];
    }
};