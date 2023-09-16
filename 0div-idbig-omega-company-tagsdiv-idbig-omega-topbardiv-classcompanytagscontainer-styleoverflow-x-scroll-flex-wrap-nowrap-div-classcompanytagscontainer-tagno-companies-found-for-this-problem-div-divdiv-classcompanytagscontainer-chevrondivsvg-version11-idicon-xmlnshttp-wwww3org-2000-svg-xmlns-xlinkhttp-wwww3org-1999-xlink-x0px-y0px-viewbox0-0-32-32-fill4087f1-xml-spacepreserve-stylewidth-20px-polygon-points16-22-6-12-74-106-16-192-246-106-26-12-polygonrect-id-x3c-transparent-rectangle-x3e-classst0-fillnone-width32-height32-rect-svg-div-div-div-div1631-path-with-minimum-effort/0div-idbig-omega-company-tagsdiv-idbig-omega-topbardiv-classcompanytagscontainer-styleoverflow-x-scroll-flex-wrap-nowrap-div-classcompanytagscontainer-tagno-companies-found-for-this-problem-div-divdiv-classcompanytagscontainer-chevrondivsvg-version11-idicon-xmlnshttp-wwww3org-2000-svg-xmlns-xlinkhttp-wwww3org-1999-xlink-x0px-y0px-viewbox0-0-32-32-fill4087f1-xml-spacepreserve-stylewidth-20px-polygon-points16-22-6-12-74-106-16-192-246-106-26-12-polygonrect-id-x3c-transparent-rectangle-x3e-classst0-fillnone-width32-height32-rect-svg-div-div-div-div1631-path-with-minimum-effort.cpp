class Solution {
public:
    int currDif(int curr, int row, int col, int next_row, int next_col, vector<vector<int>>& heights){
        return max(curr, abs(heights[row][col] - heights[next_row][next_col]));
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,            greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> maxi(m,vector<int> (n,1e9));
        pq.push({0,{0,0}});
        maxi[0][0] = 0;
        while(!pq.empty()){
            int curr = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
//             up
            
            if(row-1 >= 0){
                int upMax = currDif(curr,row,col,row-1,col,heights);
                if(upMax < maxi[row-1][col]){
                    pq.push({upMax,{row-1,col}});
                    maxi[row-1][col] = upMax;
                }
                
                
            }
//             down
            if(row+1 < m){
                int downMax = currDif(curr,row,col,row+1,col,heights);
                if(downMax < maxi[row+1][col]){
                    pq.push({downMax,{row+1,col}});
                    maxi[row+1][col] = downMax;
                }
                
            }
//             left
            if(col-1 >= 0){
                int currMax = currDif(curr,row,col,row,col-1,heights);
                if(currMax < maxi[row][col-1]){
                    pq.push({currMax,{row,col-1}});
                    maxi[row][col-1] = currMax;
                }
                
            }
//             right
             if(col+1 < n){
                int currMax = currDif(curr,row,col,row,col+1,heights);
                if(currMax < maxi[row][col+1]){
                    pq.push({currMax,{row,col+1}});
                    maxi[row][col+1] = currMax;
                }
            }
        }
        
        return maxi[m-1][n-1];
    }
};