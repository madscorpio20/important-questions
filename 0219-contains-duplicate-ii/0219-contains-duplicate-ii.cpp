class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> m;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]].push_back(i);
        }
        for(auto it: m)
        {
            vector<int> temp = it.second;
            for(int i=1; i<temp.size(); i++)
            {
                if(temp[i] - temp[i-1] <=k)
                    return true;
            }
        }
        return false;
    }
    
};