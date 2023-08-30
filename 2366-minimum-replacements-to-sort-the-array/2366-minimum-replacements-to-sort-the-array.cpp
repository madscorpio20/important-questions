class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans  = 0;
        int n = nums.size();
        int maxi = nums[n-1];
        for(int i=n-2; i>=0;i--){
            if(nums[i] <= maxi){
                maxi = nums[i];
            }
            else
            {
                ans += nums[i]/maxi;
                if(nums[i]%maxi == 0){
                    ans--;
                }
                else
                {
                    maxi = nums[i]/((nums[i]/maxi)+1);
                }
            }
        }
        return ans;
    }
};