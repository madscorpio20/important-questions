class Solution {
public:
    long long dfs(int curr, vector<int> adj[], vector<int> &vis)
    {
        vis[curr] = 1;
        long long cnt = 0;
        for(auto it: adj[curr])
        {
            if(!vis[it])
            {
                cnt += dfs(it,adj,vis);
            }
        }
        return cnt + 1;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long answer = 0;
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                long long cnt = dfs(i,adj,vis);
                answer += cnt*(n-cnt);
            }
        }
        return answer/2;
    }
};