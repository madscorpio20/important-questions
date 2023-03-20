//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> newAdj[V];
        vector<int> indegree(V,0);
        for(int i=0; i<V; i++)
        {
            for(auto it: adj[i])
            {
                newAdj[it].push_back(i);
                indegree[i]++;
            }
        }
       
        queue<int> q;
        for(int i=0; i<V; i++)
        {
            if(indegree[i]== 0)
            q.push(i);
        }
        
        vector<int> ans(V,0);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans[curr] = 1;
            for(auto it: newAdj[curr])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        vector<int> output;
        for(int i=0; i<V; i++)
        {
            if(ans[i] == 1)
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