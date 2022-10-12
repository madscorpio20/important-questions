class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                int s = j+1;
                int e = nums.size()-1;
                while(s<e)
                {
                    double sum = 
                        (double)nums[i] + 
                        (double)nums[j] + 
                        ( double)nums[s] +
                        ( double)nums[e];
                    // cout<<sum<<endl;
                    if(sum < target)
                        s++;
                    else if(sum > target)
                        e--;
                    else
                    {
                        while(s<e && nums[s] == nums[s+1])
                        {
                            s++;
                        }
                        while(s<e && nums[e] == nums[e-1])
                        {
                            e--;
                        }
                        ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                        s++;
                        e--;
                    }
                }
                while(j+1<nums.size() && nums[j] == nums[j+1])
                    j++;
            }
            while(i+1<nums.size() && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};