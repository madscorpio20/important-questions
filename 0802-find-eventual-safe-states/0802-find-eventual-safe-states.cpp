class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &safeNodes, vector<int> &vis,vector<int> &pathVis){
        if(pathVis[node]) return false;
        if(vis[node]) return safeNodes[node];
        bool safe = true;
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it: graph[node]){
             bool curr_path_safe = dfs(it, graph, safeNodes, vis,pathVis);
            curr_path_safe == false ? safe = false : safe = safe;
        }
        pathVis[node] = 0;
        return safeNodes[node] = safe;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safeNodes(n, 1);
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, graph, safeNodes, vis, pathVis);   
            }
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            if(safeNodes[i]) res.push_back(i);
        }
        return res;
        
    }
};