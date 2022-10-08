class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int j,k,currTarget;
        int ans = 1e9;
        for(int i=0; i<n; i++)
        {
            currTarget = target - nums[i];
            j = i+1;
            k = n-1;
            while(j<k)
            {
               if(nums[j] + nums[k] == currTarget)
                   return target;
                else if(nums[j] + nums[k] < currTarget)
                {
                    if(abs(target - ans) > abs(target - (nums[i]+nums[j]+ nums[k])))
                        ans = nums[i] + nums[j] + nums[k];
                    j++;
                }
                else
                {
                    if(abs(target - ans) > abs(target - (nums[i]+nums[j]+ nums[k])))
                        ans = nums[i] + nums[j] + nums[k];
                    k--;
                }
            }
        }
        return ans;
    }
};