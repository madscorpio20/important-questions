class Solution {
public:
    static bool cmp(pair<string,int> p1, pair<string,int> p2)
    {
        if(p1.second == p2.second)
        {
            if( lexicographical_compare(p1.first.begin() , p1.first.end(), p2.first.begin() ,   p2.first.end() ))
            {
                return true;

            }
            else
            {
                return false;

            }
        }
        return p1.second > p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto it: words)
            m[it]++;
        vector<pair<string,int>> v;
        for(auto it: m)
            v.push_back({it.first,it.second});
        sort(v.begin(),v.end(),cmp);
        vector<string> ans;
        int i=0;
        while(k > 0)
        {
            ans.push_back(v[i].first);
            i++;
            k--;
        }
        return ans;
    }
};