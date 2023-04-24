class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        while(stones.size() > 1)
        {
            int n = stones.size();
            int curr = stones[n-1] - stones[n-2];
            stones.pop_back();
            stones.pop_back();
            stones.push_back(curr);
            sort(stones.begin(),stones.end());
        }
        return stones[0];
    }
};