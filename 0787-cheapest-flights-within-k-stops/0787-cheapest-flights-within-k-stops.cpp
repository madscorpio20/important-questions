class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        k++;
        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int price = it[2];
            adj[u].push_back({v,price});
        }
        vector<vector<int>> res(n, vector<int> (k+1,1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,src,0});
        for(int i=0; i<=k; i++){
            res[src][i] = 0;
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int price = it[0];
            int node = it[1];
            int dis = it[2];
            if(dis >= k){
                continue;
            }
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjPrice = it.second;
                if(price + adjPrice < res[adjNode][dis+1]){
                    res[adjNode][dis+1] = price + adjPrice;
                    pq.push({price + adjPrice,adjNode,dis+1});
                }
            }
        }
        int mini = 1e9;
        for(int i=0; i<=k; i++){
            mini = min(mini, res[dst][i]);
        }
        if(mini == 1e9) return -1;
        return mini;
    }
};