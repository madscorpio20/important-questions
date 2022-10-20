class Solution {
public:
    void find(vector<int> &nums, vector<vector<int>> &ans, int ind,vector<int> &curr)
    {
        if(ind == nums.size())
        {
            ans.push_back(curr);
            return;
        }
        find(nums,ans,ind+1,curr);
        curr.push_back(nums[ind]);
        find(nums,ans,ind+1,curr);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        find(nums,ans,0,curr);
        return ans;
    }
};