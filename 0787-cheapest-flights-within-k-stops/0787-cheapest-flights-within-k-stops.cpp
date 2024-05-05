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
        vector<int> res(n,1e9);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,src,0});
        res[src] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int price = it[2];
            int node = it[1];
            int dis = it[0];
            if(dis >= k){
                continue;
            }
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjPrice = it.second;
                if(price + adjPrice < res[adjNode]){
                    res[adjNode] = price + adjPrice;
                    pq.push({dis+1,adjNode,price + adjPrice});
                }
            }
        }
        if(res[dst] == 1e9) return -1;
        return res[dst];
    }
};