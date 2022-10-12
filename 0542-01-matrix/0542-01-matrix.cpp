class Solution {
public:
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& ans)
    {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        int time = 1;
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0; i<s; i++)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if(row+1 < m && ans[row+1][col] == -1)
                {
                    ans[row+1][col] = time;
                    q.push({row+1,col});
                }
                if(row-1 >=0 && ans[row-1][col] == -1)
                {
                    ans[row-1][col] = time;
                    q.push({row-1,col});
                }
                if(col + 1 < n && ans[row][col+1] == -1)
                {
                    ans[row][col+1] = time;
                    q.push({row,col+1});
                }
                if(col - 1 >= 0 && ans[row][col-1] == -1)
                {
                    ans[row][col-1] = time;
                    q.push({row,col-1});
                }
            }
            time++;
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        bfs(mat,ans);
        return ans;
    }
};