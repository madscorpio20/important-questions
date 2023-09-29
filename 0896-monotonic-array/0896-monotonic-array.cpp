class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <=2 ) return true;
        
        vector<int> v;
        v = nums;
        sort(v.begin(), v.end());
        
        if(v == nums) return true;
        
        reverse(v.begin(),v.end());
        
        if(v == nums) return true;
        return false;
    }
};