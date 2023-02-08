class Solution {
public:
    int find(vector<int> &nums, int ind, vector<int> &dp)
    {
        if(ind>=nums.size()-1)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int mini = 1e9;
        for(int i=1; i<=nums[ind]; i++)
        {
            mini = min(mini,find(nums,ind+i,dp)+1);
        }
        return dp[ind] = mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return find(nums,0,dp);
    }
};