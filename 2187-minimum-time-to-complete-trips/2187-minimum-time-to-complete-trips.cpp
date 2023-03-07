class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        long long s = 1;
        totalTrips = (long long) totalTrips;
        long long k = time[0];
        long long e = k*totalTrips;
        long long ans = e;
        while(s<=e)
        {
            long long mid = (s+e)/2;
            long long cnt = 0;
            
            for(int i=0; i<time.size(); i++)
            {
                cnt+= mid/time[i];
            }
            if(cnt >= totalTrips)
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