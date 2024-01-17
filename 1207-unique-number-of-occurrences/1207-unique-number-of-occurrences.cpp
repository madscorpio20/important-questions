class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto it: arr){
            mp[it]++;   
        }
        map<int,int> cnt;
        for(auto it: mp){
            if(cnt[it.second]  > 0) return false;
            cnt[it.second]++;
        }
        return true;
    }
};