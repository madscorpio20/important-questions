class Solution {
public:
    void dfs(int curr, vector<int> adj[], vector<int>&vis)
    {
        vis[curr] = 1;
        for(auto it: adj[curr])
        {
            if(!vis[it])
                dfs(it,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cnt = -1;
        vector<int> adj[n];
        if(n-1 > connections.size() )
            return -1;
        for(auto it: connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back((it[0]));
        }
        vector<int> vis(n,0);
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) 
            {
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};