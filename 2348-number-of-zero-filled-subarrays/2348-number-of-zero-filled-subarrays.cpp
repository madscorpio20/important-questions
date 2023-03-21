class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long i=0; 
        long long cnt = 0;
        while(i<nums.size())
        {
            if(nums[i]!=0)
            {
                i++;
                continue;
            }
            long long j = i;
            while(j < nums.size() && nums[j] == 0)
            {
                j++;
            }
            cnt += ((j-i)*(j-i+1))/2;
            i = j;
        }
        return cnt;
    }
};