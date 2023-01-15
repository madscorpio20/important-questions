class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = 1e9;
        for(auto it: prices)
        {
            buy = min(buy,it);
            if(it > buy)
            {
                profit += it-buy;
                buy = it;
            }
        }
        return profit;
    }
};