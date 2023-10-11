class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> mp;
        for(auto it: flowers){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        // vector<vector<int>> dp;
        vector<pair<int,int>> dp;
        int curr = 0;
        for(auto it: mp){
            curr += it.second;
            dp.push_back({it.first, curr});
        }
        vector<int> res;
        for(auto it: people){
            int lo = 0;
            int hi = dp.size() - 1;
            int ans = 0;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(dp[mid].first <= it){
                    ans = dp[mid].second;
                    lo = mid + 1;
                }else{
                    hi = mid -1;
                }
            }
            res.push_back(ans);
        }
        return res;
        
    }
};