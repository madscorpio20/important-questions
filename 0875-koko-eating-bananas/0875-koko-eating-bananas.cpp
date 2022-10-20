class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = 0;
        for(auto it: piles)
            e = max(it,e);
        int mid;
        int ans;
        while( s<= e)
        {
            mid = (s+e)/2;
            double time = 0;
            for(int i=0; i<piles.size(); i++)
            {
                if(piles[i]%mid == 0)
                {
                    time += piles[i]/mid;
                }
                else
                    time+= (piles[i]/mid) + 1;
            }
            if(time <= h)
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};