class Solution {
public:
    int bfs(vector<vector<int>> &grid, queue<pair<int,int>> &q, vector<vector<int>> &vis){
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        while(!q.empty()){
            int siz = q.size();
            time++;
            for(int i=0; i<siz; i++){
                int x = q.front().first;
                int y = q.front().second;
                // cout<<x<<" "<<y<<" "<<time<<endl;
                q.pop();
                if(x-1 >= 0 && !vis[x-1][y] && grid[x-1][y] == 1){
                    vis[x-1][y] = 1;
                    q.push({x-1,y});
                }
                if(x+1 < m && !vis[x+1][y] && grid[x+1][y] == 1){
                    vis[x+1][y] = 1;
                    q.push({x+1, y});
                }
                if(y-1 >=0 && !vis[x][y-1] && grid[x][y-1] == 1 ){
                    vis[x][y-1] = 1;
                    q.push({x,y-1});
                }
                if(y+1 < n && !vis[x][y+1] && grid[x][y+1] == 1){
                    vis[x][y+1] = 1;
                    q.push({x,y+1});
                }
            }
        }
        return time > 0 ? time-1 : time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        int time = bfs(grid, q, vis);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};