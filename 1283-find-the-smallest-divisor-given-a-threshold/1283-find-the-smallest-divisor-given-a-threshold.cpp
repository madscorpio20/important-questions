class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = 1e9;
        int mid;
        int sum;
        int ans;
        while(s<=e)
        {
            mid = (s+e)/2;
            sum = 0;
            for(auto it:nums)
            {
                if(it%mid == 0)
                    sum += it/mid;
                else
                    sum += (it/mid)+1;
            }
            if(sum <= threshold)
            {
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
};