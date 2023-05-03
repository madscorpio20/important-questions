class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m1;
        map<int,int> m2;
        vector<int> v1;
        vector<int> v2;
        vector<vector<int>> ans;
        for(auto it: nums1)
            m1[it]++;
        for(auto it: nums2)
            m2[it]++;
        for(auto it: m1)
        {
            if(!m2[it.first])
                v1.push_back(it.first);
        }
        for(auto it: m2)
        {
            if(!m1[it.first])
                v2.push_back(it.first);
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};