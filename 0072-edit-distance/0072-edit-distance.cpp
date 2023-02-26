class Solution {
public:
    int find(string word1,string word2,int ind1, int ind2, vector<vector<int>> &dp)
    {
        if(ind2 < 0 && ind1 < 0)
        return 0;
        if(ind2 < 0)
        {
            return ind1+1;
        }
        if(ind1 < 0)
        return ind2 + 1;
        if(dp[ind1][ind2]!=-1)
        return dp[ind1][ind2];
        if(word1[ind1] == word2[ind2])
        {
            return dp[ind1][ind2] = find(word1,word2,ind1-1,ind2-1,dp);
        }
        else
        {
            return dp[ind1][ind2] = min(find(word1,word2,ind1-1,ind2,dp),
            min(find(word1,word2,ind1-1,ind2-1,dp),find(word1,word2,ind1,ind2-1,dp))) + 1;
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return find(word1,word2,m-1,n-1,dp);
    }
};