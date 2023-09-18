class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<mat.size(); i++){
            int cnt = 0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 1) cnt++;
            }
            if(i < k)
                pq.push({cnt,i});
            else if(pq.top().first > cnt){
                pq.pop();
                pq.push({cnt,i});
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};