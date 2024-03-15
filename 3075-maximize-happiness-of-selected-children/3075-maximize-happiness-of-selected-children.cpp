class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(), happiness.end());
        reverse(happiness.begin(), happiness.end());
        long long counter = 0;
        for(int i=0; i<k; i++){
            ans += (long long)happiness[i] - counter > 0 ? (long long)happiness[i] - counter: 0;
            counter++;
        }
        return ans;
    }
};