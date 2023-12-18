class Solution {
public:
    void bfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                int curr = q.front();
                q.pop();
                vis[curr] = 1;
                for(auto it: adj[curr]){
                    if(!vis[it]){
                        q.push(it);
                    }
                }
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
        for(int i=1; i<= n; i++){
            if(!vis[i]){
                cnt++;
                bfs(i, vis, adj);
            }
        }
        return cnt;
    }
};