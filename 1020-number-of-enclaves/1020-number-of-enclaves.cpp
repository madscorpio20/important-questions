class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0 ; i<n; i++)
        {
            if(grid[0][i] == 1 && vis[0][i] == 0)
            {
                q.push(make_pair(0,i));
            }
            if(grid[m-1][i] == 1 && vis[m-1][i] == 0) 
            {
                q.push(make_pair(m-1,i));
            }
            vis[0][i] = 1;
            vis[m-1][i] = 1;
        }
        for(int i=1; i<m-1; i++)
        {
            
            if(grid[i][0] == 1 && vis[i][0] == 0)
                q.push(make_pair(i,0));
            if(grid[i][n-1] == 1 && vis[i][n-1] == 0)
                q.push(make_pair(i,n-1));
            vis[i][0] = 1;
            vis[i][n-1] = 1;
        }
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
//                 top
                if(row-1 >=0 && vis[row-1][col] == 0 && grid[row-1][col] == 1)
                {
                    q.push(make_pair(row-1,col));
                    vis[row-1][col] = 1;
                }
//                 down
               if(row+1 < m && vis[row+1][col] == 0 && grid[row+1][col] == 1)
                {
                    q.push(make_pair(row+1,col));
                    vis[row+1][col] = 1;
                }
//                 left
               if(col-1 >=0 && vis[row][col-1] == 0 && grid[row][col-1] == 1)
                {
                    q.push(make_pair(row,col-1));
                    vis[row][col-1] = 1;
                }
                // right
               if(col+1 < n && vis[row][col+1] == 0 && grid[row][col+1] == 1)
                {
                    q.push(make_pair(row,col+1));
                    vis[row][col+1] = 1;
                }
                
            }
        }
        int count = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    count++;
            }
        }
        
        return count;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};