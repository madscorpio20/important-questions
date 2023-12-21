class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> & vis, vector<int> &res, vector<int> &pathVis){
        vis[node] = 1;
        for(auto it: graph[node]){
            if(!pathVis[it] && vis[it]) continue;
            if(pathVis[it]){
                return true;
            }
            pathVis[it] = 1;
            bool flag = dfs(it, graph, vis, res, pathVis);
            if(flag) return true;
            pathVis[it] = 0;
         }
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> res;
        vector<int> pathVis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                pathVis[i] = 1;
                bool flag = dfs(i, graph, vis, res, pathVis);
                if(!flag)
                pathVis[i] = 0;
            }
        }
        for(int i=0; i<n; i++){
            if(pathVis[i] == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};