class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int duplicate = 0;
            map<double,int> m;
            for(int j=i+1; j<n; j++)
            {
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1])
                {
                    duplicate++;
                    continue;
                }
                if(points[j][0] == points[i][0] )
                {
                    m[INT_MAX]++;
                    continue;
                }
                long double angle = 
                    (long double)(points[j][1] - points[i][1])/
                    (long double)(points[j][0]-points[i][0]);
                m[angle]++;
            }
            int localMax = duplicate+1;
            for(auto it: m)
            {
                localMax = max(localMax,it.second + duplicate+1);
            }
            ans = max(ans,localMax);
        }
        return ans;
    }
};