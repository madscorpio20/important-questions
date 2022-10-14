class Solution {
public:
    int find(vector<vector<int>> &grid,int row1,int row2 ,int col1,int col2, 
             int n,vector<vector<vector<int>>> &dp)
    {
        if(row1 == n || row2 == n || col1 == n || col2 == n || 
           grid[row1][col1] == -1 || grid[row2][col2] == -1)
            return -1;
        if(dp[row1][col1][row2] !=-2)
            return dp[row1][col1][row2];
        if(row1 == n-1 && col1 == n-1 && row2 == n-1 && col2 == n-1)
            return dp[row1][col1][row2] = grid[n-1][n-1];
        
        int ans;
        if(row1 == row2 && col1 == col2)
            ans = grid[row1][col1];
        else
            ans = grid[row1][col1] + grid[row2][col2];
        int rr = find(grid,row1,row2,col1+1,col2+1,n,dp);
        int dd = find(grid,row1+1,row2+1,col1,col2,n,dp);
        int rd = find(grid,row1,row2+1,col1+1,col2,n,dp);
        int dr = find(grid,row1+1,row2,col1,col2+1,n,dp);
        int maxi = max(dd,max(rr,max(rd,dr)));
        if(maxi == -1)
            return dp[row1][col1][row2] =  -1;
        return dp[row1][col1][row2] = ans += maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int>(n,-2)));
        int ans = find(grid,0,0,0,0,n,dp);
        if(ans <= 0)
            return 0;
        return ans;
    }
};