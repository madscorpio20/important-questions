class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>> &vis, int row, int col)
    {
        int cnt = 1;
        if(row+1 < grid.size() && grid[row+1][col] && vis[row+1][col] == 0)
        {
            vis[row+1][col] = 1;
            cnt+=dfs(grid, vis,row+1,col);
        }
        if(row-1 >=0 && grid[row-1][col] && vis[row-1][col] == 0)
        {
            vis[row-1][col] = 1;
            cnt+= dfs(grid, vis,row-1,col);
        }
        if(col+1 < grid[0].size() && grid[row][col+1] && vis[row][col+1] == 0)
        {
            vis[row][col+1] = 1;
            cnt+= dfs(grid, vis,row,col+1);
        }
        if(col-1 >=0 && grid[row][col-1] && vis[row][col-1] == 0)
        {
            vis[row][col-1] = 1;
            cnt += dfs(grid, vis,row,col-1);
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    vis[i][j] = 1;
                    maxi = max(maxi,dfs(grid,vis,i,j));
                }
            }
        }
        return maxi;
    }
};