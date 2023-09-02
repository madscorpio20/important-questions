class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        if(nums.size() < k)
            return 0;
        long long  nonUnique = 0;
        long long currSum = 0;
        long long maxSum = 0;
        map<int,int> mp;
        for(int i=0; i<k; i++){
            if(mp[nums[i]]){
                nonUnique++;
            }
            mp[nums[i]]++;
            currSum += nums[i];
        }
        if(nonUnique <= k-m){
            maxSum = max(maxSum, currSum);
        }
        for(int i=k; i<nums.size(); i++){
            currSum -= nums[i-k];
            if(mp[nums[i-k]] >1){
                nonUnique--;
            }
            mp[nums[i-k]]--;
            
            if(mp[nums[i]]){
                nonUnique++;
            }
            mp[nums[i]]++;
            currSum += nums[i];
            
            if(nonUnique <= k-m){
            maxSum = max(maxSum, currSum);
            }
            
        }
        return maxSum;
    }
};