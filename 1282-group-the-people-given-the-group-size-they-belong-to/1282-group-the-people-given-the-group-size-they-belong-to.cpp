class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>> v;
        for(int i=0; i<groupSizes.size(); i++){
            v.push_back({groupSizes[i],i});
        }
        sort(v.begin(),v.end());
        
        int ind = 0;
        vector<vector<int>> ans;
        while(ind <v.size()){
            vector<int> curr;
            int capacity = v[ind].first;
            while(curr.size() < capacity){
                curr.push_back(v[ind].second);
                ind++;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};