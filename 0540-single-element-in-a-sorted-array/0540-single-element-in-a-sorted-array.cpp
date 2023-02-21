class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0; 
        int e = nums.size()-1;
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(mid!=nums.size()-1 && nums[mid] == nums[mid+1])
                mid++;
            else if(mid!=0 && nums[mid] == nums[mid-1])
                mid = mid;
            else
                return nums[mid];
            if((mid+1)%2 !=0)
            {
                e = mid-2;
            }
            else
                s = mid+1;
        }
        return -1;
    }
};