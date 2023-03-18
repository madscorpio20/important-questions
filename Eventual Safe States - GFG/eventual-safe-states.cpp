//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int curr, vector<int> &vis, vector<int> &pathVis, vector<int> adj[])
    {
        if(vis[curr] && pathVis[curr]) return false;
        if(vis[curr]) return true;
        vis[curr] = 1;
        pathVis[curr] = 1;
        for(int i=0; i<adj[curr].size(); i++)
        {
            if(dfs(adj[curr][i],vis,pathVis,adj) == false) return false;
        }
        pathVis[curr] = 0;
        return true;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            dfs(i,vis,pathVis, adj);
        }
        vector<int> output;
        for(int i=0; i<V; i++)
        {
            if(!pathVis[i])
                output.push_back(i);
        }
        return output;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends