class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int e = 0;
        for(int i=0; i<piles.size(); i++)
        {
            e = max(e,piles[i]);
        }
        int s = 1;
        int ans;
        while(s<=e)
        {
            int mid = (s+e)/2;
            long long cnt = 0;
            for(int i=0; i<piles.size(); i++)
            {
                cnt += piles[i]/mid;
                if(piles[i]%mid != 0)
                    cnt++;
                
            }
            if(cnt <= h)
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