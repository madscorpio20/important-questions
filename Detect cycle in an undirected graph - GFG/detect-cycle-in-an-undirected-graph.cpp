//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs (vector<int> adj[], vector<int> &vis, int curr,int prev)
    {
        for(int i=0; i<adj[curr].size(); i++)
        {
            if(adj[curr][i]!=prev && vis[adj[curr][i]] == 1)
            return true;
            else if(adj[curr][i]!=prev)
            {
                vis[adj[curr][i]] = 1;
                if(dfs(adj,vis,adj[curr][i], curr))
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0; i<V; i++)
        {
            if(vis[i] == 0)
            {
                vis[i] = 1;
                bool check = dfs(adj,vis,i,-1);
                if(check) return check;
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