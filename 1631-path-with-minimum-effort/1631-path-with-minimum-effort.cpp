class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int> (n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,                                 greater<pair<int,pair<int,int>>>> pq;
        vector<int> d1 = {+1,-1,0,0};
        vector<int> d2 = {0,0,-1,+1};
        pq.push({0,{0,0}});
        effort[0][0] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            for(int i=0; i<4; i++){
                int newr = r + d1[i];
                int newc = c + d2[i];
                if(newr < m && newr>= 0 && newc < n && newc >=0){
                    int currEffort = max(dis,abs(heights[r][c] - heights[newr][newc]));
                    if(currEffort < effort[newr][newc]){
                        effort[newr][newc] = currEffort;
                        pq.push({currEffort,{newr,newc}});
                    }
                }
            }
        }
        return effort[m-1][n-1];
    }
};