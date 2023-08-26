class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];
        while(slow!= fast){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }
        fast = nums[0];
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
    }
};