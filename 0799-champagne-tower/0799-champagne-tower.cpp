class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v(query_row+1,vector<double>(query_row+1, 0));
        
        v[0][0] = (double)poured;
        for(int i=0; i<query_row; i++){
            for(int j=0; j<=i; j++){
                double value = v[i][j] - 1;
                if(v[i][j] - 1 > (double)0){
                    double k = (double)2;
                    v[i+1][j] += value/k;
                    v[i+1][j+1] += value/k;
                }
            }
        }
        // for(int i=0; i<query_row; i++){
        //     for(int j=0; j<=i; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return v[query_row][query_glass] > 1 ?  1: v[query_row][query_glass];
    }
};