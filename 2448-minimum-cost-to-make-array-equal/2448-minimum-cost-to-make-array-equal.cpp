class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<long long,long long>> v;
        for(int i=-0; i<n; i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        long long totalSum = 0;
        for(auto it: v)
        {
            totalSum+= it.second;
        }
        long long currSum = 0;
        long long median = 0;
        for(auto it: v)
        {
            currSum += it.second;
            median = it.first;
            if(currSum >= totalSum /2)
                break;
        }
        long long ans =0;
        for(auto it: v)
        {
            ans += abs(it.first - median)*it.second;
        }
        return ans;
    }
};