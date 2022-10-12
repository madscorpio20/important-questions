class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
//         sum of two side should be greater than third 
        int maxi = 0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1; i>1; i--)
        {
            if(nums[i] < nums[i-1] + nums[i-2])
                return nums[i] + nums[i-1] + nums[i-2];
        }
        return 0;
    }
};