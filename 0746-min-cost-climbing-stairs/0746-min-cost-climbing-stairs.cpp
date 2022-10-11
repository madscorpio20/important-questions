class Solution {
public:
    int findMinCost(vector<int> &cost, vector<int> &dp, int curr)
    {
        if(curr <0)
            return 0;
        if(dp[curr]!=-1)
            return dp[curr];
        if(curr == cost.size())
            return dp[curr] = min(findMinCost(cost,dp,curr-1),findMinCost(cost,dp,curr-2));
        return dp[curr] = min(findMinCost(cost,dp,curr-1),
                            findMinCost(cost,dp,curr-2))+cost[curr];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int s = cost.size();
        vector<int> dp(s+1,-1);
        return findMinCost(cost,dp,s);
    }
};