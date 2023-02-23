//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(int curr, vector<vector<int>> &adj, vector<int> &vis)
    {
        queue<int> q;
        q.push(curr);
        vis[curr] = 1;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                int front = q.front();
                q.pop();
                for(int j=0 ;j < adj[front-1].size(); j++)
                {
                  if(adj[front-1][j]!=0 && !vis[j+1])
                  {
                      vis[j+1] = 1;
                      q.push(j+1);
                  }
                  
                }
            }
            
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cnt = 0;
        vector<int> vis(V+1,0);
        for(int i=1; i<=V; i++)
        {
            if(vis[i] == 0)
            {
                cnt++;
                bfs(i,adj,vis);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends