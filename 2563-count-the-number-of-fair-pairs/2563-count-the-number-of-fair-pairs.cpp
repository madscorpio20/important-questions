class Solution {
public:
 
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int l = lower - nums[i];
            int u = upper - nums[i];
            int ind1 = lower_bound(nums.begin() + i + 1,nums.end(),l)-nums.begin();
            int ind2 = upper_bound(nums.begin() +  i + 1,nums.end(),u)- nums.begin();
            ans += ind2 - ind1;
        }
        return ans;
    }
};