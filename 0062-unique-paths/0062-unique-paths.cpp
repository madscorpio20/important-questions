class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m,vector<int> (n,0));
        v[m-1][n-1] = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i+1 < m){
                    v[i][j] += v[i+1][j];
                }
                if(j+1 < n){
                    v[i][j] += v[i][j+1];
                }
            }
        }
        return v[0][0];
    }
};