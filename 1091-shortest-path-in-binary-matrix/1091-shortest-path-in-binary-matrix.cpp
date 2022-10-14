class Solution {
public:
    int bfs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int time = 2;
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0; i<s; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if(row == n-1 && col == n-1)
                    return grid[row][col];
                if(row+1 < n && grid[row+1][col] == 0)
                {
                    q.push({row+1,col});
                    grid[row+1][col] = time;
                }
                if(row-1 >=0 && grid[row-1][col] == 0)
                {
                    q.push({row-1,col});
                    grid[row-1][col] = time;
                }
                if(col+1 < n && grid[row][col+1] == 0)
                {
                    q.push({row,col+1});
                    grid[row][col+1] = time;
                }
                if(col-1 >= 0 && grid[row][col-1] == 0)
                {
                    q.push({row,col-1});
                    grid[row][col-1] = time;
                }
//                 diagonal
                if(row+1 < n && col+1<n && grid[row+1][col+1] == 0)
                {
                    q.push({row+1,col+1});
                    grid[row+1][col+1] = time;
                }
                if(row+1 < n && col-1 >=0 && grid[row+1][col-1] == 0)
                {
                    q.push({row+1,col-1});
                    grid[row+1][col-1] = time;
                }
                if(row-1 >=0 && col-1 >=0  && grid[row-1][col-1] == 0)
                {
                    q.push({row-1,col-1});
                    grid[row-1][col-1] = time;
                }
                if(row-1>=0 && col+1 < n && grid[row-1][col+1] == 0)
                {
                    q.push({row-1,col+1});
                    grid[row-1][col+1] = time;
                }
            }
            time++;
        }
        return -1;
        
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};