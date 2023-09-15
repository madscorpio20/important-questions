class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(points.size(),0);
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty()){
            pair<int,int> curr = pq.top();
            int wt = curr.first;
            int node = curr.second;
            pq.pop();
            if(vis[node] ){
                continue;
            }
            vis[node] = 1;
            for(int i=0; i<points.size(); i++){
                if(!vis[i]){
                    pq.push({abs(points[node][0]-points[i][0]) +abs(points[node][1]-points[i][1]),i});
                }
            }
            sum += wt;
        }
        return sum;
    }
};