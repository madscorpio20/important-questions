class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dis(m, vector<int> (n, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        dis[0][0] = 0;
        vector<int> r = {-1,+1,0,0};
        vector<int> c = {0,0,-1,+1};
        while(!pq.empty()){
            auto it = pq.top();
            int hi = it[0];
            int row = it[1];
            int col = it[2];
            pq.pop();
            for(int i=0; i<4; i++){
                int adjRow = row + r[i];
                int adjCol = col + c[i];
                if(adjRow >= 0 && adjCol >=0 && adjRow < m && adjCol < n){
                    int diff = max(hi,abs(heights[row][col] - heights[adjRow][adjCol]));
                    if(diff < dis[adjRow][adjCol]){
                        dis[adjRow][adjCol] = diff;
                        pq.push({diff,adjRow,adjCol});
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
};