class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int cnt = 0;
//         prefixSum[i-1]%mod
        map<int,int> preSum;
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            preSum[cnt%modulo]++;
            if(nums[i]%modulo == k)
                cnt++;
            ans += preSum[(cnt-k)%modulo];
        }
        return ans;
    }
};