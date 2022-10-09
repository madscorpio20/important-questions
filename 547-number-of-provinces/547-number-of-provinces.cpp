class Solution {
public:
    void bfs(vector<vector<int>> &isConnected, vector<int> &vis, int curr)
    {
        queue<int> q;
        q.push(curr);
        vis[curr] = 1;
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                int front = q.front();
                q.pop();
                for(int j=0; j<isConnected.size(); j++)
                {
                    if(vis[j] == 0 && isConnected[front][j] == 1)
                    {
                        q.push(j);
                        vis[j] = 1;
                    }
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size()+1,0);
        int cnt = 0;
        for(int i=0; i<isConnected.size(); i++)
        {
            if(vis[i] == 0)
            {
                cnt++;
                bfs(isConnected,vis, i);
            }
        }
        return cnt;
    }
};