class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 1;
        int e = 1e9;
        int mid;
        int ans = -1;
        while(s<=e)
        {
            mid = (s+e)/2;
            int bouquetCnt = 0;
            int adjacentCnt = 0;
            for(int i = 0; i< bloomDay.size(); i++)
            {
                if(bloomDay[i] <= mid)
                    adjacentCnt++;
                else
                    adjacentCnt = 0;
                if(adjacentCnt == k)
                {
                    bouquetCnt++;
                    adjacentCnt = 0;
                }
            }
            if(bouquetCnt >= m)
            {
                ans = mid;
                e = mid-1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};