class Solution {
public:
    double dfs(string curr, string dst, double product,unordered_map<string,vector<pair<string,double>>>& adj, set<string> &vis){
    // cout<<product<<endl;
    if(curr == dst){
        return product;
    }
    for(auto it: adj[curr]){
        string s = it.first;
        double val = it.second;
        if(vis.find(s) == vis.end()){
            vis.insert(s);
            double res = dfs(s,dst,product * val, adj,vis);
            if(res != -1.0){
                return res;
            }
        }
    }
    return -1.0;
}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0; i<equations.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];
            adj[u].push_back({v,values[i]});
            adj[v].push_back({u, (1.0)/values[i]});
        }
        
        vector<double> res;
        for(int i =0; i<queries.size(); i++){
            string src = queries[i][0];
            string dst = queries[i][1];
            // cout<<i<<endl;
            if(src == dst){
                // cout<<src<<endl;
                bool flag = false;
                for(auto it: adj[src]){
                    // cout<<it.second<<endl;
                    flag = true;
                    break;
                }
                // cout<<flag<<endl;
                if(flag)
                    res.push_back(1.0);
                else
                    res.push_back(-1.0);
                continue;
            }
            double product = 1.0;
            set<string> vis;
            vis.insert(src);
            double r = dfs(src,dst,product,adj,vis);
            // cout<<"res "<<r<<endl;
            res.push_back(r);

        }
        return res;
    }
};