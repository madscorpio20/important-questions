class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long i=0; 
        long long cnt = 0;
        long long j =0;
        while(i<nums.size())
        {
            if(nums[i]!=0)
            {
                i++;
                continue;
            }
            j = i;
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