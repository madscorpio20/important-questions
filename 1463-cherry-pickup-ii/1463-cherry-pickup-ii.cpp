class Solution {
public:
    int find(vector<vector<int>>& grid, int row, int col1, 
             int col2,vector<vector<vector<int>>> &dp)
    {
        if(col1<0 || col2<0 || col1 >= grid[0].size() || col2 >= grid[0].size())
            return -1;
        if(dp[row][col1][col2]!=-1)
            return dp[row][col1][col2];
        if(row == grid.size()-1)
        {
            if(col1 == col2)
                return dp[row][col1][col2] = grid[row][col1];
            return dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
        }
        int ans = 0;
        if(col1 == col2)
            ans = grid[row][col1];
        else
            ans = grid[row][col1] + grid[row][col2];
        int maxi = -1;
        for(int i=-1; i<=1; i++)
        {
            for(int j=-1; j<=1; j++)
            {
                maxi = max(maxi, find(grid,row+1,col1+i,col2+j,dp));
            }
        }
        return dp[row][col1][col2] = maxi + ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return find(grid,0,0,n-1,dp);
    }
};