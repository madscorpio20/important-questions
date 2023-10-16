class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        if(indexDifference == 0){
            if(valueDifference == 0){
                vector<int> res;
                res.push_back(0);
                res.push_back(0);
                return res;
            }
        }
        vector<pair<int,int>> prefix;
        int mini = 1e9 + 1;
        int maxi = -1;
        for(int i=0; i<nums.size(); i++){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
            prefix.push_back({mini, maxi});
            if(i - indexDifference >= 0){
                if(abs(prefix[i-indexDifference].first - nums[i]) >= valueDifference || 
                   abs(prefix[i-indexDifference].second - nums[i]) >= valueDifference){
                    vector<int> res;
                    for(int j=0; j<= i - indexDifference; j++){
                        if(abs(nums[i] - nums[j]) >= valueDifference){
                            res.push_back(j);
                            res.push_back(i);
                            return res;
                        }
                    }
                }
                
            }
            
        }
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        return res;
        
    }
};