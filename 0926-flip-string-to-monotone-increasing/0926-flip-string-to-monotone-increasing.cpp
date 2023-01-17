class Solution {
public:
    int find(string s, int ind, bool prevOne, vector<vector<int>> &dp)
    {
        if(ind == s.size())
            return 0;
        if(dp[ind][prevOne]!=-1)
            return dp[ind][prevOne];
        if(prevOne)
        {
            if(s[ind] == '0')
                return dp[ind][prevOne] = 1 + find(s,ind+1,prevOne,dp);
            else
                return dp[ind][prevOne] = find(s,ind+1,prevOne,dp);
        }
        else
        {
            if(s[ind] == '0')
                return dp[ind][prevOne] = min(find(s,ind+1,prevOne,dp),1+find(s,ind+1,true,dp));
            else
                return dp[ind][prevOne] = min(1+find(s,ind+1,prevOne,dp),find(s,ind+1,true,dp));
        }
    }
    int minFlipsMonoIncr(string s) {
        bool prevOne = false;
        vector<vector<int>> dp(s.size()+1,vector<int>(2,0));
        // return find(s,0,prevOne,dp);
        for(int ind=1; ind<=s.size(); ind++)
        {
            if(s[ind-1] == '0')
            {
                dp[ind][0] = dp[ind-1][0];
                dp[ind][1] = min(dp[ind-1][0],dp[ind-1][1]) + 1;
            }
            else
            {
                dp[ind][0] = dp[ind-1][0]+1;
                dp[ind][1] = min(dp[ind-1][1],dp[ind-1][0]);
            }
        }
        return min(dp[s.size()][0],dp[s.size()][1]);
    }
};