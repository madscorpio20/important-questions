class Solution {
public:
    int find(vector<vector<int>> &offers, int ind){
        int target = offers[ind][1] + 1;
        int s = ind+1;
        int ans = -1;
        int e = offers.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(offers[mid][0] >= target){
                e = mid-1;
                ans = mid;
            }else{
                s = mid+1;
            }
        }
        
        return ans;
    }

    int helper(vector<vector<int>> &offers, int ind,vector<int> &dp){
        if(ind >= offers.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int notTake = helper(offers, ind+1,dp);
        int take = 0;

        int nextInd = find(offers,ind);
        if(nextInd!=-1)
        {
            take = helper(offers,nextInd,dp) + offers[ind][2];
        }else{
            take = offers[ind][2];
        }
        return dp[ind] = max(take,notTake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        int ind = 0;
        vector<int> dp(offers.size(),-1);
        return helper(offers, ind,dp);
    }
};