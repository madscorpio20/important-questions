class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>> v;
        
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                double d = (double)arr[i]/(double)arr[j];
                v.push_back({d,{arr[i],arr[j]}});
            }
        }
        sort(v.begin(),v.end());
        vector<int> res;
        res.push_back(v[k-1].second.first);
        res.push_back(v[k-1].second.second);
        return res;
    }
};