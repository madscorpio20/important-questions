class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> m;
        vector<vector<int>> result;
        for(int i=0; i<groupSizes.size(); i++){
            int size = groupSizes[i];
            m[size].push_back(i);
            if(m[size].size() == size ){
                result.push_back(m[size]);
                m[size].clear();
            }
        }
        return result;
    }
};