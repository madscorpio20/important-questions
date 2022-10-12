class Solution {
public:
    int mod = 1000000007;
    int find(vector<vector<int>> &grid, int k, int row, int col, int sum,                   vector<vector<vector<int>>> &dp)
    {
        sum += grid[row][col]%mod;
        if(dp[row][col][sum%k]!=-1)
            return dp[row][col][sum%k];
        if(row == grid.size()-1 && col == grid[0].size()-1)
        {
            if(sum%k == 0)
                return dp[row][col][sum%k] = 1;
            return dp[row][col][sum%k] = 0;
        }
        int down = 0;
        int right = 0;
        if(row+1 < grid.size())
            down = find(grid,k,row+1,col,sum,dp);
        if(col+1 < grid[0].size())
            right = find(grid,k,row,col+1,sum,dp);
        return dp[row][col][sum%k] = (down + right)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (k,-1)));
        return find(grid,k,0,0,0,dp);
    }
};