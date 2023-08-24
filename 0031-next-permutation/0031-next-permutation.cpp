class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[n-1];
        for(int i = n-2; i>=0; i--){
            if(nums[i] > maxi){
                maxi = nums[i];
                continue;
            }
            else{
                
                for(int j = n-1; j>i; j--){
                    if(nums[j] > nums[i]){
                        swap(nums[i],nums[j]);
                        reverse(nums.begin() + i+1, nums.end());
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(),nums.end());
    }
};