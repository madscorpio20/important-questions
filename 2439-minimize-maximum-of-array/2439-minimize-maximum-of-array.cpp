class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int low = nums[0];
        int hi = nums[0];
        for(auto it: nums)
            hi = max(hi,it);
        int maxVal = hi;
        while(low <= hi)
        {
            int mid = (low+hi)/2;
            bool check = true;
            double buffer = mid - nums[0];
            for(int i=1; i<nums.size(); i++)
            {
                if(nums[i] > mid )
                {
                    buffer = mid - (nums[i] - buffer);
                    if(buffer < 0)
                    {
                        check = false;
                        break;
                    }
                }
                else
                {
                    buffer = buffer + mid - nums[i];
                }
            }
            if(check == true)
            {
                maxVal = mid;
                hi = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return maxVal;
    }
};