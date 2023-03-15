//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int k, vector<int> adj[], vector<int> &vis)
    {
        queue<pair<int,int>> q;
        q.push({k,-1});
        vis[k] = 1;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                pair<int,int> p = q.front();
                q.pop();
                int curr = p.first;
                int prev = p.second;
                for(int j=0; j<adj[curr].size(); j++)
                {
                    if(adj[curr][j] == prev )
                    continue;
                    if(vis[adj[curr][j]])
                    return true;
                    q.push({adj[curr][j],curr});
                    vis[adj[curr][j]] = 1;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                if(bfs(i,adj,vis))
                return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends