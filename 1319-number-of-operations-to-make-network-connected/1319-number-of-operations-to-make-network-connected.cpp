class Solution {
public:
    class DisjointSet{
        public: 
            vector<int> parent,size;
            DisjointSet(int n){
                parent.resize(n);
                size.resize(n,1);
                for(int i=0; i<n; i++){
                    parent[i] = i;
                }
            }
            int findUltPar(int u){
                if(parent[u] == u) return u;
                return parent[u] = findUltPar(parent[u]);
            }
            void unionBySize(int u, int v){
                int ultPar_u = findUltPar(u);
                int ultPar_v = findUltPar(v);
                if(ultPar_v == ultPar_u) return;
                if(size[ultPar_u] < size[ultPar_v]){
                    parent[ultPar_u] = ultPar_v;
                    size[ultPar_v]+= size[ultPar_u];
                }else{
                    parent[ultPar_v] = ultPar_u;
                    size[ultPar_u]+= size[ultPar_v];
                }
            }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        DisjointSet dis(n);
        for(auto it: connections){
            dis.unionBySize(it[0], it[1]);
        }
        int totalComponents = 0;
        for(int i=0; i<n; i++){
            if(dis.parent[i] == i){
                totalComponents++;
            }
            
        }
        return totalComponents-1;
        
    }
};