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
        int prev1 = 0;
        int prev0 = 0;
        int curr1 = 0;
        int curr0 = 0;
        // return find(s,0,prevOne,dp);
        for(int ind=1; ind<=s.size(); ind++)
        {
            if(s[ind-1] == '0')
            {
                curr0 = prev0;
                curr1 = min(prev0,prev1) + 1;
                
            }
            else
            {
                curr0 = prev0+1;
                curr1 = min(prev1,prev0);
            }
            prev0 = curr0;
            prev1 = curr1;
        }
        return min(curr0,curr1);
    }
};