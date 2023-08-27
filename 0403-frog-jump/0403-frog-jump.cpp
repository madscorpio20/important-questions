class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1]!=1)
            return false;
        vector<vector<int>> v(n,vector<int>(n,0));
        map<int,int> m;
        for(int i=0; i<n; i++){
            m[stones[i]] = i;
        }
        v[0][0] = 1;
        v[1][1] = 1;
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                if(v[i][j] == 1){
                    if(m[stones[i] + j]){
                        int ind = m[stones[i] + j];
                        v[ind][j] = 1;
                    }
                    if(m[stones[i] + j + 1]){
                        int ind = m[stones[i] + j + 1];
                        v[ind][j+1] = 1;
                    }
                    if(m[stones[i] + j - 1]){
                        int ind = m[stones[i] + j  - 1];
                        v[ind][j-1] = 1;
                    }
                }
            }
        }
        for(int i=1; i<n; i++){
            if(v[n-1][i] == 1)
                return true;
        }
        return false;
    }
};