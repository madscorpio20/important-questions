class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n + 1);
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        vector<int> vis(n +1, 0);
        int cnt = 0;
        // for(int i=0; i<adj.size(); i++){
        //     for(int j=0; j<adj[i].size(); j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=1; i<= n; i++){
            if(!vis[i]){
                // cout<<i<<endl;
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};