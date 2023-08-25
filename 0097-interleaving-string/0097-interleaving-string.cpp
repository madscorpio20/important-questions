class Solution {
public:
    bool helper(string s1, string s2, string s3, int ind1, int ind2, int ind3, vector<vector<int>> &dp){
        if(ind1 == s1.size() && ind2 == s2.size() && ind3 == s3.size()){
            return true;
        }
        if(ind1 == s1.size() && ind3 == s3.size())
            return false;
        if(ind2 == s2.size() && ind3 == s3.size())
            return false;
        if(ind1 == s1.size() && ind2 == s2.size())
            return false;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        bool first = false;
        bool second = false;
        if(ind1 < s1.size() && s1[ind1] == s3[ind3]){
            first = helper(s1,s2,s3,ind1+1,ind2,ind3+1,dp);
        }
        if(ind2 < s2.size() && s2[ind2] == s3[ind3]){
            second = helper(s1,s2,s3,ind1,ind2+1,ind3+1,dp);
        }
        return dp[ind1][ind2] = first || second;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int ind1 = 0;
        int ind2 = 0;
        int ind3 = 0;
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1,-1));
        return helper(s1,s2,s3,ind1,ind2,ind3, dp);
    }
};