//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int curr, vector<int> &vis, vector<pair<int,int>> adj[], stack<int> &s)
    {
        if(vis[curr]) return;
        vis[curr] = 1;
        for(auto it: adj[curr])
        {
            dfs(it.first,vis,adj,s);
        }
        s.push(curr);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(auto it: edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> shortestPath(N,1e9);
        vector<int> vis(N,0);
        stack<int> s;
        for(int i=0; i<N; i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,s);
            }
        }
        shortestPath[0] = 0;
        while(s.top()!=0)
        s.pop();
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            for(auto it: adj[node])
            {
                shortestPath[it.first] = 
                min(shortestPath[it.first],shortestPath[node] + it.second);
            }
        }
        for(int i=0; i<N; i++)
        {
            if(shortestPath[i] >= 1e9)
            shortestPath[i] = -1;
        }
        
        return shortestPath;
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends