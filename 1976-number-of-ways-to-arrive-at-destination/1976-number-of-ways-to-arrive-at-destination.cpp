class Solution {
public:
    #define ll long long
    ll mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> adj(n);
        for(auto it: roads){
            ll u = (ll)it[0];
            ll v = (ll)it[1];
            ll wt = (ll)it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<ll> wt(n,1e18);
        vector<ll> cnt(n,0);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push({0,0});
        wt[0] = 0;
        cnt[0] = 1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ll nodeWt = it.first;
            ll node = it.second;
            for(auto it: adj[node]){
                ll adjNode = it.first;
                ll adjWt = it.second;
                if(adjWt + nodeWt < wt[adjNode]){
                    wt[adjNode] = adjWt + nodeWt;
                    cnt[adjNode] = cnt[node];
                    pq.push({adjWt + nodeWt, adjNode});
                }
                else if(adjWt + nodeWt == wt[adjNode]){
                    cnt[adjNode] = (cnt[adjNode]%mod + cnt[node]%mod)%(mod); 
                    cnt[adjNode] = cnt[adjNode]%mod;
                    
                }
                
            }
            
        }
        return cnt[n-1]%mod;
    }
};