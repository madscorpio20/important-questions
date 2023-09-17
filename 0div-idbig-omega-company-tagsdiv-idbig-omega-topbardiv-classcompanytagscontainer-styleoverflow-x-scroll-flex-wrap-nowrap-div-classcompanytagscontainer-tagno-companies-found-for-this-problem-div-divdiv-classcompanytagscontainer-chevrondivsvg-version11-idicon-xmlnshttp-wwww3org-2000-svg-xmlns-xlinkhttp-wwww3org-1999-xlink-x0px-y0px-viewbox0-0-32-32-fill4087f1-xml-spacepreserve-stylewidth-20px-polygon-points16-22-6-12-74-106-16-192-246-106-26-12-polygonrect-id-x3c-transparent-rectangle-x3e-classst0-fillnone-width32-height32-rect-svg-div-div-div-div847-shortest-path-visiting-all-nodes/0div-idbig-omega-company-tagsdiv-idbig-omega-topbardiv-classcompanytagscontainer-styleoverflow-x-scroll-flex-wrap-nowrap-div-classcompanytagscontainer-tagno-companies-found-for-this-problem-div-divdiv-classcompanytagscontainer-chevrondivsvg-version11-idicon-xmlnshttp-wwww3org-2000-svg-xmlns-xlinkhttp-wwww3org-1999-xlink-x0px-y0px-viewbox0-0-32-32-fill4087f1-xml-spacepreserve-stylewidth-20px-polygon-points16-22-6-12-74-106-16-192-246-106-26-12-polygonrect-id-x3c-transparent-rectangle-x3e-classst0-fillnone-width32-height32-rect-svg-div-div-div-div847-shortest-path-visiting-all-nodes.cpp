class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() <=1)
            return 0;
        int target = 0;
        int n = graph.size();
        for(int i = 0; i<n; i++){
            target = (target | 1<<i);
        }
        queue<pair<int,pair<int,int>>> q;
        set<pair<int,int>>vis;
        for(int i=0; i<n; i++){
            q.push({i,{0,1<<i}});
            vis.insert({i,1<<i});
        }
        int mini = 1e9;
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second.first;
            int mask = q.front().second.second;
            q.pop();
            if(mask == target){
                mini = min(mini,dis);
                continue;
            }
            for(int i=0; i<graph[node].size(); i++){
                int val = graph[node][i];
                if(!vis.count({val,mask | 1<<val})){
                    vis.insert({val,mask| 1<<val});
                    q.push({val,{dis+1,mask | 1<<val}});
                }
            }
        }
        return mini;
    }
};