class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int u = upper_bound(nums.begin(),nums.end(), target) - nums.begin();
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        vector<int> res;
        if(l >= nums.size() || nums[l]!= target){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(l);
        res.push_back(u-1);
        return res;
    }
};