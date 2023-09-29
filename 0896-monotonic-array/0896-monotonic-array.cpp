class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <=2 ) return true;
        int ind = 1;
        while(ind < nums.size() && nums[ind] == nums[ind-1]) ind++;
        
        if(ind == nums.size()) return true;
        int pos = nums[ind] - nums[ind-1];
        
        while(ind < nums.size()){
            if(pos > 0){
                if(nums[ind] - nums[ind-1] < 0) return false;
            }else{
                if(nums[ind] - nums[ind-1] > 0) return false;
            }
            ind++;
        }
        
        return true;
        
    }
};