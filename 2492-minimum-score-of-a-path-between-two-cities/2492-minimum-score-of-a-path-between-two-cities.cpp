class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> vis(n+1,0);
        vector<pair<int,int>> adj[n+1];
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        queue<int> q;
        q.push(1);
        int mini = 1e9;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            vis[curr] = 1;
            for(auto it: adj[curr])
            {
                mini = min(mini,it.second);
                if(vis[it.first])
                    continue;
                q.push(it.first);
            }
        }
        return mini;
    }
    
};