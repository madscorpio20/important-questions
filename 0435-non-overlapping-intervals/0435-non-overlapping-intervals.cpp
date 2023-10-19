class Solution {
public:
    
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> dp(intervals.size());
        int cnt = 1;
        int prev = intervals[0][1];
        for(int i=1;i<intervals.size(); i++){
            if(intervals[i][0] >= prev){
                cnt++;
                prev = intervals[i][1];
            }else{
                prev = min(intervals[i][1], prev);
            }
        }
        return intervals.size() - cnt;
    }
};