class Solution {
public:
    int bfs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
        }
        int time = 1;
        if(q.empty() || q.size() == n*n)
            return -1;
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0; i<s; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if(row+1 < n && grid[row+1][col] == 0)
                {
                    grid[row+1][col] = time;
                    q.push({row+1,col});
                }
                if(row-1 >=0 && grid[row-1][col] == 0)
                {
                    grid[row-1][col] = time;
                    q.push({row-1,col});
                }
                if(col+1 < n && grid[row][col+1] == 0)
                {
                    grid[row][col+1] = time;
                    q.push({row,col+1});
                }
                if(col-1 >=0 && grid[row][col-1] == 0)
                {
                    grid[row][col-1] = time;
                    q.push({row,col-1});
                }
            }
            time++;
        }
        return time-2;
    }
    int maxDistance(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};