class Solution {
public:
    class Disjoint{
        public : 
            map<pair<string,string>,pair<string,string>> parent;
            map<pair<string,string>,int> siz;
            pair<string,string> findUltPar(pair<string,string> node){
                if(parent[node] == node) return node;
                return parent[node] = findUltPar(parent[node]);
            }
            
            void unionBySize(pair<string,string> u, pair<string,string> v){
                if(parent.find(u) == parent.end()){
                    parent[u] = u;
                    siz[u] = 1;
                }
                if(parent.find(u) == parent.end()){
                    parent[v] = v;
                    siz[v] = 1;
                }
                pair<string,string> ultPar_u = findUltPar(u);
                pair<string,string> ultPar_v = findUltPar(v);
                 
                
                // cout<<u.first<< " "<<v.first<<" "<<parent[ultPar_u].first<<" "<<parent[ultPar_v].first<<endl;
                // cout<<siz[ultPar_u]<<" "<<siz[ultPar_v]<<endl;
                if(ultPar_u == ultPar_v) return;
                if(siz[ultPar_u] < siz[ultPar_v]){
                    parent[ultPar_u] = ultPar_v;
                    siz[ultPar_v] += siz[ultPar_u];
                }else{
                     parent[ultPar_v] = ultPar_u;
                    siz[ultPar_u] += siz[ultPar_v];
                }
                // cout<<u.first<< " "<<v.first<<" "<<parent[ultPar_u].first<<" "<<parent[ultPar_v].first<<endl;
                // cout<<siz[ultPar_u]<<" "<<siz[ultPar_v]<<endl;
            } 
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        Disjoint dis;
        for(int i=0; i<accounts.size(); i++){
            if(dis.parent.find({accounts[i][1],accounts[i][0]}) == dis.parent.end()){
                dis.parent[{accounts[i][1],accounts[i][0]}] = {accounts[i][1],accounts[i][0]};
                dis.siz[{accounts[i][1],accounts[i][0]}] = 1;   
            }
            for(int j=2; j<accounts[i].size(); j++){
                dis.unionBySize({accounts[i][j],accounts[i][0]},{accounts[i][j-1],accounts[i][0]});
            }
        }
        map<pair<string,string> , vector<string>> mp;
        for(auto it: dis.parent){
            string child = it.first.first;
            pair<string,string> parent = dis.findUltPar(it.first);
            mp[parent].push_back(child);
        }
        vector<vector<string>> res;
        
        for(auto it: mp){
            vector<string> curr = it.second;
            sort(curr.begin(), curr.end());
            curr.insert(curr.begin(),it.first.second);
            res.push_back(curr);
        }
        // for(auto it : dis.parent){
        //     cout<<it.first.first<<" "<<it.second.first<<" "<<endl;
        // }
        // cout<<endl;
        // for(auto it: dis.siz){
        //     cout<<it.first.first<<" "<<it.second<<" "<<endl;
        // }
        return res;
        
        
    }
};