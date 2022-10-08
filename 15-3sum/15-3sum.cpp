class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            int j = i+1;
            int k = nums.size()-1;
            while(j<k)
            {
                if(nums[j] + nums[k] == -nums[i])
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j+1<nums.size() && nums[j] == nums[j+1])
                        j++;
                    while(k-1>=0 && nums[k] == nums[k-1])
                        k--;
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] < -nums[i])
                    j++;
                else
                    k--;
            }
            while(i+1<nums.size() && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};