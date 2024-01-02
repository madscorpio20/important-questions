class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        vector<vector<int>> res;
        
        int cnt = nums.size();
        while(cnt > 0){
            vector<int> curr;
            for(auto it: mp){
                if(it.second > 0){
                    curr.push_back(it.first);
                    mp[it.first]--;
                    cnt--;
                }
            }
            res.push_back(curr);
        }
        return res;
    }
};