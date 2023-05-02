class Solution {
public:
    double average(vector<int>& salary) {
        int maxi = -1e9;
        int mini = 1e9;
        double total = 0;
        for(auto it: salary)
        {
            maxi = max(maxi,it);
            mini = min(mini,it);
            total += it;
        }
        total  = total - (double)maxi - (double)mini;
        double cnt = (double)salary.size() - 2;
        return total /cnt;
    }
};