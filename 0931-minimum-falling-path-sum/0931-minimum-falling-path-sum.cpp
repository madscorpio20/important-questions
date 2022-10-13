class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++)
            dp[i] = matrix[n-1][i];
        for(int i=n-2; i>=0; i--)
        {
            vector<int> temp(n,1e9);
            for(int j=0; j<n; j++)
            {
//                 down
                temp[j] = min(dp[j],temp[j]);
                if(j-1 >=0)
                    temp[j] = min(temp[j],dp[j-1]);
                if(j+1 <n)
                    temp[j] = min(temp[j],dp[j+1]);
                temp[j] += matrix[i][j];
            }
            dp = temp;
        }
        int mini = 1e9;
        for(int i=0; i<n; i++)
            mini = min(mini,dp[i]);
        return mini;
    }
};