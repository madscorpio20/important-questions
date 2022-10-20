class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 1;
        int e = 1e9;
        int mid;
        int ans;
        while(s<=e)
        {
            mid = (s+e)/2;
            int currDays = 1;
            int capacity = 0;
            for(auto it: weights)
            {
                if(it > mid)
                {
                    currDays = 1e9;
                    break;
                }
                capacity+= it;
                if(capacity > mid)
                {
                    currDays++;
                    capacity = it;
                }
            }
            
            if(currDays <=days)
            {
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
};