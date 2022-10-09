class Solution {
public:
    bool isIsland(vector<vector<int>>& grid,vector<vector<int>> &vis,int row,int col)
    {
        bool check = true;
        queue<pair<int,int>> q;
        q.push(make_pair(row,col));
        vis[row][col] = 1;

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                pair<int,int> front = q.front();
                q.pop();
                int currRow = front.first;
                int currCol = front.second;
                if(currRow == 0 || currCol == 0 || 
                   currRow == grid.size()-1 || currCol == grid[0].size()-1)
                {
                    check = false;
                    continue;
                }
                
                if( grid[currRow+1][currCol] == 0 && vis[currRow + 1][currCol] == 0)
                {
                    
                        vis[currRow+1][currCol] = 1;
                        q.push(make_pair(currRow+1,currCol));
                }

                if( grid[currRow-1][currCol] == 0 && vis[currRow - 1][currCol] == 0)
                {
                   
                        vis[currRow-1][currCol] = 1;
                        q.push(make_pair(currRow-1,currCol));
                }

                if( grid[currRow][currCol+1] == 0 && vis[currRow][currCol+1] == 0)
                {

                        vis[currRow][currCol+1] = 1;
                        q.push(make_pair(currRow,currCol+1));
                }

                if( grid[currRow][currCol-1] == 0 && vis[currRow][currCol-1] == 0)
                { 
                        vis[currRow][currCol-1] = 1;
                        q.push(make_pair(currRow,currCol-1));
                }
            }
        }
        return check;
       
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int islandCnt = 0;
        for(int i=1; i<m-1; i++)
        {
            for(int j=1; j<n-1; j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == 0 && isIsland(grid,vis,i,j) == true)
                {
                    islandCnt++;
                }
            }
        }
        return islandCnt;
    }
};