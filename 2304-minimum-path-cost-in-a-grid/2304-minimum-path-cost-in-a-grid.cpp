class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int col = 0; col <n; col++)
            dp[m-1][col] = grid[m-1][col];
        for(int row = m-2; row>=0; row--)
        {
            for(int col = 0; col<n; col++)
            {
                int mini = 1e9;
                int ind = grid[row][col];
                for(int i=0; i<n; i++)
                {
                    mini = min(mini,dp[row+1][i] + moveCost[ind][i]);
                }
                dp[row][col] = grid[row][col] + mini;
            }
        }
        int mini = 1e9;
        for(int i=0; i<n; i++)
            mini = min(mini,dp[0][i]);
        return mini;
    }
};