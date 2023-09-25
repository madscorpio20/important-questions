class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = nums[0];
        int curr = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(curr == 0){
                curr = 1;
            }
            curr *= nums[i];
            mx1 = max(mx1, curr);
        }
        int mx2 = nums[nums.size()-1];
        curr = nums[nums.size()-1];
        for(int i=nums.size()-2; i>=0; i--){
            if(curr == 0) curr = 1;
            curr *= nums[i];
            mx2 = max(mx2, curr);
        }
        return max(mx1, mx2);
    }
};