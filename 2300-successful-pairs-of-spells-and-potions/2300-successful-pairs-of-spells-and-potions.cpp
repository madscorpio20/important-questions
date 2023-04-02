class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = potions.size();
        vector<long long> spells2;
        for(auto it: spells)
        {
            spells2.push_back((long long) it);
        }
        vector<long long> potions2;
        for(auto it: potions)
        {
            potions2.push_back((long long) it);
        }
        vector<int> ans;
        for(int i=0; i<spells2.size(); i++)
        {
            int s = 0;
            int e = n-1;
            int ind = n;
            while(s<=e)
            {
                int mid = (s+e)/2;
                
                if(spells2[i]*potions2[mid] >= success)
                {
                    ind = mid;
                    e = mid-1;
                }
                else
                    s = mid+1;
            }
            ans.push_back(n - ind);
        }
        return ans;
    }
};