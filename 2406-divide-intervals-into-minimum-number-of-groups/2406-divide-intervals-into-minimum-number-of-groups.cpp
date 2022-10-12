class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> m;
        for(auto it: intervals)
        {
            m[it[0]]++;
            m[it[1] + 1]--;
        }
        int maxi = 0;
        int curr = 0;
        for(auto it: m)
        {
            curr+=it.second;
            maxi = max(curr,maxi);
        }
        return maxi;
    }
};