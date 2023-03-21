//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
         vector<int> shortestPath(N,1e9);
        shortestPath[0] = 0;
        vector<int> indegree(N,0);
        vector<vector<pair<int,int>>> adj(N);
        for(auto it: edges)
        {
                adj[it[0]].push_back(make_pair(it[1],it[2]));
                indegree[it[1]]++;
        }
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        while(!q.empty())
        {
                pair<int,int> front = q.front();
                int  prevNode = front.first;
                int prevDistance = front.second;
                q.pop();
                for(auto it: adj[front.first])
                {
                        int node = it.first;
                        int distance = it.second;
                        indegree[node]--;
                        shortestPath[node] = min(shortestPath[node], prevDistance + distance);
                        q.push(make_pair(node,shortestPath[node]));
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