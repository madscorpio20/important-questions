class TreeAncestor {
public:
    vector<vector<int>> v;
    TreeAncestor(int n, vector<int>& parent) {
        v.resize(18,vector<int>(n));
        v[0] = parent;
        for(int i=1; i<18; i++){
            for(int j=0; j<parent.size(); j++){
                if(v[i-1][j]!=-1)
                    v[i][j] = v[i-1][v[i-1][j]];
                else
                    v[i][j] = -1;
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        int ind = 0;
        int currNode = node;
        while(k > 0){

            if(k & 1 == 1){
                currNode = v[ind][currNode];
                if(currNode == -1)
                    break;
            }
            ind++;
            k = k>>1;
        }
        return currNode;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */