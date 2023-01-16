class Solution {
public:
    static bool cmp(vector<int> first, vector<int> second)
    {
        return first[0] <= second[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> ans;
        for(int i=0; i<intervals.size(); i++)
        {
            vector<int> curr(2);
            curr[0] = intervals[i][0];
            curr[1] = intervals[i][1];
            while(i < intervals.size()-1 && curr[1] >= intervals[i+1][0])
            {
                curr[1] = max(curr[1],intervals[i+1][1]);
                i++;
            }
            curr[1] = max(curr[1],intervals[i][1]);
            cout<<curr[0]<<" "<<curr[1]<<endl;
            ans.push_back(curr);
        }
        return ans;
    }
};