class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long currSmallest1 = nums[0];
        long long currSmallest2;
        bool two = false;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]<currSmallest1)
                currSmallest1 = nums[i];
            else if(two == false && nums[i] > currSmallest1)
            {
                two = true;
                currSmallest2 = nums[i];
            }
            else if(two && nums[i]<currSmallest2 && nums[i] > currSmallest1)
                currSmallest2 = nums[i];
            else if(two && nums[i] > currSmallest2)
                return true;
        }
        return false;
    }
};