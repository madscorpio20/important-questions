class Solution {
public:
    int minInsertions(string s) {
        string t;
        int n = s.size();
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++)
        {
            vector<int> temp(n+1,0);
            for(int j=1; j<=n; j++)
            {
                if(s[i-1] == s[n-j]) temp[j] = 1 + dp[j-1];
                else
                    temp[j] = max(dp[j], temp[j-1]);
            }
            dp = temp;
        }
        return n-dp[n];
    }
};